#ifndef _TRANSFER_H_
#define _TRANSFER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>
#include <grpcpp/grpcpp.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include "pro/transfer.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientWriter;
using grpc::Status;
using transfer::Stmt1;
using transfer::Stmt2;
using transfer::Reply;
using transfer::Transfer;

using namespace std;

// bool Transfer(int site,string data);
class TransferClient
{
public:
    TransferClient(std::shared_ptr<Channel> channel) : stub_(Transfer::NewStub(channel)){};
    string local_I_D(string sql, int site);
    string local_L(string sql1, string sql2, int site);
private:
    std::unique_ptr<Transfer::Stub> stub_;
};

typedef struct webInfo{
    string IP;
    string RPC_PORT;
    string ETCD_PORT;
    string MYSQL_PORT;
}WEB;

extern WEB site_info[4];

string RPC_local_Insert_Delete(string sql, string site);
string RPC_local_Load(string sql_create, string sql_load, string site);



#endif /*_TRANSFER_H_*/