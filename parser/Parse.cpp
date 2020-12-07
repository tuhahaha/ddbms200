#include "Parse_INIT.h"
#include "Parse_LOAD.h"
#include "Parse_SELECT.h"
#include <vector>
#include "Tools.h"

using namespace std;
/*
The parser mainly contains 6 functions
SelectObject Parse_SELECT(string sql_statement);
InsertObject Parse_INSERT(string sql_statement);
DeleteObject Parse_DELETE(string sql_statement);
GDD Parse_CREATE_TABLE(string sql_statement);
Fragment Parse_CREATE_FRAGMENTATION(string sql_statement);
LoadObject Parse_LOAD(string sql_statement);
*/

// SelectObject Parse_SELECT(string sql_statement);
// InsertObject Parse_INSERT(string sql_statement);
// DeleteObject Parse_DELETE(string sql_statement);
// GDD Parse_CREATE_TABLE(string sql_statement);
// Fragment Parse_CREATE_FRAGMENTATION(string sql_statement);
// LoadObject Parse_LOAD(string sql_statement);

// SelectObject Parse_SELECT(string sql_statement) {
    
// }
// InsertObject Parse_INSERT(string sql_statement);
// DeleteObject Parse_DELETE(string sql_statement);
// GDD Parse_CREATE_TABLE(string sql_statement) {
//     GDD gdd;
//     gdd.name = InitGetTableCreateTable(sql_statement);
//     gdd.cols = InitGetColumnsCreateTable(sql_statement);
//     return gdd;
// }
// Fragment Parse_CREATE_FRAGMENTATION(string sql_statement);
// LoadObject Parse_LOAD(string sql_statement);

int main() {
    string sql_statement;
    vector<string> sql_statements;
    string create_sql_yq;
    string load_sql_yq;
    string main_name;
    vector<string> sitenames;
    vector<string> sqls;
    vector<string> table_names;

    sql_statement = "CREATE TABLE Pulisher[ id int(24) key,name char(100),nation char(100)];"; 
    while (true) {
        cin >> sql_statement;
        if (sql_statement.find("CREATE TABLE") != -1) {
            GDD gdd = InitGetGDDCreateTable(sql_statement);
            saveTableToEtcd(gdd);
        }
        else if (sql_statement.find("CREATE FRAGMENTATION") != -1) {
            Fragment fragment = InitGetFragmentCreateFragment(sql_statement);
            saveFragToEtcd(fragment);
        }
        else if (sql_statement.find("LOCAL") != -1) {           
            while (true){
                if (sql_statement.find("CREATE") != -1) {
                    create_sql_yq = GetLocalCreate(sql_statement);
                }
                else if (sql_statement.find("ALLDATA") != -1) {
                    load_sql_yq = GetLoadSql(sql_statement);
                    main_name = GetTableFromLocalLoad(sql_statement);
                }
                else if (sql_statement.find("LOCALDATA") != -1) {
                    sql_statements.push_back(sql_statement);
                }
                else if (sql_statement == "LOAD FINISH") {
                    sitenames = GetSiteNames(sql_statements);
                    sqls = GetSqls(sql_statements);
                    table_names = GetTableNames(sql_statements);
                    string result = Data_Load_Execute(create_sql_yq,load_sql_yq,main_name,sitenames,sqls,table_names); // call yq's function
                    cout << result << endl;
                    sql_statements.clear();
                    sitenames.clear();
                    sqls.clear();
                    table_names.clear();
                    continue;
                }
                else {
                    cout << "INVALID LOAD COMMENT" << endl;
                }
            }
        }
        // else if (sql_statement.find("INSERT") != -1) {

        // }
        // else if (sql_statement.find("DELETE") != -1) {

        // }
        else if (sql_statement.find("SELECT") != -1) {
            Data_Select_Execute(SELECT(sql_statement, 0)); // call yq's function
        }
        else if (sql_statement == "QUIT") {
            break;
        }
        else {
            cout << "INVALID SQL STATEMENT " << endl;
        }
    }
    return 0;
}