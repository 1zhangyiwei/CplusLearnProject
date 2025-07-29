/*
    01 函数
    函数的定义。语法：返回值类型，函数名称，(参数列表)，{函数体语句，return表达式}。
    返回值类型要和return对应。
    函数的调用。语法：函数名称（参数）。
    函数定义中的参数被称为形参，函数调用中的参数被称为实参。实参将数值传给形参（值传递），从而调用函数。
    注意，函数值传递占用内存较多，尤其是处理结构体和结构体数组时。所以，在该情况下，优先使用地址传递，指针占的空间很小。
    将函数中的形参改为指针，可以减少内存空间，不会复制一个新的副本出来。

    如果函数不需要返回值，声明可以写void，不写return表达式。
    值传递的时候，形参的改变并不会影响实参。

    函数常见样式：有无参数，有无返回值。两两组合，一共四种情况。

    函数的声明放在main函数之前，这样函数具体内容就可以放在main函数后面。声明可以写多次，函数定义只能有一次。
    函数的分文件编写。首先创建后缀名为.h的头文件，然后创建后缀名为.cpp的源文件，接着在头文件中写函数的声明，
    最后，在源文件中写函数的定义。为了关联头文件和源文件，在创建的源文件中包含创建的头文件（自定义的头文件用“”）。
    而且，在创建的头文件中，还要包含一般的c++头文件（iostream,using namespace std等）。
*/

//  #include <iostream>
//  #include <string>
//  #include "add.h"

//  using namespace std;

//  void swap(int num1,int num2)
//  {
//      cout<<"交换前："<<endl;
//      cout<<"num1="<<num1<<endl;
//      cout<<"num2="<<num2<<endl;    
//      int temp = num1;
//      num1 = num2;
//      num2 = temp;
//      cout<<"交换后："<<endl;
//      cout<<"num1="<<num1<<endl;
//      cout<<"num2="<<num2<<endl; 
//  }

//  //无参无返
//  void test01()
//  {
//      cout<<"this is test01"<<endl;
//  }

//  //有参无返
//  void test02(int a)
//  {
//      cout<<"this is test02 and a = "<<a<<endl;
//  }

//  //无参有返
//  int test03()
//  {
//      cout<<"this is test03"<<endl;

//      return 100;
//  }

//  //有参有返
//  int test04(int a)
//  {
//      cout<<"this is test04"<<endl;

//      return 2*a;
//  }

//  int main()
//  {
//      int a, b;
//      cin>>a>>b;

//     //  int c;
//     //  c = add(a, b);             //函数的分文件编写
//     //  cout<<"最终的结果为:"<<c<<endl;

//     //  cout<<"a = "<<a<<endl;
//     //  cout<<"b = "<<b<<endl;
//     //  swap(a, b);
//     //  cout<<"a = "<<a<<endl;
//     //  cout<<"b = "<<b<<endl;

//      test01();
//      test02(100);
//      int c = test03();
//      cout<<"c = "<<c<<endl;
//      int d = test04(20);
//      cout<<"d = "<<d<<endl;

//      system("pause");

//      return 0;
//  }



/*
    02 指针
    指针定义的语法：数据类型*指针变量名。
    指针的作用：可以通过指针间接访问内存,读内存数据和写内存数据。
    内存编号是从0开始记录的，一般用十六进制数字表示。可以用指针变量保存地址，记录内存编号。
    指针代表地址；变量名代表数据。
    
    可以通过解引用的方式来找到指针指向的内存。
    指针前加*代表解引用，找到指针指向的内存中的数据。

    指针也是一种数据类型,比如int*，也占用了内存空间。
    c++规定：无论任何数据类型指针，32位系统中，指针占用4个字节。64位系统中，指针占用8个字节。

    空指针和野指针。
    空指针指向内存中编号为0的空间，用来初始化指针变量，空指针指向的内存是不可访问的。
    0~255之间的内存编号是系统占用的，因此不可以访问。
    野指针指向非法的内存空间。内存地址要申请，不要随便给指针赋一个内存地址，容易出现异常，权限问题。
    空指针和野指针都不是我们申请的空间，因此不要访问。
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 10;
    int* p;
    p = &a;        //让整型指针p记录a的地址

    cout<<"数据a的地址为："<<p<<endl;
    cout<<"指针指向的内存中的数据为："<<*p<<endl;
    *p = 1000;
    cout<<"数据a为："<<a<<endl;

    cout<<"sizeof(int*) = "<<sizeof(int*)<<endl;
    cout<<"sizeof(float*) = "<<sizeof(float*)<<endl;
    cout<<"sizeof(char*) = "<<sizeof(char*)<<endl;
    cout<<"sizeof(double*) = "<<sizeof(double*)<<endl;

    int* p = NULL;            //空指针初始化
    *p = 100;                 //此句无法写
    cout<<*p<<endl;        //此句无法读

    int* p = (int*)0x1100;         //野指针,指向非法空间
    cout<<*p<<endl;

    system("pause");

    return 0;
}


/*
    03 指针和数组。
    利用指针来访问数组中的元素。
    int型指针p++，就是让指针向后偏移4个字节，指针查看数组内容中常用。指针所占内存空间大小和p++偏移空间大小没关系。
    偏移空间大小和指针类型相关。
*/

// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     int arr[7] = {1,2,3,6,7,84,94};
//     // cout<<arr<<endl;
//     // cout<<arr[0]<<endl;
//     // cout<<&arr[0]<<endl;
//     // int* p = &(arr[5]);
//     // cout<<*p<<endl;
//     // p++;
//     // cout<<*p<<endl;    
//     int* p2 = arr;
//     for(int i = 0;i < 7;i++)
//     {
//         cout<<"数组第"<<i<<"个元素为"<<*p2<<endl;
//         p2++;
//     }

//     // system("pause");

//     return 0;
// }


/*
    04 指针和函数。
    利用指针作为函数参数，来修改实参的值。
    在函数的值传递中，形参的改变并不会影响实参。
    在函数的地址传递中，可以修改实参。
    如果不想修改实参，就用值传递。如果想修改实参，就用地址传递。
    指针，数组，函数实现冒泡排序的例子可以好好看看。
*/
// #include <iostream>
// #include <string>
// using namespace std;

// void swp01(int num1, int num2)
// {
//     int temp = num1;
//     num1 = num2;
//     num2 = temp;
// }

// void swp02(int* p1, int* p2)
// {
//     int temp = *p1;
//     *p1 = *p2;
//     *p2 = temp;
// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     int* p1 = &a;
//     int* p2 = &b;
//     // swp01(a, b);             //值传递
//     swp02(p1, p2);              //地址传递
//     cout<<"a的值为:"<<a<<endl;
//     cout<<"b的值为:"<<b<<endl;

//     return 0;
// }


/*
    05 结构体。
    结构体属于用户自定义的数据类型，允许用户存储不同的数据类型。
    结构体数据类型的定义，一般在main函数外。语法：struct 结构体名{结构体成员列表}。创建时struct不能省略，结构体成员用分号隔开。
    结构体变量有三种创建方式，定义时struct可以省略（符合逻辑）。
    方式一，先创建结构体变量，后通过.访问结构体变量中的属性并赋值。
    方式二，在创建结构体变量的同时，={}进行赋值。注意结构体成员顺序不能乱。
    方式三，在定义结构体数据类型的时候，结尾花括号后跟着要创建的结构体变量名。后通过.访问结构体变量中的属性并赋值。
    方式一和方式三大同小异，方式三不建议用。学会方式一和方式二即可。
*/
// #include <iostream>
// #include <string>
// using namespace std;

// struct student              //定义结构体数据类型student
// {
//     string name;
//     int age;
//     double score;
// }s3;                       //方式三创建结构体变量

// int main()
// {
//     // struct student              //定义结构体数据类型student
//     // {
//     //     string name;
//     //     int age;
//     //     double score;
//     // }s3;                       //方式三创建结构体变量

//     student s1;                //方式一创建结构体变量
//     s1.name = "zhangyiwei";
//     s1.age = 26;
//     s1.score = 352.5;
//     cout<<s1.name<<"\t"<<s1.age<<"\t"<<s1.score<<endl; 

//     student s2 = {"zhangyiwei",26,352.5};         //方式二创建结构体变量
//     cout<<s2.name<<"\t"<<s2.age<<"\t"<<s2.score<<endl; 
    
//     return 0;
// }

/*
    06 结构体数组。
    数组中存放的每一个数据都是结构体数据变量，将结构体数据变量放入数组中方便维护。
    语法：struct 结构体名 数组名[元素个数] = {{}，{}，{}}。完全符合创建数组的逻辑。
    谨记结构体也是一种数据类型。
*/
// #include <iostream>
// #include <string>
// using namespace std;

// struct student                //定义结构体数据类型
// {
//     string name;
//     int age;
//     double score;
// };

// int main()
// {
//     student test1[2];                    //创建结构体数组
//     test1[0].name = "zhangyiwei";        //方式一，通过.属性进行赋值
//     test1[0].age = 15;
//     test1[0].score = 462;
//     test1[1].name = "ShaNiu";
//     test1[1].age = 18;
//     test1[1].score = 2060;
//     for (int i = 0; i < 2; i++)         //for循环进行数组的显示
//     {
//         cout<<test1[i].name<<"\t"<<test1[i].age<<"\t"<<test1[i].score<<endl;
//     }

//     student test2[2] =                  //方式二，创建结构体数组并赋值
//     {           
//         {"张三",12,251},
//         {"李四",25,347}
//     };
    
//     for (int i = 0; i < 2; i++)
//     {
//         cout<<test2[i].name<<"\t"<<test2[i].age<<"\t"<<test2[i].score<<endl;
//     }
    
//     return 0;
// }


/*
    07 结构体指针。
    通过指针访问结构体中的成员。
    结构体变量可以通过操作符.访问结构体属性。
    结构体指针可以通过操作符->访问结构体属性。
    解引用在结构体指针里为啥不能用？
*/
// #include <iostream>
// #include <string>
// using namespace std;

// struct student                //定义结构体数据类型
// {
//     string name;
//     int age;
//     double score;
// };

// int main()
// {
//     student s1 = {"张义伟", 26, 352};              //创建学生的结构体变量
//     student* p = &s1;        //指针指向结构体变量

//     cout<<"姓名："<<p->name<<"   年龄："<<p->age<<"   成绩："<<p->score<<endl;

//     return 0;
// }


/*
    08 结构体嵌套结构体
    结构体中的成员可以是另一个结构体，用来解决实际问题。注意两种结构体的定义顺序，被嵌套的结构体先定义。
    举例：比如不同老师带着不同的学生，老师和学生都可以视为两种不同的结构体。
*/
// #include <iostream>
// #include <string>
// using namespace std;

// struct student                //定义结构体数据类型
// {
//     string name;
//     int age;
//     double score;
// };

// struct teacher                //定义结构体数据类型
// {
//     int ID;
//     string name;
//     int age;
//     student stu;
// };

// int main()
// {
//     teacher t;                               //创建结构体
//     t.ID = 1;
//     t.name = "奥云";
//     t.age = 30;

//     t.stu.name = "zhangyiwei";               //方式一，赋值嵌套结构体内的变量
//     t.stu = {"张义伟", 10, 99};          //方式二，赋值嵌套结构体内的变量

//     cout<<"教师编号："<<t.ID<<"    教师姓名："<<t.name<<"      教师年龄："<<t.age<<"\n"
//         <<"所带学生姓名："<<t.stu.name<<"       所带学生年龄："<<t.stu.age<<"      所带学生分数："<<t.stu.score<<endl;

//     return 0;
// }


/*
    09 结构体做函数参数。
    将结构体作为参数向函数中传递。传递方式有两种，值传递和地址传递。切记两种传递方式的区别，是否改变实参！

    结构体中const使用场景。在函数地址传递时，可以在形参前加const来设置只读状态，防止误操作。即使是地址传递也不能改变实参。

    将学生传入到一个参数中，打印学生身上的所有信息。
*/
// #include <iostream>
// #include <string>
// using namespace std;

// struct student
// {
//     string name;
//     int age;
//     double score;
// };

// void PrintStu1(student* p)
// {
//     cout<<"学生姓名:"<<p->name<<"\n"<<"学生年龄:"<<p->age<<"\n"<<"学生分数:"<<p->score<<endl;
//     p->name = "傻妞";
// }

// void PrintStu2(student st)
// {
//     cout<<"学生姓名:"<<st.name<<"\n"<<"学生年龄:"<<st.age<<"\n"<<"学生分数:"<<st.score<<endl;
// }

// void PrintStu3(const student* p)
// {
//     cout<<"学生姓名:"<<p->name<<"\n"<<"学生年龄:"<<p->age<<"\n"<<"学生分数:"<<p->score<<endl;
//     // p->name = "傻妞";             //本句就无法使用，因为有const存在，限制了实参的改变
// }

// int main()
// {
//     student st;
//     st = {"张义伟", 26, 352};
//     student* p = &st;

//     PrintStu1(p);               //地址传递
//     // PrintStu2(st);            //值传递。这里只是打印学生信息，所以不会改变实参，也就可以用值传递的方法。
//     // PrintStu3(p);               //地址传递,加了const修饰，使函数无法修改实参。

//     cout<<"main函数中 学生姓名:"<<st.name<<"\n"<<"学生年龄:"<<st.age<<"\n"<<"学生分数:"<<st.score<<endl;

//     return 0;
// }