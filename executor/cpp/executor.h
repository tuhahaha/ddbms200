#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "./mysql_connector.h"
#include "../../transfer/transfer/transfer.h"

/* 在每个site实例上部署的时候这个值不同 */
#define LOCALSITE "s3"
#define LOCALSITE2 "s4"


// 现在定义一下时间和数据传输量记录的结构
// 也用树结构记录每个节点花费的时间和数据传输量
struct exec_node{
    int node_id; // 原来树中该节点对应的ID
    double time_spend; // 执行对应节点所花的时间，单位为秒
    int volume; // 该节点上结果的数据量，单位为比特
};
struct exec_tree{
    int tree_id; // 应当与它执行的树的ID一致
    vector<exec_node> nodes; // 应当与它执行的树的node数量一致
};


// string Data_Load_Execute(string create_sql, string load_sql, vector<string> sitenames, vector<string> sqls, vector<string> table_names){
//     return "x rows imported, y seconds used."
// }
// 这里是一条一条给我的？

/* 本函数用于执行整个load流程，输入本地创建和导入表的SQL语句，本地表的表名，站点列表，
分片select语句列表和分片表名列表，返回
"x1 rows imported on site 1.
 x2 rows imported on site2.
 y seconds used."
 或者"FAIL" */
string Data_Load_Execute(string create_sql, string load_sql, string main_name, vector<string> sitenames, vector<string> sqls, vector<string> table_names);
