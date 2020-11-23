#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include"Tools.h"
#include "../metadata/metadata.h"

using namespace std;
// Create table
string InitGetTableCreateTable(string sql_statement);
vector<ColumnDef> InitGetColumnsCreateTable(string sql_statement);
GDD InitGetGDDCreateTable(string sql_statement);
void TraverseGDD(GDD gdd);
// Create Fragment
string InitGetTableCreateFragmentation(string sql_statement);
string InitGetFragmentTypeCreateFragmentation(string sql_statement);
vector<FragDef> InitGetFragDefCreateFragmentation(string sql_statement);
int InitGetFragNumCreateFragmentation(string sql_statement);
void Traversefrags(vector<FragDef> frags);
void TraverseFragment(Fragment);
Fragment InitGetFragmentCreateFragment(string sql_statement);

int main() {
    // Create table
    string sql_statement;
    vector<string> sql_statement_list;
    sql_statement = "CREATE TABLE Pulisher[ id int(24) key,name char(100),nation char(100)];"; 
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Customer[ id int(24) key,name char(100),rank char(100)];";
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Book[ id int(24) key,title char(100),authors char(100),publisher_id int(24),copies int(24)];";
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Orders[ customer_id int(24) key,Book_id int(24) key,quantity int(24)];";
    sql_statement_list.push_back(sql_statement);
    GDD gdd_tmp;
    for (int i = 0; i < sql_statement_list.size(); i++) {
        gdd_tmp = InitGetGDDCreateTable(sql_statement_list[i]);
        // TraverseGDD(gdd_tmp);
        // saveTableToEtcd(gdd_tmp);
    }
    
    // Create Fragment 
    vector<string> sql_statement_list2;
    sql_statement = "CREATE FRAGMENTATION Publisher ( H,1 Publisher.id<104000ANDPublisher.nation='PRC' 1,2 Publisher.id<104000ANDPublisher.nation='PRC' 2,3 Publisher.id>=104000ANDPublisher.nation='USA' 3,4 Publisher.id>=104000ANDPublisher.nation='USA' 4 );";
    sql_statement_list2.push_back(sql_statement);
    sql_statement = "CREATE FRAGMENTATION Book ( H,1 Book.id<205000 1,2 Book.id>=205000ANDid<210000 2,3 Book.id>=210000 3);";
    sql_statement_list2.push_back(sql_statement);
    sql_statement = "CREATE FRAGMENTATION Customer ( V,1 Customer.idANDCustomer.name 1,2 Customer.idANDCusomer.rank 2);";
    sql_statement_list2.push_back(sql_statement);
    sql_statement = "CREATE FRAGMENTATION Orders ( H,1 Orders.customer_id<307000ANDOrders.customer_id<215000 1,2 Orders.customer_id<307000ANDOrders.book_id>=215000 2,3 Orders.customer_id>=307000ANDOrders.book_id<215000 3,4 Orders.cusomer_id>=307000ANDOrders.book_id>=215000 4);";
    sql_statement_list2.push_back(sql_statement);
    Fragment fragment_tmp;
    for (int i = 0; i < sql_statement_list2.size(); i++) {
        cout << i << " =="<< endl;
        fragment_tmp = InitGetFragmentCreateFragment(sql_statement_list2[i]);
        // saveFragToEtcd(fragment_tmp);
    }
    return 0;
}

// Create table
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
void TraverseGDD(GDD gdd) {
    cout << "TABLE NAME : " << gdd.name << endl;
    cout << "THE SIZE OF GDD.COLS IS " << gdd.cols.size() << endl;
    for (int i = 0; i < gdd.cols.size(); i++) {
        cout << "   " << gdd.cols[i].name << endl;
        cout << "   " << gdd.cols[i].type << endl;
        cout << "   " << gdd.cols[i].key << endl;
    }
}

// Create Fragment
string InitGetTableCreateFragmentation(string sql_statement) {
    return GetBetween(sql_statement, "CREATE FRAGMENTATION", "(");
}
string InitGetFragmentTypeCreateFragmentation(string sql_statement) {
    string fragment_line = GetBetween(sql_statement, "(", ")");
    vector<string> fragment_list = GetList(fragment_line,",",")");
    return fragment_list[0];
}
vector<FragDef> InitGetFragDefCreateFragmentation(string sql_statement) {
    string fragment_line = GetBetween(sql_statement, "(", ")");
    vector<string> fragment_list = GetList(fragment_line,",",")");
    vector<FragDef> frags;
    for (int i = 1; i < fragment_list.size(); i++) {
        string fragement_tmp = fragment_list[i];
        vector<string> fragment_tmp_list = GetList(fragement_tmp, " ", ")");
        FragDef frags_tmp;        
        frags_tmp.condition = fragment_tmp_list[1];
        frags_tmp.id = stoi(fragment_tmp_list[0]);
        frags_tmp.site = stoi(fragment_tmp_list[2]);
        frags_tmp.size = 0;
        frags.push_back(frags_tmp);
    }
    return frags;
}
Fragment InitGetFragmentCreateFragment(string sql_statement) {
    Fragment fragment;
    fragment.fragnum = InitGetFragNumCreateFragmentation(sql_statement);
    cout << "fragnum :"<< fragment.fragnum << endl;
    fragment.fragtype = InitGetFragmentTypeCreateFragmentation(sql_statement);
    cout << "fragtype :"<<fragment.fragtype << endl;
    fragment.name = InitGetTableCreateFragmentation(sql_statement);
    cout << "name " << fragment.name << endl;
    fragment.frags = InitGetFragDefCreateFragmentation(sql_statement); // Segmentation fault (core dumped)
    // cout << fragment.frags << endl;
    return fragment;
}
int InitGetFragNumCreateFragmentation(string sql_statement) {
    string fragment_line = GetBetween(sql_statement, "(", ")");
    vector<string> fragment_list = GetList(fragment_line,",",")");
    return fragment_list.size()-1;
}
void Traversefrags(vector<FragDef> frags) {
    for (int i = 0; i < frags.size(); i++) {
        cout << frags[i].column << endl;
        cout << frags[i].condition << endl;
        cout << frags[i].id << endl;
        cout << frags[i].site << endl;
        cout << frags[i].size << endl;
    }
}
void TraverseFragment(Fragment fragment) {
    cout << fragment.name << endl;
    cout << fragment.fragtype << endl;
    cout << fragment.fragnum << endl;
    Traversefrags(fragment.frags);
}