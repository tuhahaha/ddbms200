#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>
#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include "transfer_file.grpc.pb.h"
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientWriter;
using grpc::Status;
using transferfile::Chunk;
using transferfile::Reply;
using transferfile::TransferFile;
#define CHUNK_SIZE 1024 * 1024
class TransferFileClient
{
public:
    TransferFileClient(std::shared_ptr<Channel> channel) : stub_(TransferFile::NewStub(channel)){};
    void Upload();private:
    std::unique_ptr<TransferFile::Stub> stub_;
};

void TransferFileClient::Upload()
{
    Chunk chunk;
    char data[CHUNK_SIZE];
    Reply stats;
    ClientContext context;
    const char *filename = "book.tsv";
    std::ifstream infile;
    int len = 0;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    infile.open(filename, std::ifstream::in | std::ifstream::binary);
    std::unique_ptr<ClientWriter<Chunk>> writer(stub_->Upload(&context, &stats));
    while (!infile.eof()) {
      infile.read(data, CHUNK_SIZE);
      chunk.set_buffer(data, infile.gcount());
      if (!writer->Write(chunk)) {
        // Broken stream.
        break;
      }
      len += infile.gcount();
    }
    writer->WritesDone();
    Status status = writer->Finish();
    if (status.ok()) {
        gettimeofday(&end, NULL);
        std::cout <<  (end.tv_sec-start.tv_sec)+ (double)(end.tv_usec-start.tv_usec)/1000000 << std::endl;
    } else {
      std::cout << "TransferFile rpc failed." << std::endl;
    }
}
int main(int argc, char** argv){
  TransferFileClient guide(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
  guide.Upload();
  return 0;
}