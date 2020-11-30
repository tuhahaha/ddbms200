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
string TransferClient::local_S(string sql,string file_name, int site){
    Stmt2 stmt;
    stmt.set_sql1(sql);
    stmt.set_sql2(file_name);
    stmt.set_site(site);
    // 开始接收返回，并写入文件
    ClientContext context;
    Chunk chunk;
    string fl = TMPPATH + file_name+".sql";
    const char *filename = fl.c_str();
    ofstream outfile;
    const char *data;
    outfile.open(filename, ofstream::out | ofstream::trunc | ofstream::binary);
    std::unique_ptr<ClientReader<Chunk> > reader(
        stub_->L_S(&context, stmt));
    while (reader->Read(&chunk)) {
        data = chunk.buffer().c_str();
        outfile.write(data, chunk.buffer().length());
    }
    long pos = outfile.tellp();
    cout << "length:    " << pos << endl;
    outfile.close();

    Status status = reader->Finish();
    
    if (status.ok()) {
      return file_name;
    } else {
      cout << status.error_code() << ": " << status.error_message() << endl;
      return "";
    }
}
string TransferClient::local_T_L(string tmp_data, int site){
    TMPFile fi;
    Stmt1 st;
    st.set_sql(tmp_data);
    st.set_site(site);
    fi.mutable_cfg()->CopyFrom(st);

    //读取文件，传输给server    
    string fl = TMPPATH + tmp_data +".sql";
    const char *filename = fl.c_str();

    Chunk chunk;
    char data[CHUNK_SIZE];
    Reply re;
    ClientContext context;

    ifstream infile;
    int len = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    infile.open(filename, ifstream::in | ifstream::binary);
    std::unique_ptr<ClientWriter<TMPFile>> writer(stub_->L_T_L(&context, &re));
    while (!infile.eof()) {
      infile.read(data, CHUNK_SIZE);
      chunk.set_buffer(data, infile.gcount());
      fi.mutable_chk()->CopyFrom(chunk);
      if (!writer->Write(fi)) {
        // Broken stream.
        break;
      }
      len += infile.gcount();
    }
    gettimeofday(&end, NULL);
    cout <<  (end.tv_sec-start.tv_sec)+ (double)(end.tv_usec-start.tv_usec)/1000000 << endl;
    return re.done();
}


// RPC_  是executor调用的接口定义
string RPC_local_Insert_Delete(string sql, string site){
    site = site[1];
    char *p = (char*)site.c_str();
    int st = atoi(p);
    TransferClient t1(grpc::CreateChannel(site_info[st-1].IP+":"+site_info[st-1].RPC_PORT, grpc::InsecureChannelCredentials()));
    string res = t1.local_I_D(sql,st);
    return res;
}
string RPC_local_Load(string sql_create, string sql_load, string site){
    site = site[1];
    char *p = (char*)site.c_str();
    int st = atoi(p);
    TransferClient t1(grpc::CreateChannel(site_info[st-1].IP+":"+site_info[st-1].RPC_PORT, grpc::InsecureChannelCredentials()));
    string res = t1.local_L(sql_create,sql_load,st);
    return res;

}
string RPC_Local_Select(string sql, string res_name, string site){
    site = site[1];
    char *p = (char*)site.c_str();
    int st = atoi(p);
    TransferClient t1(grpc::CreateChannel(site_info[st-1].IP+":"+site_info[st-1].RPC_PORT, grpc::InsecureChannelCredentials()));
    string res = t1.local_S(sql,res_name,st);
    return res_name;
}
string RPC_Local_Tmp_Load(string tmp_data, string site){
    site = site[1];
    char *p = (char*)site.c_str();
    int st = atoi(p);
    TransferClient t1(grpc::CreateChannel(site_info[st-1].IP+":"+site_info[st-1].RPC_PORT, grpc::InsecureChannelCredentials()));
    string res = t1.local_T_L(tmp_data,st);
    return res;
}

// int main(){
//     string res = RPC_local_Insert_Delete("insert into book values(200002,'Book #200001','H. Johnston',100366,7231)","s3");
//     // string res = RPC_Local_Select("","test","3");
//     // string res = RPC_Local_Tmp_Load("test","3");
//     cout << res << endl;
//     return 0;
// }