#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>

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