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

// mysql自己定义了查询结果的结构

// //取自mysql自己定义的查询结果的结构
// typedef struct st_mysql_res {
//   my_ulonglong row_count;                               // 结果集的行数
//   unsigned int field_count, current_field;            // 结果集的列数，当前列
//   MYSQL_FIELD *fields;                                    // 结果集的列信息
//   MYSQL_DATA *data;                                      // 结果集的数据
//   MYSQL_ROWS *data_cursor;                        // 结果集的光标
//   MEM_ROOT field_alloc;                                   // 内存结构
//   MYSQL_ROW row;                                         // 非缓冲的时候用到
//   MYSQL_ROW current_row;                           //mysql_store_result时会用到。当前行
//   unsigned long *lengths;                                //每列的长度
//   MYSQL *handle;                                           // mysql_use_result会用。
//   my_bool eof;                                                 //是否为行尾
// } MYSQL_RES;
// typedef char ** MYSQL_ROW; /* 返回的每一行的值，全部用字符串来表示*/
// typedef struct st_mysql_rows {
//   struct st_mysql_rows *next; /* list of rows */
//   MYSQL_ROW data;
// }  MYSQL_ROWS;        //mysql的数据的链表节点。可见mysql的结果集是链表结构
// typedef struct st_mysql_data {
//   my_ulonglong rows;
//   unsigned int fields;
//   MYSQL_ROWS *data;
//   MEM_ROOT alloc;
// }  MYSQL_DATA; // 数据集的结构
// typedef struct st_mysql_field {
//   char *name;  /* Name of column */
//   char *table;                                            /* Table of column if column was a field */
//   char *def;                                               /* Default value (set by mysql_list_fields) */
//   enum enum_field_types type;                /* Type of field. Se mysql_com.h for types */
//   unsigned int length;                               /* Width of column */
//   unsigned int max_length;                       /* Max width of selected set */
//   unsigned int flags;                                  /* Div flags */
//   unsigned int decimals;                            /* Number of decimals in field */
// }  MYSQL_FIELD;  //列信息的结构
// typedef struct st_used_mem { /* struct for once_alloc */
//   struct st_used_mem *next; /* Next block in use */
//   unsigned int left; /* memory left in block  */
//   unsigned int size; /* Size of block */
// } USED_MEM; //内存结构
// typedef struct st_mem_root {
//   USED_MEM *free;
//   USED_MEM *used;
//   USED_MEM *pre_alloc;
//   unsigned int min_malloc;
//   unsigned int block_size;
//   void (*error_handler)(void);
// } MEM_ROOT;  //内存结构
