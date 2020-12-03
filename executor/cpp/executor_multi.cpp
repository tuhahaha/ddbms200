#include "./executor.h"
// #include <thread>
// #include <future>
// #include <utility>

// /* 这是为了记录每次最多并行多少线程，受到机器最大并行数量的限制，
// 所以实质上应当取max(机器允许的最大并行数量，数据库站点数量)，
// 但事实上后面如果有递归执行，可能会直接超出机器能力，
// 而且直接写在这里也有点笨，size算出来然后在内部申请可以更省空间 */
// #define MAXTHREAD 4
// #include <iostream>
// #include <string>
// #include <vector>
// #include <ctime>
// #include "./mysql_connector.h"
// #include "../../transfer/transfer/transfer.h"

// /* 在每个site实例上部署的时候这个值不同 */
// #define LOCALSITE "s1"


// // 现在定义一下时间和数据传输量记录的结构
// // 也用树结构记录每个节点花费的时间和数据传输量
// struct exec_node{
//     int node_id; // 原来树中该节点对应的ID
//     double time_spend; // 执行对应节点所花的时间，单位为秒
//     int volume; // 该节点上结果的数据量，单位为比特
// };
// struct exec_tree{
//     int tree_id; // 应当与它执行的树的ID一致
//     vector<exec_node> nodes; // 应当与它执行的树的node数量一致
// };


// // string Data_Load_Execute(string create_sql, string load_sql, vector<string> sitenames, vector<string> sqls, vector<string> table_names){
// //     return "x rows imported, y seconds used."
// // }
// // 这里是一条一条给我的？

// /* 本函数用于执行整个load流程，输入本地创建和导入表的SQL语句，本地表的表名，站点列表，
// 分片select语句列表和分片表名列表，返回
// "x1 rows imported on site 1.
//  x2 rows imported on site2.
//  y seconds used."
//  或者"FAIL" */
// string Data_Load_Execute(string create_sql, string load_sql, string main_name, vector<string> sitenames, vector<string> sqls, vector<string> table_names);

// /* for循环内原先的内容被封装为另外一个函数，
// 输入sitenames, sqls, table_names, 输出String - "xx rows imported on site x.\n" 或者 "FAIL on site x.\n" 
// 最后三个参数是为了传递主函数给每个线程的对应变量预留的空间，而不是传递值 */
// void Data_Load_Thread(string site, string frag_sql, string frag_name, std::promise<string> &resultObj);

int main(int argc,char *argv[])
{
    /* id int key, name char(100), nation char(3) */
    string create_sql = "create table publisher(id int(6), name char(100), nation char(3))";
    string load_sql = "load data local infile '/home/roy/ddbms/rawdata/publisher.tsv' into table publisher";
    string main_name = "publisher";
    vector<string> sitenames;
    string site = "s3";
    sitenames.push_back(site);
    site = "s4";
    sitenames.push_back(site);
    site = "s2";
    sitenames.push_back(site);
    vector<string> sqls;
    string sql = "select * from publisher where id < 104000 and nation='PRC'";
    sqls.push_back(sql);
    sql = "select * from publisher where id > 104000 and nation='PRC'";
    sqls.push_back(sql);
    sql = "select * from publisher where id > 104000 and nation='PRC'";
    sqls.push_back(sql);
    vector<string> table_names;
    string table_name = "publisher_3";
    table_names.push_back(table_name);
    table_name = "publisher_4";
    table_names.push_back(table_name);
    table_name = "publisher_2";
    table_names.push_back(table_name);

    string load_output = Data_Load_Execute(create_sql, load_sql, main_name, sitenames, sqls, table_names);
    printf("%s", load_output.data());
    return 0;
}

/* for循环内原先的内容被封装为另外一个函数，
输入sitenames, sqls, table_names, 输出String - "xx rows imported on site x.\n" 或者 "FAIL on site x.\n" */
void Data_Load_Thread(string site, string frag_sql, string frag_name, std::promise<string> &resultObj){
    /* 执行分片语句 */
    string frag_res;
    int row_num;
    string res_output;
    /* 这里固定s1的意思是固定在每台机子的第一个MySQL实例上执行 */
    /* loacl_name和frag_name其实一模一样，所以爱怎么放怎么放，后面直接用frag_name */
    string local_name = Local_Select(frag_sql, frag_name, "s1");
    /* 获得行数，这个函数要出现在LOAD前面，不然会把原来的表删掉 */
    row_num = my_mysql_res_get_rows(frag_name);
    // printf("local_name: %s", local_name);
    /* 在目标site上执行存储语句 */
    /* 判断一下是否为本地，并执行对应存储函数 */
    if(site == LOCALSITE){
        frag_res = Local_Tmp_Load(frag_name, site);
        // printf("localsite.\n%s\n", frag_res.data());
    }
    else if(site == LOCALSITE2){
        frag_res = Local_Tmp_Load(frag_name, site);
    }
    else{
        // printf("not localsite.");
        frag_res = RPC_Local_Tmp_Load(local_name, site);
        // frag_res = Local_Tmp_Load(frag_name, site); // 先这么写着，防止transfer那边的问题
        // printf("success .");
        // printf("%s", frag_res.data());
        // cout << frag_res;
    }
    // frag_res = "OK";
    if(frag_res == "OK"){ /* 目标site上存储成功 */
        /* 构造输出语句 */
        res_output = to_string(row_num);
        res_output.append(" rows imported on site ");
        res_output.append(site);
        res_output.append(".\n");
        
        // printf("%s\n", res_output.data());
        resultObj.set_value(res_output);
        // return res_output;
    }
    else{
        // printf("FAIL TO LOAD %s", frag_name);
        res_output = "FAIL on site ";
        res_output.append(site);
        res_output.append("\n");
        // printf("%s\n", res_output.data());
        resultObj.set_value(res_output);
        // return res_output_2;
    }
}

string Data_Load_Execute(string create_sql, string load_sql, string main_name, vector<string> sitenames, vector<string> sqls, vector<string> table_names){
    /* 将数据存入本地数据库 */
    /* 记录开始时间 */
    time_t start_time = time(NULL);
    int i;
    vector<thread> load_threads;
    vector<std::future<string>> result_objs;
    /* 先在本地创建和导入表 */
    /* 这里固定s1的意思是固定在每台机子的第一个MySQL实例上执行 */
    string local_load_res = local_Load(create_sql, load_sql, "s1");
    if(local_load_res == "OK"){ /* 本地导入表成功 */
        /* 执行分片并存储 */
        /* 这里有两种方式，一是遍历执行，二是并行执行，此处想要完成第二种 */
        /* for循环内原先的内容被封装为另外一个函数，输入sitenames, sqls, table_names, 输出String - "xx rows imported on site x.\n" 或者 "FAIL on site x.\n" */
        // string frag_sql;
        // string frag_name;
        // string site;
        /* 先把空间给申请好 */
        std::promise<string> resultObjs[MAXTHREAD]; 
        std::thread load_threads[MAXTHREAD];
        std::future<string> load_sentences[MAXTHREAD];
        // string frag_res[MAXTHREAD];
        // int row_num[MAXTHREAD];
        // string res_output[MAXTHREAD];

        for(i = 0; i < sitenames.size(); i++){
            // frag_sql = sqls[i];
            // frag_name = table_names[i];
            // site = sitenames[i];            
            /* 开启一个分片并在对应site存储的线程，通过传promise类给线程，让线程把结果给future类，实现结果返回 */
            // std::promise<string> resultObj;
            // std::future<string> resultSen = resultObj.get_future();
            load_sentences[i] = resultObjs[i].get_future();
            load_threads[i] = std::thread(Data_Load_Thread, sitenames[i], sqls[i], table_names[i], std::ref(resultObjs[i]));
            // result_objs.push_back(resultObj.get_future());
        }

        /* 从每个进程中获得返回结果并汇总 */
        vector<string> load_results;
        for(i = 0; i < sitenames.size(); i++){
            // std::future<string> resultSent = result_objs[i];
            string load_sentence = load_sentences[i].get();
            load_results.push_back(load_sentence);
        }

        /* 本意是说所有线程完成了主函数才继续，
        但是可能会造成join了第一个线程，就等，等到第一个线程结束了才会join第二个线程？ 
        似乎效果确实一样 */
        for(i = 0; i < sitenames.size(); i++){
            // std::thread th = load_threads[i];
            load_threads[i].join();
        }

        /* 删除本地存储的表 */
        string drop_sql = "drop table ";
        drop_sql.append(main_name);
        string local_release_res = local_Insert_Delete(drop_sql, "s1");
        if (local_release_res == "FAILED") 
        {   /*现在就代表执行失败了*/
            printf("Error： mysql release error!\n");
        }
        else 
        { 
            /*现在就代表执行成功了*/
        }
        /* 计算所花时间 */
        time_t end_time = time(NULL);
        double time_spend = difftime(end_time, start_time);
        /* 构造输出语句 */
        string time_output = to_string(time_spend);
        time_output.append(" seconds used.\n");
        string output_sentence = "";
        for(i = 0; i < load_results.size(); i++){
            output_sentence.append(load_results[i]);
        }
        output_sentence.append(time_output);
        return output_sentence;
        

    }
    else{
        printf("LOCAL LOAD FAILED!");
        return "FAIL";
    }
}

