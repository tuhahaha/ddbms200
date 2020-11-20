# ddbms200 in 2020

In this repo you can find a demo for a Ditributed DatabBase Managment System. The repo can mainly devided into 3 parts, and each one of the team is responsible to one part of the project.

The three parts are
- metadata (Jianhong Tu)
- parser (Xiaotong Li)
- executor (Yinqing Luo)

## Some details about these three parts

### metadata

### parser

The parser mainly contains 6 functions
- SelectObject Parse_SELECT(string sql_statement);
- InsertObject Parse_INSERT(string sql_statement);
- DeleteObject Parse_DELETE(string sql_statement);
- GDD Parse_CREATE_TABLE(string sql_statement);
- Fragment Parse_CREATE_FRAGMENTATION(string sql_statement);
- LoadObject Parse_LOAD(string sql_statement);

### executor
