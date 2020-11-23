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
string GetLocalFile(string sql_statement);

int main() {
    string sql_statement;
    // sql_statement = "CREATE TABLE Publisher (id int(6) key, name char(100), nation char(3)) ON SITE 1;";
    sql_statement = "LOAD ALLDATA TO TABLE Publisher FROM LOCAL FILE the path;";
    // sql_statement = "LOAD LOCALDATA TABLE Publisher BY H WITH ( id<104000 nation='PRC') TO Publiser.1 ON SITE 1;";
    
    // int site = GetSite(sql_statement);
    // string type = GetFragType(sql_statement);
    // cout <<type.size()<<endl;
    // string sql_statement_create = GetCreateSql(sql_statement);
    // string sql_statement_load = GetLoadSql(sql_statement);
    string local_file = GetLocalFile(sql_statement);

    // cout << site << endl;
    // cout << type << endl;
    // cout << sql_statement_create << endl;
    // cout << sql_statement_load << endl;
    cout << local_file << endl;


    // sql_statement = "LOAD TABLE Customer TO SITE 1 BY V WITH ( id rank) AS Customer.1 THE LOCAL FILE IS the path;";
    // int site = GetSite(sql_statement);
    // string type = GetFragType(sql_statement);
    // string sql_statement_create = GetCreateSql(sql_statement);
    // string sql_statement_load = GetLoadSql(sql_statement);

    // cout << site << endl;
    // cout << type << endl;
    // cout << sql_statement_create << endl;
    // cout << sql_statement_load << endl;

    return 0;
}

int GetSite(string sql_statement) {
    int site = stoi(GetBetween(sql_statement, "SITE", ";"));
    return site;
}
string GetFragType(string sql_statement){
    string type;
    type = GetBetween(sql_statement, "BY", "WITH");
    return type.substr(0,1);
}

string GetCreateSql(string sql_statement) {
    string sql_statement_create;
    string table_name_from = GetBetween(sql_statement, "TABLE", "TO");
    cout << table_name_from << endl;
    string table_name_to = GetBetween(sql_statement, "AS"," THE LOCAL FILE");
    cout << table_name_to << endl;
    sql_statement_create = "CREATE TABLE " + table_name_to;
    if (GetFragType(sql_statement) == "H") {
        sql_statement_create += " (id int(6) key, name char(100), nation char(3));";
    }
    else if (GetFragType(sql_statement) == "V") {
        sql_statement_create += "(id int(6), rank int(6));";
    }
    else {
        cout << "ERROR: Invalid FragType" << endl;
    }
    cout << sql_statement_create << endl;
    return sql_statement_create;
}
string GetSqlFromGddCols(vector<ColumnDef> cols) {
    string sql_statement;
    return sql_statement;
}
string GetLoadSql(string sql_statement) {
    string sql_statement_load;
    string table_from = GetBetween(sql_statement, "TABLE", "TO"); 
    string table_to = GetBetween(sql_statement, "AS"," THE LOCAL FILE");
    if (GetFragType(sql_statement) == "H") {
        string condition = GetBetween(sql_statement, "(",")");
        vector<string> condition_list = GetList(condition," ",";");
        string sql_statment_condition = Link(condition_list, " AND ");
        sql_statement_load = "SELECT * FROM " +  GetBetween(sql_statement, "TABLE", "TO") + "WHERE " + sql_statment_condition;
    }
    else if (GetFragType(sql_statement) == "V") {
        string column = GetBetween(sql_statement, "(", ")");
        vector<string> column_list = GetList(column, " ", ";");
        string sql_statement_column = Link(column_list,",");
        sql_statement_load = "SELECT " +  sql_statement_column + " FROM " + table_from + ";";
    }
    else {
        cout << "ERROR: Invalid FragType" << endl;
    }
    return sql_statement_load;
}
string GetLocalFile(string sql_statement) {
    string local_file;
    local_file = GetBetween(sql_statement,"FROM LOCAL FILE",";");
    return local_file;
}