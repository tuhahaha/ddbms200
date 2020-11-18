//metadata managemant
#ifndef _DDB_METADATA_H_
#define _DDB_METADATA_H_
// #include <curl/curl.h> 
// #include <json/json.h> 
#include <iostream>  
#include <string>
#include <map> 
#include <regex>
#include <vector>
#include <sstream>
// #include <cstdlib>
// #include <cstdio>
#include <typeinfo>
// #define MAX_FRAG_COUNT1 100
// #define MAX_FRAG_V 10
// #define MAX_FRAG_H 10


using namespace std;
// using namespace Json;

// column
struct ColumnDef {
	string name;
	string type;
	bool null=false;
	bool key=false;
	string desc;
};
// table 
struct GDD {
	string name;
	vector<ColumnDef> cols;
};
// fragment
struct FragDef {
	int id;
    int site;
    string column; //该分片涉及到的column，如果是多个，则用逗号分隔
	string condition; //分片条件
    int size; //记录该分片的大小，以byte为单位
};
// table-fragment
struct Fragment {
	string name;
	string fragtype; // H/V 
	int fragnum;
	vector<FragDef> frags;
};

class ZBase64{
private:
    //Base64编码解码表
    char* m_Base64_Table;
public:
    //构造
    ZBase64();
    //编码
    string EncodeBase64(const string strSource);
    //解码
    string DecodeBase64(const string strSource);
};
vector<string> split2list(string info);
vector<string> getTables();
vector<string> getTableAttri(string tableName);
string getTableAttriType(string tableName, string attriName);
string getTableAttriDesc(string tableName, string attriName);
string getTableKey(string tableName);
string getTableFragType(string tableName);
vector<string> getTableFragH(string tableName);
int getTableFragNum(string tableName);
string getTableFragCondition(string tableName, int index);
string getTableFragCol(string tableName, int index);
int getTableFragSize(string tableName,int index);
int getTableFragSite(string tableName,int index);
bool saveTableToEtcd(GDD table);
GDD getTableFromEtcd(string tablename);
bool saveFragToEtcd(Fragment frag);
Fragment getFragFromEtcd(string tablename);
string get_value_from_json(string &res);
string toJson(string k);
bool Insert_Attrvalue(string &key,string &value);
string etcd_op(string &dt,string &op);
size_t write_data(void *buffer, size_t size, size_t nmemb, void *stream);


// int etcd_set(char *key, char *value, char *token);
// int etcd_set2(char *key, char *value, char *token);
// string  Create_Dir(string &etcd_url,string &etcd_dir);  

// bool Save_Table(Table TableInfo);
// bool Save_Fragment(Fragment table);
// Fragment To_json(string &info,string &tablename);
// Fragment Get_Fragment(string &tablename);
// Table To_Table(string &info,string &tablename);
// Table Get_Table(string &tablename);
// Fragment1 Change_Frag(Fragment f1);
// Fragment1 Get_Fragment1(string &tablename);
// void Get_TableAttrs(string &tablename,string str[]);
// SiteInfos Get_SiteInfo();
// bool Save_SiteInfo(SiteInfo site);
#endif /*_DDB_METADATA_H_*/
