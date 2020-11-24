#include "Tools.h"
#include "../metadata/metadata.h"
#include "Parse_INIT.h"
#include "Parse_LOAD.h"

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
    sql_statement = "CREATE TABLE Pulisher[ id int(24) key,name char(100),nation char(100)];"; 
    if (sql_statement.find("CREATE TABLE") != -1) {
        GDD gdd = InitGetGDDCreateTable(sql_statement);
        // TraverseGDD(gdd);
        // cout << gdd.name << endl;
        // saveTableToEtcd(gdd);
    }
    else if (sql_statement.find("CREATE FRAGMENTATION") != -1) {
        // Fragment fragment = InitGetFragmentCreateFragment(sql_statement);
        // saveFragToEtcd(fragment);
    }
    // else if (sql_statement.find("LOCAL") != -1) {
    //     if (sql_statement.find("CREATE") != -1) {
    //         int site = GetSite(sql_statement);
    //         string sql_localcreate = GetLocalCreate(sql_statement);
    //     }
    //     else if (sql_statement.find("ALLDATA") != -1) {
    //         string table_name = GetTableFromLocalLoad(sql_statement);
    //         string path = GetPathFromLocalLoad(sql_statement);
    //     }
    //     else if (sql_statement.find("LOCALDATA") != -1) {
    //         string select_sql = GetSelectSqlFromLoadLocalData(sql_statement);
    //         string to_table = GetToTable(sql_statement);
    //     }
    //     else {
    //         cout << "INVALID LOAD DATA" << endl;
    //     }
    // }
    // else if (sql_statement.find("INSERT") != -1) {

    // }
    // else if (sql_statement.find("DELETE") != -1) {

    // }
    // else if (sql_statement.find("SELECT") != -1) {

    // }
    else {
        cout << "INVALID SQL STATEMENT " << endl;
    }
    return 0;
}