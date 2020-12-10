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
    Fragment fragment;
    sql_statement = "CREATE FRAGMENTATION publisher( H,1 publisher.id<104000ANDpublisher.nation='PRC' 1,2 publisher.id<104000ANDpublisher.nation='PRC' 2,3 publisher.id>=104000ANDpublisher.nation='USA' 3,4 publisher.id>=104000ANDpublisher.nation='USA' 4 );";
    fragment = InitGetFragmentCreateFragment(sql_statement);
    saveFragToEtcd(fragment);
    sql_statement = "CREATE FRAGMENTATION book( H,1 book.id<205000 1,2 book.id>=205000ANDid<210000 2,3 book.id>=210000 3);";
    fragment = InitGetFragmentCreateFragment(sql_statement);
    saveFragToEtcd(fragment);
    sql_statement = "CREATE FRAGMENTATION customer( V,1 customer.idANDcustomer.name 1,2 customer.idANDcusomer.rank 2);";
    fragment = InitGetFragmentCreateFragment(sql_statement);
    saveFragToEtcd(fragment);
    sql_statement = "CREATE FRAGMENTATION orders( H,1 orders.customer_id<307000ANDorders.customer_id<215000 1,2 orders.customer_id<307000ANDorders.book_id>=215000 2,3 orders.customer_id>=307000ANDorders.book_id<215000 3,4 orders.cusomer_id>=307000ANDorders.book_id>=215000 4);";
    fragment = InitGetFragmentCreateFragment(sql_statement);
    saveFragToEtcd(fragment);

    sql_statement = "SELECT customer.name,book.title,publisher.name,orders.quantity FROM customer,book,publisher,orders WHERE customer.id=orders.customer_id and book.id=orders.book_id and book.publisher_id=publisher.id and customer.id>308000 and book.copies>100 and orders.quantity>1 and publisher.nation='PRC'";
    vector<TCC> TCCList = GetTCCListTest(sql_statement);
    TREE Tree = SELECT(sql_statement,0);
    TraverseTree(Tree.Nodes);
    Data_Select_Execute(Tree);
    // while (true) {
    //     getline(cin,sql_statement);
    //     if (sql_statement.find("LOCAL") != -1) {
    //         cout << "LOCAL" << endl;
    //         if (sql_statement.find("CREATE TABLE") != -1) {
    //             create_sql_yq = GetLocalCreate(sql_statement);
    //         }
    //         else if (sql_statement.find("LOAD ALLDATA") != -1) {
    //             load_sql_yq = GetLoadSql(sql_statement);
    //             main_name = GetTableFromLocalLoad(sql_statement);
    //         }
    //         else if (sql_statement.find("LOAD LOCALDATA") != -1) {
    //             sql_statements.push_back(sql_statement);
    //         }
    //         else if (sql_statement.find("LOCAL FINISH") != -1) {
    //             sitenames = GetSiteNames(sql_statements);
    //             sqls = GetSqls(sql_statements);
    //             table_names = GetTableNames(sql_statements);

    //             cout << "create_sql_yq " << create_sql_yq << endl;
    //             cout << "load_sql_yq " << load_sql_yq << endl;
    //             cout << "main_name " << main_name << endl;
    //             Traverse(sitenames);
    //             Traverse(sqls);
    //             Traverse(table_names);
    //             string result = Data_Load_Execute(create_sql_yq,load_sql_yq,main_name,sitenames,sqls,table_names);
    //             cout << result << endl;
    //             sitenames.clear();
    //             sqls.clear();
    //             table_names.clear();
    //         }
    //         else {
    //             cout << "INVALID LOAD COMMNET" << endl;
    //         }
    //         continue;
    //     }
    //     else if (sql_statement.find("CREATE TABLE") != -1) {
    //         cout << "CREATE TABLE" << endl;
    //         GDD gdd = InitGetGDDCreateTable(sql_statement);
    //         saveTableToEtcd(gdd);
    //     }
    //     else if (sql_statement.find("CREATE FRAGMENTATION") != -1) {
    //         cout << "CREATE FRAGMENTATION" << endl;
    //         Fragment fragment = InitGetFragmentCreateFragment(sql_statement);
    //         saveFragToEtcd(fragment);
    //     }
    //     else if (sql_statement.find("SELECT") != -1) {
    //         cout << "SELECT" << endl;
    //         TREE Tree = SELECT(sql_statement,0);
    //         // TraverseTree(Tree.Nodes);
    //     }
    //     else if (sql_statement == "QUIT") {
    //         break;
    //     }
    //     else {
    //         cout << "INVALID SQL STATEMENT " << endl;
    //         continue;
    //     }
    // }

    return 0;
}