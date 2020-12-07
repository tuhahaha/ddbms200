#include "Parse_INIT.h"
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
    // sql_statement = "LOCAL CREATE TABLE Publisher (id int(6) key, name char(100), nation char(3)) ON SITE 1;";
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
    while (true) {
        getline(cin,sql_statement);
        if (sql_statement.find("LOCAL") != -1) {
            cout << "LOCAL" << endl;
            if (sql_statement.find("CREATE TABLE") != -1) {
                create_sql_yq = GetLocalCreate(sql_statement);
            }
            else if (sql_statement.find("LOAD ALLDATA") != -1) {
                load_sql_yq = GetLoadSql(sql_statement);
                main_name = GetTableFromLocalLoad(sql_statement);
            }
            else if (sql_statement.find("LOAD LOCALDATA") != -1) {
                sql_statements.push_back(sql_statement);
            }
            else if (sql_statement.find("LOCAL FINISH") != -1) {
                sitenames = GetSiteNames(sql_statements);
                sqls = GetSqls(sql_statements);
                table_names = GetTableNames(sql_statements);

                cout << "create_sql_yq " << create_sql_yq << endl;
                cout << "load_sql_yq " << load_sql_yq << endl;
                cout << "main_name " << main_name << endl;
                Traverse(sitenames);
                Traverse(sqls);
                Traverse(table_names);
                // string result = Data_Load_Execute(create_sql_yq,load_sql_yq,main_name,sitenames,sqls,table_names);
                // cout << result << endl;
            }
            else {
                cout << "INVALID LOAD COMMNET" << endl;
            }
            continue;
        }
        else if (sql_statement.find("CREATE TABLE") != -1) {
            cout << "CREATE TABLE" << endl;
            GDD gdd = InitGetGDDCreateTable(sql_statement);
            saveTableToEtcd(gdd);
        }
        else if (sql_statement.find("CREATE FRAGMENTATION") != -1) {
            cout << "CREATE FRAGMENTATION" << endl;
            Fragment fragment = InitGetFragmentCreateFragment(sql_statement);
            saveFragToEtcd(fragment);
        }
        else if (sql_statement.find("SELECT") != -1) {
            cout << "SELECT" << endl;
            continue;
        }
        else if (sql_statement == "QUIT") {
            break;
        }
        else {
            cout << "INVALID SQL STATEMENT " << endl;
            continue;
        }
    }
    return 0;
}