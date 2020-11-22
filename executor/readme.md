# Installation of Requirements
## Linux Operating System
* now we are working on Windows10 Subsystem for Linux, later we might move to CentOS7 based on cloud service.
## VSCode
* we need to deploy the environment of C++ on our IDE VSCode.
* first we refer to this [website](https://blog.csdn.net/SuGeLaInys/article/details/99934184) for the configuration.
* then we refer to this [website](https://code.visualstudio.com/docs/cpp/config-wsl) for the execution of cpp file.
## Mysql 5.7.16-0ubuntu0.18.04.1
* Step1: please enter root user on your WSL.
* Step2: download and tar mysql 5.7.16 by these commands:
```
wget http://dev.mysql.com/get/Downloads/MySQL-5.7/mysql-5.7.16-linux-glibc2.5-x86_64.tar.gz
tar -xzvf  mysql-5.7.16-linux-glibc2.5-x86_64.tar.gz
```
* Step3: groupadd mysql by the following command, note that you can just ignore the message "user 'mysql' already exists". This exception is only because you has intalled one mysql on your WSL before, which won't have influence on our later installation.
```
useradd -g mysql -d /home/mysql mysql
```
* Step4: a sequence of configrations, mysql1 means the first mysql, which indicates later mysql2, mysql3, etc.
```
cd /home
mkdir mysql1
cd mysql1
<!-- note:maybe different path -->
cp -r ~/mysql-5.7.16-linux-glibc2.5-x86_64/. ./
mkdir data
chown -R mysql:mysql /home/mysql1/
chown -R mysql:mysql /home/mysql1/data
cd /etc
cp /home/mysql1/support-files/my-default.cnf  my1.cnf
vi my1.cnf
```
* edit the my1.cnf by adding these to the end of file, then save and quit:
```
[mysqld]
 
basedir = /home/mysql1
datadir = /home/mysql1/data
 
port=7654
character_set_server=utf8
init_connect='SET NAMES utf8'
innodb_file_per_table=1
user = mysql
socket=/home/mysql1/mysql.sock
[client]
default-character-set=utf8


```
* Step5: initialize mysql1 by the following commands:
```
cd /home/mysql1
./bin/mysqld --defaults-file=/etc/my1.cnf  --user=mysql --basedir=/home/mysql1 --datadir=/home/mysql1/data  --initialize
```
* and remember the keyword it generates for you, it will look like this and you should take down the `yX*xq/ye4bK+`:
```
[Note] A temporary password is generated for root@localhost: yX*xq/ye4bK+
```
* Step6: start the mysql1 instance by the command and please remember the process id to kill it when you want:
```
./bin/mysqld --defaults-file=/etc/my1.cnf --user=mysql --basedir=/home/mysql1 --datadir=/home/mysql1/data
```
* Step7: please open another terminal and log in to the mysql1 and change the root password by:
```
mysql -u root -S /home/mysql1/mysql.sock -p
```
<!-- maybe need to download Mysql client --> 
apt install mysql-client-core-8.0

* here enter the password you just took down and you can enter the mysql shell, change the password in the shell by:
```
alter user 'root'@'localhost' identified by 'rootroot';
```
* here in the shell I suggest you create a database for test in the development:
```
create database test;
```
* you can quit the shell by:
```
quit;
```
* Step8: then please intall the mysql client for C++ by the command:
```
cd ~
sudo apt install libmysqlclient-dev
```
* Step9: if you are going to intall 2 mysql instances on your WSL (here is tutu), please go over the step4 to step7 by replacing every "mysql1" with "mysql2" and when editing the file my2.cnf, set the port to 7655. I also prepare one complete version here:
```
cd /home
mkdir mysql2
cp -r ~/mysql-5.7.16-linux-glibc2.5-x86_64/. ./
mkdir data
chown -R mysql:mysql /home/mysql2/
chown -R mysql:mysql /home/mysql2/data
cd /etc
cp /home/mysql2/support-files/my-default.cnf  my2.cnf
vi my2.cnf
```
```
[mysqld]
 
basedir = /home/mysql2
datadir = /home/mysql2/data
 
port=7655
character_set_server=utf8
init_connect='SET NAMES utf8'
innodb_file_per_table=1
user = mysql
socket=/home/mysql2/mysql.sock
[client]
default-character-set=utf8
```
```
cd /home/mysql2
./bin/mysqld --defaults-file=/etc/my2.cnf  --user=mysql --basedir=/home/mysql2 --datadir=/home/mysql2/data  --initialize
```
* please remember the password here.
```
./bin/mysqld --defaults-file=/etc/my2.cnf --user=mysql --basedir=/home/mysql2 --datadir=/home/mysql2/data
```
* open another terminal
```
mysql -u root -S /home/mysql1/mysql.sock -p
```
* in the shell
```
alter user 'root'@'localhost' identified by 'rootroot';
create database test;
quit;
```

# Connector
## functions
* to be continued...
## run the code
* first you should enter root user , then start the mysql database by this command:
```
cd /home/mysql1
./bin/mysqld --defaults-file=/etc/my1.cnf --user=mysql --basedir=/home/mysql1 --datadir=/home/mysql1/data
```
* you can complile the file mysql_connector.cpp by (please pay attention to changing the file path in main funtion):
```
g++ mysql_connector.cpp `mysql_config --cflags --libs` -o mysql_connector
```
* then execute by command:
```
./mysql_connector
```
