// 生成可执行文件m
g++ metadata.cc -lcurl -ljson -o m

//函数调用说明

//可能会经常用到：直接存取GDD，Fragment对象
bool saveTableToEtcd(GDD table);
GDD getTableFromEtcd(string tablename);
bool saveFragToEtcd(Fragment frag);
Fragment getFragFromEtcd(string tablename);

//可能会用到：直接存取细致信息
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

//具体数据类型请看metadata.h

***********11-18
1，ETCD访问接口已全部完成
2，根据set_etcd.sh可以部署好4 sites


3，后续需要站点互相访问时再聚到一起部署环境，建议先将表格信息写死到strct里直接使用。
