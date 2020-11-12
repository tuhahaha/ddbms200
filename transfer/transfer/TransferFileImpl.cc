#include <iostream>
#include <fstream>
#include <string>
#include <grpc/grpc.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>
#include "transfer_file.grpc.pb.h"
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::Status;
using transferfile::Chunk;
using transferfile::Reply;
using transferfile::TransferFile;
#define CHUNK_SIZE 1024 * 1024

class TransferFileImpl final : public TransferFile::Service {
public:
    Status Upload(ServerContext* context, ServerReader<Chunk>* reader, Reply* reply);
};

Status TransferFileImpl::Upload(ServerContext* context, ServerReader<Chunk>* reader, Reply* reply) {
    Chunk chunk;
    const char *filename = "book_tmp.tsv";
    std::ofstream outfile;
    const char *data;
    outfile.open(filename, std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
    while (reader->Read(&chunk)) {
        data = chunk.buffer().c_str();
        outfile.write(data, chunk.buffer().length());
    }
    long pos = outfile.tellp();
    reply->set_length(pos);
    outfile.close();
    return Status::OK;
}

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  TransferFileImpl service;
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}