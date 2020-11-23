#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include "Tools.h"
#include "../metadata/metadata.h"

using namespace std;

int GetSite(string sql_statement);
string GetFragType(string sql_statement);
string GetCreateSql(string sql_statement);
string GetSqlFromGddCols(vector<ColumnDef> cols);
string GetLoadSql(string sql_statement);

int main() {
    string sql_statement = "LOAD TABLE Publisher TO SITE 1 BY H WITH (id<104000 nation='PRC') AS Publiser.1;";
    int site = GetSite(sql_statement);
    string type = GetFragType(sql_statement);
    string sql_statement_create = GetCreateSql(sql_statement);
    string sql_statement_load = GetLoadSql(sql_statement);

    // cout << site << endl;
    cout << type << endl;
    cout << sql_statement_create << endl;
    // cout << sql_statement_load << endl;
    return 0;
}

int GetSite(string sql_statement) {
    int site = stoi(GetBetween(sql_statement, "SITE", "WITH"));
    return site;
}
string GetFragType(string sql_statement){
    string type;
    type = GetBetween(sql_statement, "BY", "WITH");
    return type;
}

string GetCreateSql(string sql_statement) {
    string sql_statement_create;
    string table_name_from = GetBetween(sql_statement, "TABLE", "TO");
    cout << table_name_from << endl;
    string table_name_to = GetAfter(sql_statement, "AS");
    cout << table_name_to << endl;
    sql_statement_create = "CREATE TABLE " + table_name_to  ;
    // GDD gdd = getTableFromEtcd(table_name_from);
    // vector<ColumnDef> cols = gdd.cols;
    return sql_statement_create;
}
string GetSqlFromGddCols(vector<ColumnDef> cols) {
    string sql_statement;
    return sql_statement;
}
string GetLoadSql(string sql_statement) {
    string sql_statement_load;
    if (GetFragType(sql_statement) == 'h')
    // sql_statement_load = "SELECT * FROM "
    return sql_statement_load;
}