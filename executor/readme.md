# Installation of Requirements
## Linux Operating System
* now we are working on Windows10 Subsystem for Linux, later we might move to CentOS7 based on cloud service.
## VSCode
* we need to deploy the environment of C++ on our IDE VSCode.
* first we refer to this [website](https://blog.csdn.net/SuGeLaInys/article/details/99934184) for the configuration.
* then we refer to this [website](https://code.visualstudio.com/docs/cpp/config-wsl) for the execution of cpp file.
## Mysql 5.7.32-0ubuntu0.18.04.1
* please refer to this [website](https://jingyan.baidu.com/article/afd8f4decbdf2234e286e9a4.html) to intall it on your WSL.
* then please intall the mysql client for C++ by the command:
```
sudo apt install libmysqlclient-dev
```
* for convenience of development, please initialize the mysql to reset the root user and password by the command (before this you should enter root user of your WSL by command `su`):
```
mysql_secure_installation
```
* then you will see a sequence of questions for initialization, please do as follows:
```
\\ Would you like to setup VALIDATE PASSWORD plugin? - NO
\\ set user name as root
\\ set password as rootroot
\\ Remove anonymous users? - y
\\ Disallow root login remotely? - NO
\\ Remove test database and access to it? - NO
\\ Reload privilege tables now? - y
```
# Connector
## functions
* to be continued...
## run the code
* first you should enter root user by `su`, then start the mysql database by this command:
```
service mysql restart
```
* you can complile the file mysql_connector.cpp by (please pay attention to changing the file path in main funtion):
```
g++ mysql_connector.cpp `mysql_config --cflags --libs` -o mysql_connector
```
* then execute by command:
```
./mysql_connector
```