#include "Tools.h"

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
void TraverseFragment(Fragment frags);
Fragment InitGetFragmentCreateFragment(string sql_statement);
