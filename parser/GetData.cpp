#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include "Tools.h"
using namespace std;

struct Data {
    string column_name;
    string table_name;
    string condition;
    int id;
    int site;
};
struct ConditionAndColumns {
    string condition;
    vector<string> columns;
};
struct CondtionAndColumn {
    string condition;
    string column;
};
struct ColumnAndIdSite {
    string column;
    int id;
    int site;
};
struct DataGroupByTable {
    string table;
    vector<ColumnAndIdSite> columns;
    vector<int> ids;
    vector<int> sites;
};



vector<DataGroupByTable> GetDataGroupByTable(string sql_statement);
vector<string> FirstPi(string sql_statement);

int main(){
    string sql_statement = "SELECT Customer.name,Book.title,Publisher.name,Orders.quantity FROM Customer,Book,Publisher,Orders WHERE Customer.id=Orders.customer_id and Book.id=Orders.book_id and Book.publisher_id=Publisher.id and Customer.id>308000 and Book.copies>100 and Orders.quantity>1 and Publisher.nation='PRC';";
    vector<string> TableList = GetTableList(sql_statement);
    vector<string> ColumnList = GetAllColumnList(sql_statement);
    vector<string> ConditionList = GetConditionList(sql_statement);
    vector<string> SelectColumnList = GetSelectColumnList(sql_statement);
    int id = getTableFragNum(TableList[0]);
    // for (int i = 0; i < ColumnList.size(); i++) {
    //     string column = ColumnList[i];
    //     string table = GetTableFromColumn(column);
    //     cout << GetIdFromTC(table, column) << endl;
    //     cout << GetSiteFromTC(table, column) << endl;
    // }
    vector<DataGroupByTable> data_group_by_Table = GetDataGroupByTable(sql_statement);
    // for (int i = 0; i < ConditionList.size(); i++) {
    //     string condition = ConditionList[i];
    //     vector<string> column_tmp = GetColumnFromCondition(condition, TableList);
    //     for (int j = 0; j < column_tmp.size(); j++) {
            
    //     }
    // }
    return 0;
}


vector<DataGroupByTable> GetDataGroupByTable(string sql_statement) {
    vector<string> TableList = GetTableList(sql_statement);
    vector<string> ColumnList = GetAllColumnList(sql_statement);
    vector<DataGroupByTable> data_group_by_table;
    for (int i = 0 ; i < TableList.size(); i++ ) {
        string table = TableList[i];
        // cout << "Table " << table << endl;
        DataGroupByTable data_group_by_table_tmp;
        data_group_by_table_tmp.table = table;
        vector<ColumnAndIdSite> columns;
        vector<int> ids;
        vector<int> sites;
        for (int j = 0; j < ColumnList.size(); j++) {
            if(GetTableFromColumn(ColumnList[j], TableList) == TableList[i]) {
                ColumnAndIdSite columns_tmp;
                // cout << "   " << ColumnList[j] << endl;
                columns_tmp.column = ColumnList[j];
                // columns_tmp.id = GetIdFromTC(table, ColumnList[j]);
                // columns_tmp.site = GetSiteFromTC(table, ColumnList[j]);
                // ids.push_back(GetIdFromTC(table, ColumnList[j]));
                // sites.push_back(GetSiteFromTC(table, ColumnList[j]));
                // PushBackUnique(ids, GetIdFromTC(table, ColumnList[j]));
                // PushBackUnique(sites, GetSiteFromTC(table, ColumnList[j]));
                columns.push_back(columns_tmp);
            }
        }
        data_group_by_table_tmp.columns = columns;
        data_group_by_table_tmp.ids = ids;
        data_group_by_table_tmp.sites = sites;
        data_group_by_table.push_back(data_group_by_table_tmp);
    }
    return data_group_by_table;
}

vector<string> FirstPi(string sql_statement) {
    vector<string> Command4FirstPi;
    vector<DataGroupByTable> data_group_by_Table = GetDataGroupByTable(sql_statement);
    for (int i = 0; i < data_group_by_Table.size(); i++) {
        for (int j = 0; j < data_group_by_Table[i].columns.size(); j++) {
            int id = data_group_by_Table[i].columns[j].id;
            int site = data_group_by_Table[i].columns[j].site;
        }
    }
    return Command4FirstPi;
}
