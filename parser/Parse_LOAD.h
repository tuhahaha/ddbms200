#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include "Tools.h"
#include "../metadata/metadata.h"

using namespace std;

// local create
int GetSite(string sql_statement);
string GetLocalCreate(string sql_statement);
// local load ALLDATA
string GetPathFromLocalLoad(string sql_statement);
string GetTableFromLocalLoad(string sql_statement);
string GetFragType(string sql_statement);
// local select and load
string GetSelectSqlFromLoadLocalData(string sql_statement);
string GetToTable(string sql_statement);

