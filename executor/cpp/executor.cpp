#include <iostream>
#include <sting>
#include <vector>

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

