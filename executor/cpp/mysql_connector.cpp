#include <stdio.h>
#include <mysql/mysql.h>
#include <string>
#include <vector>
#include <typeinfo> /* 为了调试 */
#include "../../matadata/metadata.h"

using namespace std;

#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "rootroot"
#define DATABASE "test"  // here the name should be changed to our databases


// // 元信息结构定义
// #define MAX_COLUMN 10
// typedef struct ColumnDef {
//     string name;
//     string type;
//     bool null;
//     bool key;
//     string desc;
// } ColumnDef;
// typedef struct GDD {
//     string name; /*表名*/
//     ColumnDef col[MAX_COLUMN];
// } GDD;

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
MY_MYSQL_RES Local_Select(string sql, string table);
string Local_Tmp_Load(MY_MYSQL_RES tmp_data, string tmp_data_name);
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

/* 先固定一个元信息实例 */
ColumnDef field1;
ColumnDef field2;
ColumnDef field3;
ColumnDef field4;
ColumnDef field5;
GDD book_meta;


int main(int argc,char *argv[])
{
    /* 先固定一个元信息实例 */
    field1.name = "id";
    field1.type = "int(6)";
    field1.key = true;
    field2.name = "title";
    field2.type = "char(100)";
    field3.name = "authors";
    field3.type = "char(200)";
    field4.name = "publisher_id";
    field4.type = "int(6)";
    field5.name = "copies";
    field5.type = "int(5)";
    book_meta.cols[0] = field1;
    book_meta.cols[1] = field2;
    book_meta.cols[2] = field3;
    book_meta.cols[3] = field4;
    book_meta.cols[4] = field5;
    book_meta.name = "book";
    // book_meta.col = col;
 
    // string res_str_out;
    // res_str_out = local_Insert_Delete("delete from test where name='user'");
    // insert into test values('user','123456')
    // res_str_out = local_Insert_Delete("insert into test values('user','123456')");
    // res_str_out = local_Load("create table book(id int(6), title char(100), authors char(200), publisher_id int(6), copies int(5), key(id) )", "load data local infile '/home/roy/ddbms/rawdata/book.tsv' into table book");
    // const char* p = res_str_out.data();
    // printf("%s\n", p);
    /* 存成临时表 */
    MY_MYSQL_RES res_data_out = Local_Select("select * from book where id<=200005", "book");
    string res_tmp_out = Local_Tmp_Load(res_data_out, "tmp_table_1");
    const char* p = res_tmp_out.data();
    printf("tmp table stored: %s\n", p);
    /* 把临时表查出来并且打印 */
    res_data_out = Local_Select("select * from tmp_table_1", "book");
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

string Local_Tmp_Load(MY_MYSQL_RES tmp_data, string tmp_data_name)
{
    MYSQL conn;
    int res;
    int res_load;
    /* 接下来本应从etcd读取元信息，但调试阶段我把元信息写死在代码里了，即全局变量book_meta*/
    /* 现在开始构建create语句的sql，这一部分之后应该会拆分出来成为单独的函数，输入是一堆GDD和MY_MYSQL_RES，输出是create的sql语句*/
    int i, j, flag; /*只是控制循环的两个变量和一个标记变量*/
    string sql_create = "create table ";
    sql_create = sql_create.append(tmp_data_name);
    sql_create = sql_create.append("(");
    MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    res_ptr = tmp_data.res_ptr;
    int row, column; /*查询返回的行数和列数*/
    MYSQL_FIELD *fields; /*字段结构数组的指针*/
    column = mysql_num_fields(res_ptr);
    fields = mysql_fetch_fields(res_ptr);
    /* 遍历结果集中的字段名 */
    for(i = 0; i < column; i++)
    {
        flag = 0;
        sql_create = sql_create.append(fields[i].name); //id
        sql_create = sql_create.append(" ");
        for(j = 0; j < MAX_COLUMN; j++)
        {
            /* 从元信息中找出对应的类型定义 */
            string target_name = fields[i].name;
            string source_name = book_meta.col[j].name;
            if(target_name == source_name){
                sql_create = sql_create.append(book_meta.col[j].type); //int(6)
                sql_create = sql_create.append(", ");
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            mysql_close(&conn);
            return "Fields error!";
        }
    }
    sql_create = sql_create.substr(0,sql_create.length()-2); //删掉最后一个", "
    sql_create = sql_create.append(")");
    /* create语句构造完毕 */
    mysql_init(&conn);
    if(mysql_real_connect(&conn, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL,0))
    {
        printf("connect success!\n");        
        const char* p = sql_create.data();
        res=mysql_query(&conn,p);
        if(res) /*创建数据表失败*/
        {
            mysql_close(&conn);
            return "FAILED";
        }
        else /*创建数据表成功*/
        {
            /* 开始一条一条存数据, e.g. insert into test values('user', '123456')*/
            /*取得結果的行列数*/
            column = mysql_num_fields(res_ptr);
            row = mysql_num_rows(res_ptr);
            MYSQL_ROW result_row; /*按行返回的查询信息*/
            /*按行插入結果*/
            for (i = 1; i < row; i++)
            {
                /* 开始构造insert语句 */
                string sql_load = "insert into ";
                sql_load = sql_load.append(tmp_data_name);
                sql_load = sql_load.append(" values(\'");
                result_row = mysql_fetch_row(res_ptr);
                for (j = 0; j < column; j++)
                {
                    sql_load = sql_load.append(result_row[j]);
                    sql_load = sql_load.append("\', \'");
                }
                sql_load = sql_load.substr(0,sql_load.length()-3); //删掉最后一个", \'"
                sql_load = sql_load.append(")");
                /* insert语句构造完毕 */
                p = sql_load.data();
                res_load = mysql_query(&conn,p);
                if(res_load) /*导入数据失败*/
                {
                    mysql_close(&conn);
                    return "FAILED";
                }
                else{
                    continue;
                }   
            }
            mysql_close(&conn);
            /* 如果全部成功插入 */
            if(i == row){
                return "OK";
            }
            else{
                return "FAILED";
            }
            
        }
        
    }           

}

MY_MYSQL_RES Local_Select(string sql, string table) 
{
    MYSQL my_connection; /*这是一个数据库连接*/
    int res; /*执行sql語句后的返回标志*/
    MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    // MYSQL_FIELD *field; /*字段结构指针*/
    // MYSQL_ROW result_row; /*按行返回的查询信息*/
    MY_MYSQL_RES my_res; /*需要返回的查询结果*/

    // int row, column; /*查询返回的行数和列数*/
    // int i, j; /*只是控制循环的两个变量*/
 
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
    mysql_free_result(res_ptr);
}

/* res_ptr = mysql_store_result(&my_connection)用于分配内存并把指针返回
   mysql_free_result(res_ptr)则用于释放被分配的内存
   一般来说子站点返回结果集之后就应当释放，但不知道RPC如何反应，
   我暂且先写在executor的transfer后面吧，加上注释，一开始的测试通过以后再尝试取消注释能不能继续跑通*/
/* mysql_library_end()用于彻底释放，按理来说mysql_free_result如果有，这个也应当有，
   但是它并不指定是哪一个连接，我觉得多线程的时候有些危险，所以不打算放上去*/
