<!-- 先在executor目录下编译executor生成.o文件 -->
g++ -c mysql_connector.cpp `mysql_config --cflags --libs` ../../metadata/metadata.cc -lcurl -ljson

<!-- 在该目录下 生成server , client-->
make
