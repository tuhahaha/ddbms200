#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include "../metadata/metadata.h"
using namespace std;


// Do not need metadata
string GetBetween(string sql_statement, string start, string end);
string GetAfter(string sql_statement, string start);
string GetBefore(string sql_statement, string end);
vector<string> GetList(string line, string split, string stop);
void Traverse(vector<string> input);
string Link(vector<string> input, string devide);
string GetTableName(string sql_statement);
vector<string> GetTableList(string TableName);
string GetSelectColumnName(string sql_statement);
vector<string> GetSelectColumnList(string sql_statement);
string GetCondition(string sql_statement);
string GetTableFromColumn(string column, vector<string> TableList);
vector<string> GetColumnFromCondition(string condtion, vector<string> TableList);
vector<string> GetColumnListFromConditionList(vector<string> ConditionList, vector<string> TableList);
vector<string> GetAllColumnList(string sql_statement);
vector<string> GetAllData(string sql_statement);
int GetTCLoc(string table, string column);
string GetPureColumnFromColumn(string column);
string Link(vector<string> input, string devide);

// Need metadata 
// int GetIdFromTC(string table, string column);
// int GetSiteFromTC(string table, string column);
// vector<int> PushBackUnique(vector<int> original, int input);


