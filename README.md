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
