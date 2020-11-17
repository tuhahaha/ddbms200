 #include <stdio.h>
 #include <mysql/mysql.h>
 
 int main(int argc,char *argv[])
 {
    MYSQL conn;
    int res;
    mysql_init(&conn);
    if(mysql_real_connect(&conn,"localhost","root","rootroot","test",0,NULL,0)) //"root":数据库管理员 "":root密码 "test":数据库的名字
    {
       printf("connect success!\n");
       res=mysql_query(&conn,"insert into test values('user','123456')");
       if(res){
          printf("error\n");
          }
      else{
         printf("OK\n");
         }
      mysql_close(&conn);
    }
    else{
       printf("connection failed!\n");
       const char* pCh = mysql_error(&conn);
       printf("%s", pCh);
    }
    return 0;
}