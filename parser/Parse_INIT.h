#include "iostream"
#include <stdio.h>
#include <vector>
#include <string>
#include "Tools.h"
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

void TraverseGDD(GDD gdd) {
    cout << "TABLE NAME : " << gdd.name << endl;
    cout << "THE SIZE OF GDD.COLS IS " << gdd.cols.size() << endl;
    for (int i = 0; i < gdd.cols.size(); i++) {
        cout << "   " << gdd.cols[i].name << endl;
        cout << "   " << gdd.cols[i].type << endl;
        cout << "   " << gdd.cols[i].key << endl;
    }
}
