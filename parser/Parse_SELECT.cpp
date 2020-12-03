#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include"Tools.h"

using namespace std;

struct NODE {
    int id;
    int child1;
    int child2;
    int child3;
    int child4;
    int parent;
    string sql_statement;
};
struct TCC {
    string table_name;
    string fratype;
    vector<string> condition_list;
    vector<string> column_list;
};

TCC GetTCC(string table_name, vector<string> ColumnList);
vector<TCC> GetTCCList(vector<string> table_list, vector<string> column_list);
vector<string> GetSelectConditionList(vector<string> condition_list, vector<string> table_list);
vector<string> GetJoinConditionList(vector<string> condition_list, vector<string> table_list);

int main() {
    string sql_statement = "SELECT Customer.name,Book.title,Publisher.name,Orders.quantity FROM Customer,Book,Publisher,Orders WHERE Customer.id=Orders.customer_id and Book.id=Orders.book_id and Book.publisher_id=Publisher.id and Customer.id>308000 and Book.copies>100 and Orders.quantity>1 and Publisher.nation='PRC';";
    vector<string> TableList = GetTableList(sql_statement);
    vector<string> ColumnList = GetAllColumnList(sql_statement);
    vector<string> SelectColumnList = GetSelectColumnList(sql_statement);
    vector<TCC> TCCList = GetTCCList(TableList, ColumnList);
    vector<string> ConditionList = GetConditionList(sql_statement);
    vector<string> select_list = GetSelectConditionList(ConditionList, TableList);
    vector<string> join_list = GetJoinConditionList(ConditionList, TableList);
    for (int i = 0; i < TableList.size(); i++) {

    }
    return 0;
}
TCC GetTCC(string table_name, vector<string> column_list) {
    // Get the table_name's column and condition
   TCC tcc;
    for (int i = 0; i < column_list.size(); i++) {
        string table_tmp = GetBefore(column_list[i], ".");
        if (table_tmp == table_name && I ) {
            tcc.column_list.push_back(column_list[i]);
            cout << table_name << " " << column_list[i] << endl;
        }
    }
    return tcc;
}
vector<TCC> GetTCCList(vector<string> table_list, vector<string> column_list) {
    vector<TCC> tcc_list;
    for (int i = 0; i < table_list.size(); i++) {
        TCC tcc = GetTCC(table_list[i], column_list);
        tcc_list.push_back(tcc);
    }
    return tcc_list; 
}
vector<string> GetSelectConditionList(vector<string> condition_list, vector<string> table_list) {
    vector<string> selectcondition_list;
    vector<string> tmp;
    vector<string> joincondition_list;
    // vector<string> condition_list = GetAllColumnList(sql_statement);
    for (int i = 0; i < condition_list.size(); i++) {
        tmp = GetColumnFromCondition(condition_list[i], table_list);
        if (tmp.size() == 2) {
            joincondition_list.push_back(condition_list[i]);
        }
        else if (tmp.size() == 1) {
            selectcondition_list.push_back(condition_list[i]);
        }
        else {
            cout << "ERROR: " << condition_list[i] << endl;
        }
    }
    return selectcondition_list;
}
vector<string> GetJoinConditionList(vector<string> condition_list, vector<string> table_list) {
    vector<string> selectcondition_list;
    vector<string> tmp;
    vector<string> joincondition_list;
    // vector<string> condition_list = GetAllColumnList(sql_statement);
    for (int i = 0; i < condition_list.size(); i++) {
        tmp = GetColumnFromCondition(condition_list[i], table_list);
        if (tmp.size() == 2) {
            joincondition_list.push_back(condition_list[i]);
        }
        else if (tmp.size() == 1) {
            selectcondition_list.push_back(condition_list[i]);
        }
        else {
            cout << "ERROR: " << condition_list[i] << endl;
        }
    }
    return joincondition_list;
}