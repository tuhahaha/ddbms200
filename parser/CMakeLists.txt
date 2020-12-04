cmake_minimum_required(VERSION 3.5.1)
project(DDBMS)

add_executable(main Parse_LOAD.cpp Tools.cpp)
target_link_libraries(main Executor)
target_include_directories(main PUBLIC ../../executor/cpp)
target_link_libraries(main Metadata)
target_include_directories(main PUBLIC ../../metadata)