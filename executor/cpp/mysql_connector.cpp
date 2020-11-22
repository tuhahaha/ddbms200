// #include <stdio.h>
// #include <mysql/mysql.h>
// #include <string>
// #include <vector>
// #include <typeinfo> /* 为了调试 */
// #include "../../metadata/metadata.h"
#include "./mysql_connector.h"

// using namespace std;

// #define HOST "localhost"
// #define USERNAME "root"
// #define PASSWORD "rootroot"
// #define DATABASE "test"  // here the name should be changed to our databases
// #define PORT 7654  // here the site1, it can be changed to 7655 for site2
// #define UNIX_SOCKET "/home/mysql1/mysql.sock" // here the site1, later can be changed to "home/mysql2/mysql.sock" for site2





// 目前我自己定义的返回结果的形式
// typedef struct my_mysql_res {
//     vector<string> global_tables; /* 结果集来源的表名 */
//     MYSQL_RES *res_ptr; /*指向查询结果的指针*/
// } MY_MYSQL_RES; /* 结果集 */
	

// /* 本地执行插入和删除函数，输入SQL语句，返回执行结果(OK or FAIL) */
// string local_Insert_Delete(string sql);

// /* 本地执行文件导入函数，输入创建表的SQL语句和导入文件的SQL语句，返回执行结果(OK or FAIL)
//    例子：以Book表为例
//    local_Load("create table book(id int(6), title char(100), authors char(200), publisher_id int(6), copies int(5), key(id) )", "load data local infile '/home/roy/ddbms/rawdata/book.tsv' into table book"); */
// string local_Load(string sql_create, string sql_load);

// /* 本地执行查询函数，输入SQL语句，和返回结果集所来源的一组全局表名，返回执行结果(MY_MYSQL_RES结构) */
// MY_MYSQL_RES Local_Select(string sql, vector<string> tables);

// /* 本地执行临时表存储函数，输入待存的数据(MY_MYSQL_RES结构)和临时表表名，返回执行结果(OK or FAIL) */
// string Local_Tmp_Load(MY_MYSQL_RES tmp_data, string tmp_data_name);

// /* 打印MY_MYSQL_RES结构的数据
//    输出样例为：
// 查询到 2 行 
// id      title   authors publisher_id    copies
// 200001  Book #200001    H. Johnston     100366  7231
// 200002  Book #200002    L. Houghton     101543  694 */
// void my_mysql_res_print(MY_MYSQL_RES my_res);


// int main(int argc,char *argv[])
// {
//     // string res_str_out;
//     // res_str_out = local_Insert_Delete("delete from test where name='user'");
//     // insert into test values('user','123456')
//     // res_str_out = local_Insert_Delete("insert into test values('user','123456')");
//     // res_str_out = local_Load("create table book(id int(6), title char(100), authors char(200), publisher_id int(6), copies int(5), key(id) )", "load data local infile '/home/roy/ddbms/rawdata/book.tsv' into table book");
//     // const char* p = res_str_out.data();
//     // printf("%s\n", p);
//     /* 存成临时表 */
//     // vector<string> tables = {"Book"};
//     // MY_MYSQL_RES res_data_out = Local_Select("select * from book where id<=200005", tables);
//     // string res_tmp_out = Local_Tmp_Load(res_data_out, "tmp_table_1");
//     // const char* p = res_tmp_out.data();
//     // printf("tmp table stored: %s\n", p);
//     /* 把临时表查出来并且打印 */
//     vector<string> tablenames;
//     tablenames.push_back("Book");
//     MY_MYSQL_RES res_data_out;
//     res_data_out = Local_Select("select * from tmp_table_1", tablenames, "s3");
//     my_mysql_res_print(res_data_out);

//     return 0;
// }

string local_Insert_Delete(string sql, string site) // 即只返回成功与否的所有sql语句都可以用这个，测试完毕
{
    MYSQL conn;
    int res;

    int PORT;
    const char* UNIX_SOCKET;

    /* 通过站点名称判断使用哪个连接 */
    if(site == "s4"){
        PORT = 7655;
        UNIX_SOCKET = "/home/mysql2/mysql.sock";
    }
    else{
        PORT = 7654;
        UNIX_SOCKET = "/home/mysql1/mysql.sock";
    } // 此处如果输入了没出现过的站点应当报警但我没写

    mysql_init(&conn);
    if(mysql_real_connect(&conn, HOST, USERNAME, PASSWORD, DATABASE, PORT, UNIX_SOCKET,0))
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

string local_Load(string sql_create, string sql_load, string site)
{
    MYSQL conn;
    int res;
    int res_load;

    int PORT;
    const char* UNIX_SOCKET;

    /* 通过站点名称判断使用哪个连接 */
    if(site == "s4"){
        PORT = 7655;
        UNIX_SOCKET = "/home/mysql2/mysql.sock";
    }
    else{
        PORT = 7654;
        UNIX_SOCKET = "/home/mysql1/mysql.sock";
    } // 此处如果输入了没出现过的站点应当报警但我没写

    mysql_init(&conn);
    if(mysql_real_connect(&conn, HOST, USERNAME, PASSWORD, DATABASE, PORT, UNIX_SOCKET,0))
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

string Local_Tmp_Load(MY_MYSQL_RES tmp_data, string tmp_data_name, string site)
{
    MYSQL conn;
    int res;
    int res_load;
    /* 接下来从etcd读取GDD格式的元信息*/
    vector<string> table_names = tmp_data.global_tables;
    // printf("tablename is %s\n", table_name.data());
    vector<GDD> table_metas;
    for (int i = 0; i < table_names.size(); i++){
        string table_name = table_names[i];
        GDD book_meta = getTableFromEtcd(table_name);
        table_metas.push_back(book_meta);
    }
    // printf("GDD Name is %s\n", book_meta.name.data());
    /* 现在开始构建create语句的sql，这一部分之后应该会拆分出来成为单独的函数，输入是vector<GDD>和MY_MYSQL_RES，输出是create的sql语句*/
    /* 我们内部的每个属性名字是唯一的，所以可以全局遍历来匹配 */
    int i, j, k, flag; /*只是控制循环的三个变量和一个标记变量*/
    string sql_create = "create table ";
    sql_create = sql_create.append(tmp_data_name);
    sql_create = sql_create.append("(");
    MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    res_ptr = tmp_data.res_ptr;
    int row, column; /*查询返回的行数和列数*/
    MYSQL_FIELD *fields; /*字段结构数组的指针*/
    int max_GDD; /* 数据所来源的全局表数量 */
    GDD book_meta; /* 循环时候用到的单个GDD变量 */
    int max_num; /* 单个GDD里面列的数量 */
    string target_name; /* 待匹配的目标列名，来自于数据 */
    string source_name; /* 元信息中的列名，来自于GDD */


    column = mysql_num_fields(res_ptr);
    fields = mysql_fetch_fields(res_ptr);
    /* 遍历结果集中的字段名 */
    for(i = 0; i < column; i++)
    {
        flag = 0;
        sql_create = sql_create.append(fields[i].name); //id
        sql_create = sql_create.append(" ");
        /* 遍历所有GDD格式的元信息 */
        max_GDD = table_metas.size();
        for(k = 0; k < max_GDD; k++){
            book_meta = table_metas[k];
            /* 在每个GDD里面遍历列名进行匹配 */
            max_num = book_meta.cols.size();
            for(j = 0; j < max_num; j++)
            {
                /* 从元信息中找出对应的类型定义 */
                target_name = fields[i].name;
                source_name = book_meta.cols[j].name;
                if(target_name == source_name){
                    sql_create = sql_create.append(book_meta.cols[j].type); //int(6)
                    sql_create = sql_create.append(", ");
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
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
    // printf("creat sentence is %s", sql_create.data());
    /* create语句构造完毕 */

    int PORT;
    const char* UNIX_SOCKET;

    /* 通过站点名称判断使用哪个连接 */
    if(site == "s4"){
        PORT = 7655;
        UNIX_SOCKET = "/home/mysql2/mysql.sock";
    }
    else{
        PORT = 7654;
        UNIX_SOCKET = "/home/mysql1/mysql.sock";
    } // 此处如果输入了没出现过的站点应当报警但我没写

    mysql_init(&conn);
    if(mysql_real_connect(&conn, HOST, USERNAME, PASSWORD, DATABASE, PORT, UNIX_SOCKET,0))
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

MY_MYSQL_RES Local_Select(string sql, vector<string> tables, string site) 
{
    MYSQL my_connection; /*这是一个数据库连接*/
    int res; /*执行sql語句后的返回标志*/
    MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    // MYSQL_FIELD *field; /*字段结构指针*/
    // MYSQL_ROW result_row; /*按行返回的查询信息*/
    MY_MYSQL_RES my_res; /*需要返回的查询结果*/

    // int row, column; /*查询返回的行数和列数*/
    // int i, j; /*只是控制循环的两个变量*/

    int PORT;
    const char* UNIX_SOCKET;

    /* 通过站点名称判断使用哪个连接 */
    if(site == "s4"){
        PORT = 7655;
        UNIX_SOCKET = "/home/mysql2/mysql.sock";
    }
    else{
        PORT = 7654;
        UNIX_SOCKET = "/home/mysql1/mysql.sock";
    } // 此处如果输入了没出现过的站点应当报警但我没写
 
    /*初始化mysql连接my_connection*/
    mysql_init(&my_connection);

    /*这里就是用了mysql.h里的一个函数，用我们之前定义的那些宏建立mysql连接，并
     *     返回一个值，返回不为空证明连接是成功的*/
    if (mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD, DATABASE, PORT, UNIX_SOCKET, 0)) 
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
            // my_res.global_tables = "Error";  // 将表名保留为空
        }
        else 
        { 
            /*现在就代表执行成功了*/
            /*将查询的結果给res_ptr*/
            res_ptr = mysql_store_result(&my_connection);
            /*如果结果不为空，就把结果返回*/
            if (res_ptr)
            {
                my_res.global_tables = tables;
                my_res.res_ptr = res_ptr;
            }
            /* 如果结果为空，就把table名字置为empty */
            else
            {
                vector<string> empty = {"Empty"};
                my_res.global_tables = empty;  // 将表名列表第一位置为"Empty"
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
        for (i = 1; i <= row; i++)
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
