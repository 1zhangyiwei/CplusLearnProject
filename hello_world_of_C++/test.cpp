/*
01 hello world
基础框架测试
*/

#include <iostream>
#include <string>

#include "max.h"
using namespace std;

int main()
{
    cout<<"hello world!"<<endl;
    int a = 10;
    int b = 20;

    int c = Max(a,b);
    cout<<"a和b的最大值为："<<c<<endl;
    // system("pause");
    return 0;
}