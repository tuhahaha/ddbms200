#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

string GetBetween(string sql_statement, string start, string end);
string GetAfter(string sql_statement, string start);
vector<string> GetList(string line, string split, string stop);
void Traverse(vector<string> input);
string GetTableName(string sql_statement);
vector<string> GetTableList(string TableName);
string GetSelectColumnName(string sql_statement);
vector<string> GetSelectColumnList(string sql_statement);
string GetCondition(string sql_statement);
string GetTableFromColumn(string column);
vector<string> GetColumnFromCondition(string condtion, vector<string> TableList);
vector<string> GetColumnListFromConditionList(vector<string> ConditionList, vector<string> TableList);
vector<string> GetAllColumnList(string sql_statement);

string GetBetween(string sql_statement, string start, string end) {
    int start_loc = sql_statement.find(start) + start.size() + 1;
    int end_loc = sql_statement.find(end);
    return sql_statement.substr(start_loc, end_loc-start_loc);
}
string GetAfter(string sql_statement, string start) {
    int start_loc = sql_statement.find(start) + start.size() + 1;
    int end_loc = sql_statement.size();
    return sql_statement.substr(start_loc, end_loc-start_loc);
}
vector<string> GetList(string Line, string split, string stop) {
    vector <string> TableList;
    int loc_start = 0;
    int loc_end;
    int size = Line.size();
    int cnt = 0;
    while (size > 0) {
        loc_end = Line.find(split);
        int loc_table_end = loc_end + split.size();
        if (loc_end == -1) {
            string item = Line;
            item = item.substr(0,item.find(stop)-stop.size()+1);
            TableList.push_back(item);
            break;
        }
        else {
            string item = Line.substr(0,loc_end);
            TableList.push_back(item);
            size = size - loc_table_end;
            Line = Line.substr(loc_table_end,size);
        }       
    }
    return TableList;
}
void Traverse(vector<string> input) {
    int size = input.size();
    for (int i = 0; i < size; i++) {
        cout << input[i] << endl;
    }
}
string GetTableName(string sql_statement) {
    return GetBetween(sql_statement, "FROM", "WHERE");
}
vector<string> GetTableList(string sql_statement) {
    return GetList(GetTableName(sql_statement),","," ");
}
string GetSelectColumnName(string sql_statement) {
    return GetBetween(sql_statement, "SELECT", "FROM");
}
vector<string> GetSelectColumnList(string sql_statement) {
    return GetList(GetSelectColumnName(sql_statement),","," ");
}
string GetCondition(string sql_statement) {
    return GetAfter(sql_statement,"WHERE");
}
vector<string> GetConditionList(string sql_statement) {
    return GetList(GetCondition(sql_statement),"and ",";");
}
string GetTableFromColumn(string column, vector<string> TableList) {
    int size = TableList.size();
    for (int i = 0; i < size; i++) {
        if (column.find(TableList[i]) != -1){
            return TableList[i];
        }
    }
    return "GetTableFromColumn ERROR!";
}
vector<string> GetColumnFromCondition(string condition, vector<string> TableList) {
    vector<string> items;
    vector<string> column_list;
    if (condition.find('=') != -1) {
        items = GetList(condition,"="," ");
    }
    else if (condition.find('>') != -1) {
        items = GetList(condition,">"," ");
    }
    else if (condition.find('<') != -1) {
        items = GetList(condition,"<"," ");
    }
    else if (condition.find(">=") != -1) {
        items = GetList(condition, ">="," ");
    }
    else if (condition.find("<=") != -1) {
        items = GetList(condition, "<=", " ");
    }
    else {
        cout << "GetColumnFromCondition ERROR" << endl;
        return items;
    }
    for (int i = 0; i < items.size(); i++) {
        if(GetTableFromColumn(items[i], TableList) != "GetTableFromColumn ERROR!") {
            column_list.push_back(items[i]);
        }
    }
    return column_list;
}
vector<string> GetColumnListFromConditionList(vector<string> ConditionList, vector<string> TableList) {
    vector<string> ColumnList;
    for(int i = 0; i < ConditionList.size(); i++) {
        vector<string> tmp = GetColumnFromCondition(ConditionList[i], TableList);
        ColumnList.insert(ColumnList.end(), tmp.begin(), tmp.end());
    }
    return ColumnList;
}
vector<string> GetAllColumnList(string sql_statement) {
    vector<string> select_column_list = GetSelectColumnList(sql_statement);
    vector<string> condition_list = GetConditionList(sql_statement);
    vector<string> column_list = GetColumnListFromConditionList(condition_list, GetTableList(sql_statement));
    column_list.insert(column_list.end(),select_column_list.begin(),select_column_list.end());
    return column_list;
}