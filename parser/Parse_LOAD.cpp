#include"Tools.h"
using namespace std;

int GetSite(string sql_statement);
string GetCreateSql(string sql_statement);
string GetLoadSql(string sql_statement);

int main() {
    string sql_statement = "LOAD TABLE Publisher TO SITE 1 WITH (id<104000 nation='PRC') AS Publiser.1;";
    int site = GetSite(sql_statement);
    string sql_statement_create = GetCreateSql(sql_statement);
    string sql_statement_load = GetLoadSql(sql_statement);
    return 0;
}

string GetCreateSql(string sql_statement) {
    string sql_statement_create;
    string table_name = GetBetween(sql_statement, "TABLE", "TO");
    cout << table_name << endl;
    return sql_statement_create;
}

string GetLoadSql(string sql_statement) {
    string sql_statement_load;
    return sql_statement_load;
}