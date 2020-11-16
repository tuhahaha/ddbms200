//metadata managemant
#ifndef _DDB_METADATA_H_
#define _DDB_METADATA_H_
#include <curl/curl.h> 
#include <iostream>  
#include <string>
#include <map> 
#include <regex>
#include <vector>
#include <sstream>

// #define MAX_FRAG_COUNT1 100
// #define MAX_FRAG_V 10
// #define MAX_FRAG_H 10


using namespace std;
using namespace Json;

// table 
struct GDD {
	string name;
	vector<ColumnDef> cols;
};
// column
struct ColumnDef {
	string name;
	string type;
	bool null;
	bool key;
	string desc;
};
// table-fragment
struct Fragment {
	string name;
	string fragtype; // H/V 
	int fragnum;
	vector<FragDef> frags;
};
// fragment
struct FragDef {
	int id;
    int site;
    string column; //该分片涉及到的column，如果是多个，则用逗号分隔
	string condition; //分片条件
    int size; //记录该分片的大小，以byte为单位
};

vector<string> split2list(string info);
vector<string> getTables();
vector<string> getTableAttri(string: tableName);
string getTableAttriType(string: tableName, string: attriName);
string getTableAttriDesc(string: tableName, string:attriName);
string getTableKey(string: tableName);
string getTableFragType(string: tableName);
vector<string> getTableFragH(string: tableName);
int getTableFragNum(string: tableName);
string getTableFragCondition(string: tableName, int index);
string getTableFragCol(string: tableName, int index);
int getTableFragSize(string: tableName,int index);
int getTableFragSite(string: tableName,int index);
bool saveTableToEtcd(GDD table);
bool saveFragToEtcd(Fragment frag);

int etcd_set(char *key, char *value, char *token);
int etcd_set2(char *key, char *value, char *token);
string  Create_Dir(string &etcd_url,string &etcd_dir);  
bool Insert_Attrvalue(string &dir,string &value);
string Search_Value(string &dir);

// size_t write_data(void *buffer, size_t size, size_t nmemb, void *stream);
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
