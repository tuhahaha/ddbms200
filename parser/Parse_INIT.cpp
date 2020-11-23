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
void Traversefrags(vector<FragDef> frags);
void TraverseFragment(Fragment);

int main() {
<<<<<<< HEAD
    // Create table
    // string sql_statement = "CREATE TABLE Pulisher[ id int(24) key,name char(100),nation char(100)];"; 
    // vector<string> sql_statement_list;
    // sql_statement_list.push_back(sql_statement);
    // sql_statement = "CREATE TABLE Customer[ id int(24) key,name char(100),rank char(100)];";
    // sql_statement_list.push_back(sql_statement);
    // sql_statement = "CREATE TABLE Book[ id int(24) key,title char(100),authors char(100),publisher_id int(24),copies int(24)];";
    // sql_statement_list.push_back(sql_statement);
    // sql_statement = "CREATE TABLE Orders[ customer_id int(24) key,Book_id int(24) key,quantity int(24)];";
    // sql_statement_list.push_back(sql_statement);
=======
    string sql_statement = "CREATE TABLE Pulisher[ id int(24) key,name char(100),nation char(100)];"; 
    vector<string> sql_statement_list;
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Customer[ id int(24) key,name char(100),rank char(100)];";
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Book[ id int(24) key,title char(100),authors char(100),publisher_id int(24),copies int(24)];";
    sql_statement_list.push_back(sql_statement);
    sql_statement = "CREATE TABLE Orders[ customer_id int(24) key,Book_id int(24) key,quantity int(24)];";
    sql_statement_list.push_back(sql_statement);
>>>>>>> e90ee96bccfe8d57d105dff87d18aa3810ae443b
    // GDD gdd_tmp;
    // gdd_tmp.name = InitGetTableCreateTable(sql_statement);
    // gdd_tmp.cols = InitGetColumnsCreateTable(sql_statement);
    // TraverseGDD(gdd_tmp);
<<<<<<< HEAD
    // for (int i = 0; i < sql_statement_list.size(); i++) {
    //     gdd_tmp = InitGetGDDCreateTable(sql_statement_list[i]);
    //     TraverseGDD(gdd_tmp);
    // }
=======
    for (int i = 0; i < sql_statement_list.size(); i++) {
        GDD gdd_tmp;
        gdd_tmp = InitGetGDDCreateTable(sql_statement_list[i]);
        TraverseGDD(gdd_tmp);
        saveTableToEtcd(gdd_tmp);
    }
>>>>>>> e90ee96bccfe8d57d105dff87d18aa3810ae443b
    // saveTableToEtcd(gdd_tmp);
    
    // Create Fragment 
    Fragment fragment_tmp;
    string sql_statement = "CREATE FRAGMENTATION Publisher ( H,1 Publisher.id<104000ANDPublisher.nation='PRC' 1,2 Publisher.id<104000ANDPublisher.nation='PRC' 2,3 Publisher.id>=104000ANDPublisher.nation='USA' 3,4 Publisher.id>=104000ANDPublisher.nation='USA' 4 );";
    fragment_tmp.name = InitGetTableCreateFragmentation(sql_statement);
    fragment_tmp.fragtype = InitGetFragmentTypeCreateFragmentation(sql_statement);
    fragment_tmp.frags = InitGetFragDefCreateFragmentation(sql_statement);
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
    // Traverse(fragment_list);
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

        vector<string> condition_list = GetList(fragment_tmp_list[1],"AND", ")");
        Traverse(condition_list);
        vector<string> TableList;
        TableList.push_back(InitGetTableCreateFragmentation(sql_statement));
        vector<string> column_list = GetColumnListFromConditionList(condition_list, TableList);
        Traverse(column_list);
        frags.push_back(frags_tmp);
    }
    return frags;
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