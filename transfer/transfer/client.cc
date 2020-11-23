#include "transfer.h"


// HOST_1=10.46.182.82
// HOST_2=10.46.235.16
// HOST_3=10.46.219.70
// HOST_4=10.46.219.70

WEB site_info[4] = {{"10.46.182.82","50051","2379","3306"},
                    {"10.46.235.16","50051","2379","3306"},
                    {"10.46.219.70","50051","2379","3306"},
                    {"10.46.219.70","50052","22379","33306"}
                };

string TransferClient::local_I_D(string sql, int site){
    Stmt1 stmt;
    stmt.set_sql(sql);
    stmt.set_site(site);

    Reply re;

    ClientContext context;

    Status status = stub_->L_I_D(&context, stmt, &re);
    if (status.ok()) {
      return re.done();
    } else {
      cout << status.error_code() << ": " << status.error_message() << endl;
      return re.done();
    }
}
string TransferClient::local_L(string sql1,string sql2, int site){
    Stmt2 stmt;
    stmt.set_sql1(sql1);
    stmt.set_sql2(sql2);
    stmt.set_site(site);

    Reply re;

    ClientContext context;

    Status status = stub_->L_L(&context, stmt, &re);
    if (status.ok()) {
      return re.done();
    } else {
      cout << status.error_code() << ": " << status.error_message() << endl;
      return re.done();
    }

}
string RPC_local_Insert_Delete(string sql, string site){
    char *p = (char*)site.c_str();
    int st = atoi(p);
    TransferClient t1(grpc::CreateChannel(site_info[st-1].IP+":"+site_info[st-1].RPC_PORT, grpc::InsecureChannelCredentials()));
    string res = t1.local_I_D(sql,st);
    return res;
}
string RPC_local_Load(string sql_create, string sql_load, string site){
    char *p = (char*)site.c_str();
    int st = atoi(p);
    TransferClient t1(grpc::CreateChannel(site_info[st-1].IP+":"+site_info[st-1].RPC_PORT, grpc::InsecureChannelCredentials()));
    string res = t1.local_L(sql_create,sql_load,st);
    return res;

}

int main(){
    string res = RPC_local_Insert_Delete("insert into book values(200001,'Book #200001','H. Johnston',100366,7231)","3");
    cout << res << endl;
    return 0;
}