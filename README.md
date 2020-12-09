# 执行流程
- 1，启动etcd集群（可能需要修改ip   client.cc,set_etcd.sh）

- 2，启动mysql
-   cd /home/mysql1
-   ./bin/mysqld --defaults-file=/etc/my1.cnf  --user=mysql --basedir=/home/mysql1 --datadir=/home/mysql1/data
-   mysql -u root -S /home/mysql1/mysql.sock -p

- 3，编译grpc server，在transfer/transfer 下
-   make
-   ./server

- 4，编译main函数，在parser下
-   make
-   ./main 

-   或者用命令：
-   g++ Parse.o Parse_INIT.o Parse_LOAD.o Parse_SELECT.o Tools.o ../executor/cpp/executor_multi.o ../executor/cpp/mysql_connector.o ../transfer/transfer/transfer.pb.o ../transfer/transfer/transfer.grpc.pb.o ../transfer/transfer/client.o ../metadata/metadata.o -o main `pkg-config --cflags protobuf grpc` `pkg-config --libs protobuf grpc++` `mysql_config --cflags --libs` -ljson -lcurl

-   如果需要测试executor，在executor/cpp下
-   g++ -c executor_multi.cpp -pthread -std=c++11
-   g++ -c mysql_connector.cpp
-   g++ executor_multi.o mysql_connector.o ../../transfer/transfer/transfer.pb.o ../../transfer/transfer/transfer.grpc.pb.o ../../transfer/transfer/client.o -o mm `pkg-config --cflags protobuf grpc` `pkg-config --libs protobuf grpc++` `mysql_config --cflags --libs`


- mysql导出数据权限问题
-   https://blog.csdn.net/weixin_44595372/article/details/88723191


















# ddbms200 in 2020

In this repo you can find a demo for a Ditributed DatabBase Managment System. The repo can mainly devided into 4 parts.

The 4 parts are
- metadata (Jianhong Tu)
- transfer (Jianhong Tu)
- parser (Xiaotong Li)
- executor (Yinqing Luo)

## Some details about these 4 parts

### metadata
- ETCD to manage metadata
- cluster: 4 sites

### metadata
- gRPC to transfer object/data

### parser

The parser mainly contains 6 functions
- SelectObject Parse_SELECT(string sql_statement);
- InsertObject Parse_INSERT(string sql_statement);
- DeleteObject Parse_DELETE(string sql_statement);
- GDD Parse_CREATE_TABLE(string sql_statement);
- Fragment Parse_CREATE_FRAGMENTATION(string sql_statement);
- LoadObject Parse_LOAD(string sql_statement);

### executor



# 从parse入口编译运行整个项目
## transfer/transfer/下运行（先利用现成的makefile生成grpc需要的链接库）：
- make
- ./server 50051

## parser/build下运行（利用CMakeLists将所有可执行文件链接起来）：
- cmake ..
- make -j
- ./main

## 函数调用关系
