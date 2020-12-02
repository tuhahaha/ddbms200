cmake_minimum_required(VERSION 3.5.1)

include_directories(curl json)
#生成链接库
add_library(Metadata metadata.cc)
