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
            TREE Tree = SELECT(sql_statement,0);
            TraverseTree(Tree.Nodes);
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