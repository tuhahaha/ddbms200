#include "metadata.h"

#define URL_MAX_LEN 50  
#define VALUE_LEN 1024

vector<string> split2list(string info){
    stringstream sstr(info);
    string token;
    vector<string> res;
    while(getline(sstr,token,",")){
        res.push_back(token);
    }
    return res;
}

vector<string> getTables(){
    //返回创建的所有表格
    string dir = "/gdd_table";
    string info  = Search_Value(dir);
    vector<string> res = split2list(info);
    return res;
}
vector<string> getTableAttri(string: tableName) {
    //返回表的attri
    string dir = "/gdd_table/"+tableName;
    string info  = Search_Value(dir);
    vector<string> res = split2list(info);
    return res;
}
string getTableAttriType(string: tableName, string: attriName){
    string dir = "/gdd_table/"+tableName+"/"+attriName;
    string info  = Search_Value(dir);
    return info;
}
string getTableAttriDesc(string: tableName, string:attriName){
    string dir = "/gdd_table/"+tableName+"/desc/"+attriName;
    string info  = Search_Value(dir);
    return info;
}
string getTableKey(string: tableName){
    string dir = "/gdd_key/"+tableName;
    string info  = Search_Value(dir);
    return info;
}
string getTableFragType(string: tableName){
    string dir = "/part_schema/"+tableName;
    string info  = Search_Value(dir);
    return info;
}
vector<string> getTableFragH(string: tableName){
    string dir = "/part_schema/"+tableName+"/H";
    string info  = Search_Value(dir);
    vector<string> res = split2list(info);
    return res;
}
int getTableFragNum(string: tableName){
    string dir = "/part_info/"+tableName;
    string info  = Search_Value(dir);
    char *p = (char*)info.c_str();
    return atoi(p);
}
string getTableFragCondition(string: tableName, int index){
    string dir = "/part_info/"+tableName+"/"+tableName+".";
    dir.append(itoa(index));
    cout << dir << endl;
    string info  = Search_Value(dir);
    return info;
}
string getTableFragCol(string: tableName, int index){
    string dir = "/part_column/"+tableName+"/"+tableName+".";
    dir.append(itoa(index));
    cout << dir << endl;
    string info  = Search_Value(dir);
    return info;
}

int getTableFragSize(string: tableName,int index){
    string dir = "/part_size/"+tableName+".";
    dir.append(itoa(index));
    cout << dir << endl;
    string info  = Search_Value(dir);
    char *p = (char*)info.c_str();
    return atoi(p);
}
int getTableFragSite(string: tableName,int index){
    string dir = "/part_site/"+tableName+".";
    dir.append(itoa(index));
    cout << dir << endl;
    string info  = Search_Value(dir);
    char *p = (char*)info.c_str();
    return atoi(p);
}

bool saveTableToEtcd(GDD table){
    // save table
    string k = "/gdd_table/"+GDD.name;
    string v = "";
    for (int i=0; i<table.cols.size(); i++){
        v += table.cols[i].name
        v += ","
    }
    v.pop_back();
    Insert_Attrvalue(k,v);

    for (int i=0; i<table.cols.size(); i++){
        ColumnDef col = table.cols[i];
        string k1 = k + "/" + col.name;
        string v1 = col.type;
        Insert_Attrvalue(k1,v1);

        string k2 = k + "/desc/" + col.name;
        string v1 = col.desc;
        Insert_Attrvalue(k2,v2);

        if(col.key == true){
            string k3 = "/gdd_key/"+GDD.name;
            string v3 = col.name;
            Insert_Attrvalue(k3,v3);
        }
    }
    return true;
}

bool saveFragToEtcd(Fragment frag){
    // save frag info
    string k = "/part_schema/"+frag.name;
    string v = frag.fragtype;
    Insert_Attrvalue(k,v);

    k = "/part_info/"+frag.name;
    v = atoi(frag.fragnum);
    Insert_Attrvalue(k,v);

    for (int i=0; i < frag.fragnum; i++){
        FragDef fr = frag.frags[i];
        string k1 = k+"/"+frag.name+"."+itoa(fr.id);
        string v1 = fr.condition;
        Insert_Attrvalue(k1,v1);

        k1 = "/part_site/"+frag.name+"."+itoa(fr.id);
        v1 = itoa(fr.site);
        Insert_Attrvalue(k1,v1);

        k1 = "/part_size/"+frag.name+"."+itoa(fr.id);
        v1 = itoa(fr.size);
        Insert_Attrvalue(k1,v1);

        k1 = "/part_column"+frag.name+"."+itoa(fr.id);
        v1 = fr.column;
        Insert_Attrvalue(k1,v1);
    }
    return true;
}

string Search_Value(string &dir) //将全部数据合并返回
{
    string etcd_url = "http://127.0.0.1/v2/keys/"+dir+"?recursive=true";
        char *ss=(char*)etcd_url.c_str();
     CURLcode return_code;  
    return_code = curl_global_init(CURL_GLOBAL_SSL);  
    if (CURLE_OK != return_code)  
    {  
        cerr << "init libcurl failed." << endl;  
        return "";  
    }  
    // 获取easy handle  
    CURL *easy_handle = curl_easy_init();  
    if (NULL == easy_handle)  
    {  
        cerr << "get a easy handle failed." << endl;  
        curl_global_cleanup();   
  
        return "";  
    }  
    char * buff_p = NULL;  
    char result[5000] = "";
    // 设置easy handle属性  
    curl_easy_setopt(easy_handle, CURLOPT_URL,ss);  
    curl_easy_setopt(easy_handle, CURLOPT_PORT, 2379);  
    curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, &write_data);  
    curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &result);  
  
    // 执行数据请求  
    curl_easy_perform(easy_handle);   
  
    // 释放资源  
    curl_easy_cleanup(easy_handle);  
    curl_global_cleanup();  
    string info = result;
    return info;
}
int etcd_set(char *key, char *value, char *token)  
{  //向etcd创建dir数据
    CURLcode return_code;  
    char etcd_url[URL_MAX_LEN];  
    char etcd_value[VALUE_LEN];   

        return_code = curl_global_init(CURL_GLOBAL_SSL);  
    if (CURLE_OK != return_code)  
    {  
        //cerr << "init libcurl failed." << endl;  
        printf("init libcurl failed\n");  
        return -1;  
    }  
  
    sprintf(etcd_url, "http://127.0.0.1:2379/v2/keys%s", key);  
    sprintf(etcd_value, "dir=%s", value);  
    // 获取easy handle  
    CURL *easy_handle = curl_easy_init();  
    if (NULL == easy_handle)  
    {  
        //cerr << "get a easy handle failed." << endl;  
        printf("get a easy handle failed.\n");  
        curl_global_cleanup();   
        return -1;  
    }  
    // 设置easy handle属性  
    curl_easy_setopt(easy_handle, CURLOPT_URL, etcd_url);   
    curl_easy_setopt(easy_handle, CURLOPT_POST, 1);  
    curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDS, etcd_value);  
    curl_easy_setopt(easy_handle, CURLOPT_CUSTOMREQUEST, "PUT");  
   
    // 执行数据请求  
    curl_easy_perform(easy_handle);   
  
    // 释放资源  
    curl_easy_cleanup(easy_handle);  
    curl_global_cleanup();  
    return 0;  
} 
int etcd_set2(char *key, char *value, char *token)  
//向etcd存储value数据
{    
   
    CURLcode return_code;   
    char etcd_value[VALUE_LEN];   
      
    return_code = curl_global_init(CURL_GLOBAL_SSL);  
    if (CURLE_OK != return_code)  
    {  
        //cerr << "init libcurl failed." << endl;  
        printf("init libcurl failed\n");  
        return -1;  
    }  
    string a = key;
    string str = "http://127.0.0.1:2379/v2/keys"+a;
    char *ss=(char*)str.c_str();
    sprintf(etcd_value, "value=%s", value);  
    // 获取easy handle  
    CURL *easy_handle = curl_easy_init();  
    if (NULL == easy_handle)  
    {  
        //cerr << "get a easy handle failed." << endl;  
        printf("get a easy handle failed.\n");  
        curl_global_cleanup();   
        return -1;  
    }  
    // 设置easy handle属性  
    curl_easy_setopt(easy_handle, CURLOPT_URL, ss);   
    curl_easy_setopt(easy_handle, CURLOPT_POST, 1);  
    curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDS, etcd_value);  
    curl_easy_setopt(easy_handle, CURLOPT_CUSTOMREQUEST, "PUT");  
   
    // 执行数据请求  
    curl_easy_perform(easy_handle);   
  
    // 释放资源  
    curl_easy_cleanup(easy_handle);  
    curl_global_cleanup();  
    return 0;  
}  
string Create_Dir(string &etcd_url,string &etcd_dir)
{ //在etcd里面创建dir
    string str=etcd_url+"/"+etcd_dir;
    cout<<str<<endl;
    char *p=(char*)str.c_str();
    etcd_set(p, "true", NULL);  
    return str; 
}
bool Insert_Attrvalue(string &dir,string &value)
{  //调用存储数据的etcd接口  
    string str=dir;
    char *p=(char*)str.c_str();
    char *data=(char*)value.c_str();
    etcd_set2(p, data, NULL);  
    return true; 
      
}






