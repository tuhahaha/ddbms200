#include "Tools.h"
#include "../metadata/metadata.h"
/*
The parser mainly contains 6 functions
SelectObject Parse_SELECT(string sql_statement);
InsertObject Parse_INSERT(string sql_statement);
DeleteObject Parse_DELETE(string sql_statement);
GDD Parse_CREATE_TABLE(string sql_statement);
Fragment Parse_CREATE_FRAGMENTATION(string sql_statement);
LoadObject Parse_LOAD(string sql_statement);
*/

SelectObject Parse_SELECT(string sql_statement);
InsertObject Parse_INSERT(string sql_statement);
DeleteObject Parse_DELETE(string sql_statement);
GDD Parse_CREATE_TABLE(string sql_statement);
Fragment Parse_CREATE_FRAGMENTATION(string sql_statement);
LoadObject Parse_LOAD(string sql_statement);

SelectObject Parse_SELECT(string sql_statement) {
    
}
InsertObject Parse_INSERT(string sql_statement);
DeleteObject Parse_DELETE(string sql_statement);
GDD Parse_CREATE_TABLE(string sql_statement) {
    GDD gdd;
    gdd.name = InitGetTableCreateTable(sql_statement);
    gdd.cols = InitGetColumnsCreateTable(sql_statement);
    return gdd;
}
Fragment Parse_CREATE_FRAGMENTATION(string sql_statement);
LoadObject Parse_LOAD(string sql_statement);