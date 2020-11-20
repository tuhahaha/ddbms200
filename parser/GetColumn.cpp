#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include"Tools.h"

using namespace std;
/*
GetColumn.cpp is the second step in Parse_SELECT FUNCTION which Get 
- all conditions in a SELECT query
- all columns in a SELECT query
*/

int main() {
    string sql_statement = "SELECT Customer.name,Book.title,Publisher.name,Orders.quantity FROM Customer,Book,Publisher,Orders WHERE Customer.id=Orders.customer_id and Book.id=Orders.book_id and Book.publisher_id=Publisher.id and Customer.id>308000 and Book.copies>100 and Orders.quantity>1 and Publisher.nation='PRC';";
    vector<string> ColumnList = GetAllColumnList(sql_statement);
    vector<string> ConditionList = GetConditionList(sql_statement);
    vector<string> SelectColumnList = GetSelectColumnList(sql_statement);
    return 0;
}
