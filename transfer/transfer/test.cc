#include <iostream>
#include <memory>
#include <string>
use namespace std;

static  byte[]   StructToBytes(object structObj)
{
    int   size   =     Marshal.SizeOf(structObj);   
    IntPtr   buffer   =   Marshal.AllocHGlobal(size);   
    try   
    {   
        Marshal.StructureToPtr(structObj,   buffer,   false);   
        byte[]   bytes   =   new   byte[size];   
        Marshal.Copy(buffer,   bytes,   0,   size);   
        return   bytes;   
    }   
    finally   
    {   
        Marshal.FreeHGlobal(buffer);   
    }   
   
}

struct GDD{
  string name;
  int id;
  int res;
};

int main(){
    GDD test;
    test.name = "tjh";
    test.id = 22;
    test.res = 99;

    GDD* test;
    test->id = 




}

#define MAX_COLUMN=10;
struct GDD {
	string name;
	ColumnDef col[MAX_COLUMN];
}

struct ColumnDef {
	string name;
	string type;
	bool null;
	bool key;
	string desc;
}

#define MAX_FRAG=5;
struct Fragment {
	string name;
	string fragtype;// H/V 
	int fragnum;
	FragDef frag[MAX_FRAG];
}

struct FragDef {
	int id;
    int site;
    string column; //该分片涉及到的column，如果是多个，则用逗号分隔
	string condition; //分片条件
    int size; //记录该分片的大小，以byte为单位
}

//以数据流方式传输
// bytes encodeObj(object){
//     //将object编码成bytes数据流
//     return bytes
// }
// object decodeObj(bytes){
//     //将bytes解码为数据对象
//     return object
// }

