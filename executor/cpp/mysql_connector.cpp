#include <stdio.h>
#include <mysql/mysql.h>
#include <string>

using namespace std;

#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "rootroot"
#define DATABASE "test"  // here the name should be changed to our databases

// mysql自己定义了查询结果的结构
// 但是我们的结构最好不要有指针，所以我重新定义为 —— 既然可以有指针，我怀疑这个是否还需要
// #define MAX_COLUMN=10;
// typedef struct my_mysql_res {
//     string global_table;                 // 结果集来源的表名
//     int row_count;                       // 结果集的行数
//     unsigned int field_count;            // 结果集的列数
//     MY_MYSQL_COL col[MAX_COLUMN];        // 结果集的数据，按列存储
// } MY_MYSQL_RES; // 结果集

// typedef struct st_mysql_field {
//     string name;                         // 列名
//     string values;                       // 列值，"\t"分隔
// }  MY_MYSQL_COL; // 结果集的列

// 取自mysql自己定义的查询结果的结构
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


// 目前我自己定义的返回结果的形式
typedef struct my_mysql_res {
    string global_table; // 结果集来源的表名
    MYSQL_RES *res_ptr; /*指向查询结果的指针*/
} MY_MYSQL_RES; // 结果集
	


string local_Insert_Delete(string sql);
string local_Load(string sql_create, string sql_load);
MY_MYSQL_RES query_sql(string sql, string table);
void my_mysql_res_print(MY_MYSQL_RES my_res);
// // 本地执行删除函数
// string localExecuteDelete(string sql_statement){
//     // 输入SQL语句，返回执行结果(OK or FAIL)与所需时间(s)
//     return result;
// }
// // 本地执行查询函数
// string localExecuteQuery(string sql_statement){
//     // 输入SQL语句，返回执行结果(MY_MYSQL_RES结构)与所需时间(s)
//     return result, time_spend;
// } 
// // 本地执行插入函数
// string localInsertFileToTable(string sql_statement){
//     // 输入SQL语句，返回执行结果(OK or FAIL)与所需时间(s)
//     return result, time_spend;
// }
// // 本地执行文件导入函数
// string localLoadFileToTable(string sql_statement){
//     // 输入SQL语句，返回执行结果与所需时间（s）
//     return result, time_spend;
// }
// // 本地执行临时表存储函数
// string localMY_MYSQL_RESToTable(MY_MYSQL_RES tmp_data, string tmp_data_name){
//     // 输入要存入临时表的数据与表名，返回执行结果(OK or FAIL)与所需时间（s）
//     return result, time_spend;
// }



int main(int argc,char *argv[])
{
    string res_str_out;
    // res_str_out = local_Insert_Delete("delete from test where name='user'");
    res_str_out = local_Load("create table book(id int(6), title char(100), authors char(200), publisher_id int(6), copies int(5), key(id) )", "load data local infile '/home/roy/ddbms/rawdata/book.tsv' into table book");
    const char* p = res_str_out.data();
    printf("%s\n", p);
    MY_MYSQL_RES res_data_out = query_sql("select * from book where id<=200005", "book");
    my_mysql_res_print(res_data_out);

    return 0;
}

string local_Insert_Delete(string sql) // 即只返回成功与否的所有sql语句都可以用这个，测试完毕
{
    MYSQL conn;
    int res;
    mysql_init(&conn);
    if(mysql_real_connect(&conn, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL,0))
    {
        printf("connect success!\n");
        const char* p = sql.data(); 
        res=mysql_query(&conn,p);
        mysql_close(&conn);
        if(res)
        {
            // printf("error\n");
            return "FAILED";
        }
        else
        {
            // printf("OK\n");
            return "OK";
        }
        
    }   
}

string local_Load(string sql_create, string sql_load)
{
    MYSQL conn;
    int res;
    int res_load;
    mysql_init(&conn);
    if(mysql_real_connect(&conn, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL,0))
    {
        printf("connect success!\n");
        const char* p = sql_create.data(); 
        res=mysql_query(&conn,p);
        if(res) /*创建数据表失败*/
        {
            // printf("error\n");
            mysql_close(&conn);
            return "FAILED";
        }
        else /*创建数据表成功*/
        {
            // printf("OK\n");
            p = sql_load.data();
            res_load = mysql_query(&conn,p);
            mysql_close(&conn);
            if(res_load) /*导入数据失败*/
            {
                return "FAILED";
            }
            else{
                return "OK";
            }
            
        }
        
    }       
}

MY_MYSQL_RES query_sql(string sql, string table) 
{
    MYSQL my_connection; /*这是一个数据库连接*/
    int res; /*执行sql語句后的返回标志*/
    MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    MYSQL_FIELD *field; /*字段结构指针*/
    MYSQL_ROW result_row; /*按行返回的查询信息*/
    MY_MYSQL_RES my_res; /*需要返回的查询结果*/

    int row, column; /*查询返回的行数和列数*/
    int i, j; /*只是控制循环的两个变量*/
 
    /*初始化mysql连接my_connection*/
    mysql_init(&my_connection);

    /*这里就是用了mysql.h里的一个函数，用我们之前定义的那些宏建立mysql连接，并
     *     返回一个值，返回不为空证明连接是成功的*/
    if (mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL, 0)) 
    {
        /*连接成功*/
        printf("数据库查询query_sql连接成功！\n");
        /*这句话是设置查询编码为utf8，这样支持中文*/
        mysql_query(&my_connection, "set names utf8");
    
        /*下面这句话就是用mysql_query函数来执行我们刚刚传入的sql語句，
         *         这会返回一个int值，如果为0，证明語句执行成功*/
        const char* p = sql.data();
        res = mysql_query(&my_connection, p);
    
        if (res) 
        {   /*现在就代表执行失败了*/
            printf("Error： mysql_query !\n");
            my_res.global_table = "Error";  // 将表名置为Error
        }
        else 
        { 
            /*现在就代表执行成功了*/
            /*将查询的結果给res_ptr*/
            res_ptr = mysql_store_result(&my_connection);
            /*如果结果不为空，就把结果返回*/
            if (res_ptr)
            {
                my_res.global_table = table;
                my_res.res_ptr = res_ptr;
            }
            /* 如果结果为空，就把table名字置为empty*/
            else
            {
                my_res.global_table = "Empty";
            }
        /*不要忘了关闭连接*/  
        mysql_close(&my_connection);
        return my_res;
        }             
    }  
}

void my_mysql_res_print(MY_MYSQL_RES my_res)
{
    MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    res_ptr = my_res.res_ptr;
    MYSQL_FIELD *field; /*字段结构指针*/
    MYSQL_ROW result_row; /*按行返回的查询信息*/

    int row, column; /*查询返回的行数和列数*/
    int i, j; /*只是控制循环的两个变量*/

    /*如果结果不为空，就把结果print*/
    if (res_ptr) 
    {
        /*取得結果的行列数*/
        column = mysql_num_fields(res_ptr);
        row = mysql_num_rows(res_ptr);
        printf("查询到 %d 行 \n", row);

        /*输出結果的字段名*/
        for (i = 0; field = mysql_fetch_field(res_ptr); i++)
        {
            printf("%s\t", field->name);
        }
            
        printf("\n");

        /*按行输出結果*/
        for (i = 1; i < row; i++)
        {
            result_row = mysql_fetch_row(res_ptr);
            for (j = 0; j < column; j++)
            {
                printf("%s\t", result_row[j]);
            }
            printf("\n"); 
    
        }
    }
    else
    {
        printf("Empty!");
    }
    
}
