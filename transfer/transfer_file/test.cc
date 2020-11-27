#include <iostream>
#include <memory>
#include <string>
use namespace std;

static  byte[]  StructToBytes(object structObj)
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

int main(){
    GDD test;
    test.name = "tjh";
    test.id = 22;
    test.res = 99;

    GDD* test;
    // test->id =


}

