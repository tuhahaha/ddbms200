cmake_minimum_required(VERSION 3.5.1)
project(DDBMS)

link_directories(../../metadata ../../executor/cpp)
add_executable(main Parse_LOAD.cpp Tools.cpp)
target_link_libraries(main Executor)
target_link_libraries(main Metadata)