#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include"Tools.h"
#include "../metadata/metadata.h"

using namespace std;

string InitGetTableCreateTable(string sql_statement);
vector<ColumnDef> InitGetColumnsCreateTable(string sql_statement);
GDD InitGetGDDCreateTable(string sql_statement);
string InitGetTableCreateFragmentation(string sql_statement);
string InitGetFragmentTypeCreateFragmentation(string sql_statement);
vector<FragDef> InitGetFragDefCreateFragmentation(string sql_statement);
void TraverseGDD(GDD gdd);

int main() {
    string sql_statement = "CREATE TABLE Pulisher[ id int(24) key,name char(100),nation char(100)];"; 
    vector<string> sql_statement_list;
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Customer[ id int(24) key,name char(100),rank char(100)];";
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Book[ id int(24) key,title char(100),authors char(100),publisher_id int(24),copies int(24)];";
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Orders[ customer_id int(24) key,Book_id int(24) key,quantity int(24)];";
    sql_statement_list.push_back(sql_statement);
    // GDD gdd_tmp;
    // gdd_tmp.name = InitGetTableCreateTable(sql_statement);
    // gdd_tmp.cols = InitGetColumnsCreateTable(sql_statement);
    // TraverseGDD(gdd_tmp);
    for (int i = 0; i < sql_statement_list.size(); i++) {
        GDD gdd_tmp;
        gdd_tmp = InitGetGDDCreateTable(sql_statement_list[i]);
        TraverseGDD(gdd_tmp);
        saveTableToEtcd(gdd_tmp);
    }
    // saveTableToEtcd(gdd_tmp);

    // Fragment fragment_tmp;
    // string sql_statement = "CREATE FRAGMENTATION Publisher ( H,1 id<104000ANDnation='PRC' 1,2 id<104000ANDnation='PRC' 2,3 id>=104000ANDnation='USA' 3,4 id>=104000ANDnation='USA' 4 );";
    // fragment_tmp.name = InitGetTableCreateFragmentation(sql_statement);
    // cout << InitGetTableCreateFragmentation(sql_statement) << endl;
    // fragment_tmp.fragtype = InitGetFragmentTypeCreateFragmentation(sql_statement);
    // cout << InitGetFragmentTypeCreateFragmentation(sql_statement) << endl;
    // InitGetFragDefCreateFragmentation(sql_statement);
    return 0;
}
string InitGetTableCreateTable(string sql_statement) {
    return GetBetween(sql_statement, "CREATE TABLE", "[");
}
vector<ColumnDef> InitGetColumnsCreateTable(string sql_statement) {
    string column_line = GetBetween(sql_statement, "[","]");
    vector<string> column_list = GetList(column_line,",","]");
    vector<ColumnDef> cols;
    for (int i = 0; i < column_list.size(); i++ ) {
        string column_tmp = column_list[i];
        // cout << "== " << column_tmp << " ==" << endl;
        vector<string> column_tmp_list = GetList(column_tmp, " ", "]");
        ColumnDef cols_tmp;
        cols_tmp.name = column_tmp_list[0];
        cols_tmp.type = column_tmp_list[1];
        if (column_tmp_list.size() >= 3 && column_tmp_list[2] == "key") {
            cols_tmp.key = true;
        }
        cols.push_back(cols_tmp);
    }
    return cols;
}
GDD InitGetGDDCreateTable(string sql_statement) {
    GDD gdd;
    gdd.name = InitGetTableCreateTable(sql_statement);
    gdd.cols = InitGetColumnsCreateTable(sql_statement);
    return gdd;
}
string InitGetTableCreateFragmentation(string sql_statement) {
    return GetBetween(sql_statement, "CREATE FRAGMENTATION", "(");
}
string InitGetFragmentTypeCreateFragmentation(string sql_statement) {
    string fragment_line = GetBetween(sql_statement, "(", ")");
    vector<string> fragment_list = GetList(fragment_line,",",")");
    // Traverse(fragment_list);
    return fragment_list[0];
}
vector<FragDef> InitGetFragDefCreateFragmentation(string sql_statement) {
    string fragment_line = GetBetween(sql_statement, "(", ")");
    vector<string> fragment_list = GetList(fragment_line,",",")");
    // Traverse(fragment_list);
    vector<FragDef> frags;
    for (int i = 1; i < fragment_list.size(); i++) {
        string fragement_tmp = fragment_list[i];
        cout << "== " << fragement_tmp << " ==" << endl;
        vector<string> fragment_tmp_list = GetList(fragement_tmp, " ", ")");
        // Traverse(fragment_tmp_list);
        cout << fragment_tmp_list[0] << endl;
        cout << fragment_tmp_list[2] << endl;
        // FragDef frags_tmp;
        // vector<string> condition_list = GetList(fragment_tmp_list[1]," AND ", ")");
        // Traverse(condition_list);
        // vector<string> TableList;
        // TableList.push_back(InitGetFragmentTypeCreateFragmentation(sql_statement));
        // frags_tmp.column = GetColumnListFromConditionList(condition_list, TableList);
        // frags_tmp.condition = fragment_tmp_list[1];
        // frags_tmp.id = int(fragment_tmp_list[0]);
        // frags_tmp.site = int(fragment_tmp_list[2]);
        // frags_tmp.size = -1;
        // frags.push_back(frags_tmp);
    }
    return frags;
}
void TraverseGDD(GDD gdd) {
    cout << "TABLE NAME : " << gdd.name << endl;
    cout << "THE SIZE OF GDD.COLS IS " << gdd.cols.size() << endl;
    for (int i = 0; i < gdd.cols.size(); i++) {
        cout << "   " << gdd.cols[i].name << endl;
        cout << "   " << gdd.cols[i].type << endl;
        cout << "   " << gdd.cols[i].key << endl;
    }
}