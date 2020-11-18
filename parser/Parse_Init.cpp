#include"Tools.h"
#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

// string InitGetTable(string sql_statement);

int main() {
    string sql_statement = "CREATE TABLE Pulisher (id int key,name string,nation string);";
    cout << sql_statement << endl;
    string table = GetAfter(sql_statement, "CREATE TABLE ");
    cout << table << endl;
    return 0;
}
// string InitGetTable(string sql_statement) {
//     string table;
//     table = GetBetween(sql_statement, "CREATE TABLE ",  "(");
//     return table;
// }