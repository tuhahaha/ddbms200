// #include "Parse_INIT.h"
#include "Parse_LOAD.h"
#include "Parse_SELECT.h"
#include "Tools.h"
using namespace std;

int main() {

    string sql_statement;
    // in load function
    vector<string> sql_statements;
    string create_sql_yq;
    string load_sql_yq;
    string main_name;
    vector<string> sitenames;
    vector<string> sqls;
    vector<string> table_names;
    // in load function end

    // sql_statement = "CREATE TABLE Pulisher[ id int(24) key,name char(100),nation char(100)];"; 
    sql_statement = "LOCAL CREATE TABLE Publisher (id int(6) key, name char(100), nation char(3)) ON SITE 1;";
    // sql_statement = "LOCAL LOAD ALLDATA TO TABLE Publisher FROM LOCAL FILE the path;";
    // sql_statements.clear();
    // sql_statement = "LOCAL LOAD LOCALDATA TABLE Publisher BY H WITH ( id<104000 nation='PRC') TO Publisher_1 ON SITE 1;";
    // sql_statements.push_back(sql_statement);
    // sql_statement = "LOCAL LOAD LOCALDATA TABLE Publisher BY H WITH ( id<104000 nation='USA') TO Publisher_2 ON SITE 2;";
    // sql_statements.push_back(sql_statement);
    // sql_statement = "LOCAL LOAD LOCALDATA TABLE Publisher BY H WITH ( id>=104000 nation='PRC') TO Publisher_3 ON SITE 3;";
    // sql_statements.push_back(sql_statement);
    // sql_statement = "LOCAL LOAD LOCALDATA TABLE Publisher BY H WITH ( id>=104000 nation='USA') TO Publisher_4 ON SITE 4;";
    // sql_statements.push_back(sql_statement);
    // cout << sql_statement.find("LOCAL") << endl;
    // cin >> sql_statement;
    while (true) {
        if (sql_statement.find("CREATE TABLE") != -1) {
            // InitGetGDDCreateTable(sql_statement);
            // GDD gdd = InitGetGDDCreateTable(sql_statement);
            // saveTableToEtcd(gdd);
            cin >> sql_statement;
        }
        else if (sql_statement.find("CREATE FRAGMENTATION") != -1) {
            // Fragment fragment = InitGetFragmentCreateFragment(sql_statement);
            // saveFragToEtcd(fragment);
            cin >> sql_statement;
        }
        else if (sql_statement.find("LOCAL") != -1) {         
            cout << "LOCAL" << endl;  
            while (true){
                if (sql_statement.find("CREATE") != -1) {
                    create_sql_yq = GetLocalCreate(sql_statement);
                    cin >> sql_statement;
                }
                else if (sql_statement.find("ALLDATA") != -1) {
                    load_sql_yq = GetLoadSql(sql_statement);
                    main_name = GetTableFromLocalLoad(sql_statement);
                    cin >> sql_statement;
                }
                else if (sql_statement.find("LOCALDATA") != -1) {
                    sql_statements.push_back(sql_statement);
                    cin >> sql_statement;
                }
                else if (sql_statement == "LOAD FINISH") {
                    sitenames = GetSiteNames(sql_statements);
                    sqls = GetSqls(sql_statements);
                    table_names = GetTableNames(sql_statements);
                    // string result = Data_Load_Execute(create_sql_yq,load_sql_yq,main_name,sitenames,sqls,table_names); // call yq's function
                    // cout << result << endl;
                    sql_statements.clear();
                    sitenames.clear();
                    sqls.clear();
                    table_names.clear();
                    cin >> sql_statement;
                }
                else {
                    cout << "INVALID LOAD COMMENT" << endl;
                }
            }
        }
        else if (sql_statement.find("INSERT") != -1) {
            cin >> sql_statement;
        }
        else if (sql_statement.find("DELETE") != -1) {
            // string/ sql_statement_2 = "SELECT * FROM " + GetAfter(sql_statement, "FROM");
            cin >> sql_statement;
        }
        else if (sql_statement.find("SELECT") != -1) {
            // Data_Select_Execute(SELECT(sql_statement, 0)); // call yq's function
            cin >> sql_statement;
        }
        else if (sql_statement == "QUIT") {
            break;
        }
        else {
            cout << "INVALID SQL STATEMENT " << endl;
            cin >> sql_statement;
        }
        
    }
    return 0;
}