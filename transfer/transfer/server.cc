#include <iostream>
#include <memory>
#include <sys/time.h>
#include <string>
#include <fstream>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>
#include "transfer.grpc.pb.h"
#include "../../executor/cpp/mysql_connector.h"
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::Status;
using transfer::Stmt1;
using transfer::Stmt2;
using transfer::Chunk;
using transfer::Reply;
using transfer::Transfer;

using namespace std;
#define CHUNK_SIZE 1024 * 1024

class TransferImpl final : public Transfer::Service {
public:
    Status L_I_D(ServerContext* context, const Stmt1* stmt,Reply* re);
    Status L_L(ServerContext* context, const Stmt2* stmt,Reply* re);
    Status L_S(ServerContext* context, const Stmt2* stmt,ServerWriter<Chunk>* writer);
    Status L_T_L(ServerContext* context, ServerReader<Chunk>* reader, Reply* re);
    
};

Status TransferImpl::L_I_D(ServerContext* context, const Stmt1* stmt,Reply* re){
    string sql = stmt->sql();
    int site = stmt->site();
    string res = local_Insert_Delete(sql, to_string(site)); // 此处调用函数
    re->set_done(res);
    return Status::OK;
}
Status TransferImpl::L_L(ServerContext* context, const Stmt2* stmt,Reply* re){
    string sql1 = stmt->sql1();
    string sql2 = stmt->sql2();
    int site = stmt->site();
    string res = local_Load(sql1,sql2, to_string(site)); // 此处调用函数
    re->set_done(res);
    return Status::OK;
}

Status TransferImpl::L_S(ServerContext* context, const Stmt2* stmt,ServerWriter<Chunk>* writer){
    string sql = stmt->sql1();
    string file_name = stmt->sql2();
    int site = stmt->site();
    // string res = Local_Select(sql,file_name, to_string(site)); // 此处生成文件TMPPATH+file_name+".sql"
    
    // 将新生成的文件传回client端
    Chunk chunk;
    char data[CHUNK_SIZE];
    string fl = TMPPATH + file_name+".sql";
    const char *filename = fl.c_str();
    ifstream infile;
    int len = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    infile.open(filename, ifstream::in | ifstream::binary);

    while (!infile.eof()) {
      infile.read(data, CHUNK_SIZE);
      chunk.set_buffer(data, infile.gcount());
      if (!writer->Write(chunk)) {
        // Broken stream.
        break;
      }
      len += infile.gcount();
    }
    cout <<  (end.tv_sec-start.tv_sec)+ (double)(end.tv_usec-start.tv_usec)/1000000 << endl;
    return Status::OK;
}
Status TransferImpl::L_T_L(ServerContext* context, ServerReader<Chunk>* reader, Reply* re){
    Chunk chunk;
    const char *filename = "test111.sql"; //此处filename该怎么定？
    ofstream outfile;
    const char *data;
    outfile.open(filename, ofstream::out | ofstream::trunc | ofstream::binary);
    while (reader->Read(&chunk)) {
        data = chunk.buffer().c_str();
        outfile.write(data, chunk.buffer().length());
    }
    long pos = outfile.tellp();
    cout << "length: " << pos << endl;
    re->set_done("OK");
    outfile.close();

    // 文件传过去以后，调用本地函数
    // Local_Tmp_Load(filename,to_string(site));

    return Status::OK;
}

void RunServer() {
  string server_address("0.0.0.0:50051");
  TransferImpl service;
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  unique_ptr<Server> server(builder.BuildAndStart());
  cout << "Server listening on " << server_address << endl;
  server->Wait();
}
int main(){
    RunServer();
    return 0;
}