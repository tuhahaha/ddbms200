#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>
#include "pro/transfer.grpc.pb.h"
#include "../../executor/cpp/mysql_connector.h"
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::Status;
using transfer::Stmt1;
using transfer::Stmt2;
using transfer::Reply;
using transfer::Transfer;

using namespace std;


class TransferImpl final : public Transfer::Service {
public:
    Status L_I_D(ServerContext* context, const Stmt1* stmt,Reply* re);
    Status L_L(ServerContext* context, const Stmt2* stmt,Reply* re);
    
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