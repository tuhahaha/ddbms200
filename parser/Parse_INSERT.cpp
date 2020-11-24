#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include"Tools.h"
#include"../metadata/metadata.h"

using namespace std;
bool JudgeFragement(vector<string> condition_list, vector<string> field_list, vector<string> value_list);

int main() {
    string sql_statement = "INSERT INTO TABLE Publisher( field1,field2) VALUES (value1, value2);";
    string table_name = GetBetween(sql_statement, "TABLE","(");
    cout << table_name << endl;
    string column_name = GetBetween(sql_statement, "(", ")");
    vector<string> column_list = GetList(column_name,",",";");
    Traverse(column_list);
    Fragment fragment = getFragFromEtcd(table_name);
    // string type = fragment.fragtype;
    string type = "H";
    vector<FragDef> frags = fragment.frags;
    if (type == "H"){
        for (int i = 0; i < frags.size(); i++){
            string frag_column = frags[i].column;
            vector<string> frag_column_list = GetList(frag_column,",",";");
            string condition = frags[i].condition;
            vector<string> condition_list = GetList(condition, ",",";");
            Traverse(condition_list);
            
        }
    }
    else if (type == "V") {

    }
    else {
        cout << "ERROR: INVALID FRAGMENT TYPE!" << endl;
    }
    return 0;
}

bool JudgeFragement(vector<string> condition_list, vector<string> field_list, vector<string> value_list) {
    vector<string> fv_list;
    if (field_list.size() != value_list.size()) {
        cout << "ERROR: FIELD_LIST SIZE NOT EQUAL TO VALUE_LIST ISZE" << endl;
        return false;
    }
    for (int j = 0; j < field_list.size(); j++) {
        fv_list.push_back(field_list[j]+"="+value_list[j]);
    }
    for (int i = 0; i < condition_list.size(); i++) {
        string column_condition;
        string relation;
        int value_condition;
        if (condition_list[i].find(">") != -1) {
            column_condition = GetList(condition_list[i], ">",";")[0];
            relation = ">";
            value_condition = GetList(condition_list[i], ">",";")[1];
        }
        else if (condition_list[i].find("<") != -1){
            column_condition = GetList(condition_list[i], "<",";")[0];
            relation = "<";
            value_condition = GetList(condition_list[i], "<",";")[1];
        }
        else if (condition_list[i].find("=") != -1) {
            column_condition = GetList(condition_list[i], "=",";")[0];
            relation = "=";
            value_condition = GetList(condition_list[i], "=",";")[1];

        }
        else {
            cout << "ERROR: INVALID CONDITION" << endl;
        }
        for (int j = 0; j < field_list.size(); j++) {
            
        }
    }
}