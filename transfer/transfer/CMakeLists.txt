cmake_minimum_required(VERSION 3.5.1)

#生成链接库
add_library(Client client.cc)
target_link_libraries(Client transfer.pb.o transfer.grpc.pb.o)


