cmake_minimum_required(VERSION 3.5.1)

include_directories(mysql)

link_directories(../../transfer/transfer)
#生成链接库
add_library(Mysql_connector mysql_connector.cpp)


add_library(Executor executor.cpp)
target_link_libraries(Executor Client Mysql_connector)

