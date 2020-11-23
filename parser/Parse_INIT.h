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
