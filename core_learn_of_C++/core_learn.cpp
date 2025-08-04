/*
    开始C++的核心编程。面向对象编程技术，非常主流的编程思想。
    01 内存分区模型。
    C++在程序执行的时候，将内存大方向划分为4个区域。
    意义：不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程。

    代码区：存放函数体的二进制代码，由操作系统进行管理。包含所有代码和注释。存放CPU执行的二进制机器指令。
    代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可。
    代码区是只读的，只读的目的是防止程序意外地修改了它的指令。

    全局区：存放全局变量和static静态变量以及全局常量。
    常量分为字符串常量和其他常量（const修饰的变量）也存放在此。全局区的数据在程序结束后由操作系统释放。

    栈区：由编译器自动分配释放，存放函数的形参，局部变量以及局部常量等。函数体内的变量都叫局部变量，包括main函数。
    常量分为字符串常量和其他常量（const修饰的变量）也存放在此。
    注意：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放。
    如果指针指向的数据保存在了堆区。

    堆区：由程序员分配和释放。
    在C++中主要利用new在堆区开辟内存。语法：new 数据类型（）。利用new创建数据，会返回开辟的数据的地址。
    比如int* p = new int(10)，括号表示一个变量，内写初始值。
    创建堆区数组，int* q = new int[10],[]表示创建数组。
    指针本身也是局部变量，放在栈上。如果调用的函数返回值是指针，就是把return回来的指针复制给了外面的指针变量，函数中的指针变量也被释放。
    堆区开辟的数据，由程序员手动释放，释放利用操作符delete,若程序员不释放，程序结束时，由操作系统回收。释放堆区数组要加[]。
    delete i;                                  //使用delete删除开辟出来的堆区变量
    delete[] q;                                  //使用delete删除开辟出来的堆区数组,指针还在

    在程序编译后，生成了exe可执行程序。
    程序运行前，分为两个区域：代码区和全局区。
    程序运行后，

*/
// #include <iostream>
// #include <string>

// using namespace std;

// int c = 30;
// int d = 10;
// string f = "zhangyiwei";

// int* func1()
// {
//     int h = 10;
//     return &h;
// }

// int* func2()
// {
//     int* p = new int(10);                  //利用new关键字可以在堆区开辟变量,括号内写内存初始值，new会返回开辟的变量的地址

//     return p;
// }

// int* func3()
// {
//     int* p = new int[10];                  //利用new关键字可以在堆区开辟数组,new会返回开辟的数组的首地址
//     for (int i = 0; i < 10; i++)           //赋值和打印堆区创建出来的数组
//     {
//         p[i] = i +100;
//         cout<<p[i]<<endl;
//     }
    
//     return p;
// }

// int main()
// {
//     int a = 10;
//     int b = 20;

//     static int e = 15;

//     const int g = 10;

//     cout<<"局部变量a的地址:"<<&a<<endl;         //查看局部变量的地址
//     cout<<"局部变量b的地址:"<<&b<<endl;
//     cout<<"全局变量c的地址:"<<&c<<endl;         //查看全局变量的地址
//     cout<<"全局变量d的地址:"<<&d<<endl;
//     cout<<"静态变量e的地址:"<<&e<<endl;         //查看静态变量的地址
//     cout<<"字符串常量f的地址:"<<&f<<endl;         //查看字符串常量的地址
//     cout<<"const修饰的常量g的地址:"<<&g<<endl;         //查看const修饰的常量的地址    

    // int* i = func1();                          //测试局部变量自动释放，所以无法返回地址。本句必定出错
    // cout<<*i<<endl;                           

    // int* i = func2();                          //使用new在堆区开辟内存
    // cout<<*i<<endl;    
    // cout<<i<<endl;  
    // cout<<*i<<endl;  
    // delete i;                                  //使用delete删除开辟出来的堆区变量
    // cout<<i<<endl;  
    // cout<<*i<<endl;

    // int* p = func3();
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // delete[] p;                                  //使用delete删除开辟出来的堆区数组,指针还在
    // cout<<*p<<endl;


    // return 0;
// }




/*
    02 引用。
    引用可以给变量起别名（相当于小名）。不同的名字操作同一部分内存。
    语法：数据类型 &别名 = 原名。   数据类型&  可以放在一起，看作别名的代表。          
    注意别名和原名数据类型要一致。
    注意引用必须初始化（必须对应别名和原名），初始化后不可以改变（别名不能再对应其他原名）。

    引用做函数参数。
    函数传参时，可以利用引用传递让形参修改实参。
    引用传递也是在值传递，地址传递后的第三种函数参数传递方法。引用传递可被视为地址传递的简化版，简化了语法，效果相同。C++推荐用引用技术，因为语法方便。
    引用传递，必须函数定义输入为引用别名即可，比如int &a。主函数可以不用创建别名，把原名当别名使用，调用函数直接把实参放入（相当于别名和原名相同，非常常见），
    最终就可以改变实参。

    引用做函数返回值。
    引用是可以作为函数的返回值存在的。用法：函数调用可以作为左值（被赋值），也可以作为右值（赋值）。
    注意：函数返回值不能是局部变量引用。

    引用的本质在C++内部实现是一个指针常量！写引用相当于写了一个指针常量。
    指针常量是指向的地址不变，但是指向的地址内部的数据可以变。也对应了初始化后不可以改变（别名不能再对应其他原名）。
    int a = 10;
    int& ref = a;这里相当于编译器自动变换为int* const ref = &a;
    ref = 20;这里相当于编译器检测到ref是引用，自动变换为*ref = 20;
    用引用别想太多，就当成别名用就完了，原理自己心里清楚就行。
    C++推荐用引用技术，因为语法方便。

    常量引用。
    常量引用主要用来修饰形参，防止误操作。
    在函数形参列表中，可以加const修饰形参，防止形参改变实参。？？？怕改变还用什么引用，直接值传递不就完了？
    感觉常量引用有点鸡肋。

*/
// #include <iostream>
// #include <string>
// using namespace std;

// void swap01(int num1, int num2)        //值传递
// {
//     int temp = num1;
//     num1 = num2;
//     num2 = temp;
// }

// void swap02(int* num1, int* num2)       //地址传递
// {
//     int temp = *num1;
//     *num1 = *num2;
//     *num2 = temp;
// }

// void swap03(int &num1, int &num2)       //引用传递,表示输入为别名
// {
//     int temp = num1;
//     num1 = num2;
//     num2 = temp;
// }

// int& test01()
// {
//     int a = 10;                  //该变量存放在栈区

//     return a;
// }

// int& test02()
// {
//     static int a = 10;            //改变了存放在全局区

//     return a;
// }

// void showValue(const int& value)
// {
//     cout<<value<<endl;
//     // value = 1000;                      //加上const可以防止函数体内修改别名，导致外部的变量也随之改变。本句是反例。
// }

// int main()
// {
//     int a = 10;
//     int &b = a;               //创建引用
//     int &c;                    //引用必须初始化，本句反面例子
//     int d = 20;
//     int &b = d;                  //b重复引用，本句反面例子
//     b = 20;
//     cout<<a<<endl;
//     cout<<b<<endl;


    // int num1 = 10;
    // int num2 = 20;
    // int* p1 = &num1;
    // int* p2 = &num2;
    // // swap01(num1, num2);               //值传递
    // // swap02(p1, p2);                      //地址传递
    // swap03(num1, num2);                  //引用传递
    // cout<<"num1 = "<<num1<<endl;
    // cout<<"num2 = "<<num2<<endl;

    // // int& num3 = test01();                   //函数返回值不能是局部变量引用，本句为反例。
    // int& num3 = test02();                      //此时函数返回值是全局区的静态变量
    // cout<<num3<<endl;                      
    // test02() = 1000;                   //引用作为函数返回值，且可作为左值。
    // cout<<num3<<endl;

    // int a = 10;
    // showValue(a);                              //常量引用
    // cout<<a<<endl;

    // return 0;
// }



/*
    03 函数补充

    函数的默认参数。
    在C++中，函数的形参列表中的形参是可以有默认值的。语法：返回值类型 函数名 （形参=默认值）{}
    注意，如果某个位置参数有默认值，那么从这个位置往后，从左往右，必须都要有默认值。调用函数时输入不全也清楚如何给形参赋值。
    如果函数声明里参数没有默认值，那么调用函数的时候少传一个参数都不行。有声明里有默认值的话，调用函数如果不传该参数，则使用默认值。
    调用函数如果传该参数，则传入的值覆盖默认值。
    注意，函数单句声明和函数实现只能一个有默认参数，防止出现歧义。

    函数占位参数。
    C++中函数的形参列表里可以有占位参数，只填一个数据类型用来做占位，调用函数时必须填补该位置(输入该数据类型的数据)。
    语法：返回值类型 函数名 (数据类型){}
    占位参数也可以有默认参数,不写变量名即可,比如void func3(int a, int , int = 10)。
    之后可能会用到。

    函数重载。
    函数名可以相同，提高复用性。
    函数重载满足条件：同一个作用域下；函数名称相同；函数参数类型不同或者个数不同或者顺序不同。
    注意，函数的返回值不可以作为函数重载的条件，防止出现歧义。符合逻辑，如果输入没有区别，还是不知道调用哪个函数。
    引用作为函数重载条件的注意事项：是否加const可以作为区分条件？？？指针常量，指向的数据能否更改。
    函数重载默认参数的注意事项：如果函数调用时，省略默认参数，函数重载发生歧义。为了避免这种情况，函数重载尽量避免有默认参数。
*/

// #include <iostream>
// #include <string>

// using namespace std;

// int func1(int a, int b = 20, int c = 30)              //函数默认参数
// {
//     return a+b+c;
// }

// int func2(int a = 10, int b = 10);                    //函数声明和函数实现只能有一个有默认参数

// void func3(int a, int , int = 10)                     //函数占位参数
// {
//     cout<<"this is func3"<<endl;
// }

// void func4()                                          //函数重载
// {
//     cout<<"重载函数1"<<endl;
// }

// void func4(int, char)
// {
//     cout<<"重载函数2"<<endl;
// }

// void func4(char, int)
// {
//     cout<<"重载函数3"<<endl;
// }

// void func4(int& a)
// {
//     cout<<"重载函数4"<<endl;
// }

// void func4(const int& a)
// {
//     cout<<"重载函数5"<<endl;
// }

// int main()
// {
//     // cout<<func1(10, 30)<<endl;                 //函数参数有默认值情况下，调用函数输入参数不全。
    
//     // cout<<func2(10)<<endl;

//     // func3(3, 12, 53);

//     func4();
//     func4(5, 's');
//     func4('s', 46);

//     int b = 5;
//     func4(10);
//     func4(b);

//     return 0;
// }


// int func2(int a, int b)
// {
//     return a+b;
// }



/*
    04 类和对象。
    C++面向对象的三大特性为：封装，继承，多态。
    C++认为万事万物皆为对象，对象有其属性和行为。比如人可以作为对象，属性有姓名，年龄，身高等。行为有走，跑，吃饭等。
    具有相同性质的对象，我们可以抽象为类，人属于人类，车属于车类。

    封装。
    封装是C++面向对象三大特性之一。
    封装的意义：将属性和行为作为一个整体，表现生活中的事物。将属性和行为加以权限控制。
    在设计类的时候，属性和行为写在一起，表现事物。语法(结尾加分号)：class 类名{访问权限：属性/行为};
    比如公共权限public内包含了属性和行为。可以用两个public分别包含属性和行为。
    类中的属性和行为又统一称为类的成员。属性，又被称为成员属性或成员变量。行为，又被称为成员函数或成员方法。
    类设计完，必须基于类建立对象。通过一个类创建一个对象的过程称为实例化。
    类在设计的时候，可以把属性和行为放在不同的权限下加以控制。访问权限有三种。
    public公共权限：成员 类内可以访问，类外可以访问。
    protected保护权限：成员 类内可以访问，类外不可以访问。
    private私有权限：成员 类内可以访问，类外不可以访问。protected和private主要区别在继承部分，子类能否访问。

*/
// #include <iostream>
// #include <string>
// using namespace std;

// const double PI = 3.1415;

// class Circle                        //类名。设计一个圆类，求圆的周长。
// {
// private:
//     /* data */
// public:                              //公共权限
//     int r;                           //属性：半径
// public:
//     double get_calculateZC()         //行为：获取圆的周长
//     {
//         return 2*PI*r;
//     }
// };

// class student
// {
// private:
//     /* data */
// public:
//     string stu_name;
//     int stu_ID;
// public:
//     void inputStu(string name, int id)
//     {
//         stu_name = name;
//         stu_ID = id;
//     }

//     void PringStu()
//     {
//         cout<<"学生姓名："<<stu_name<<endl;
//         cout<<"学生学号："<<stu_ID<<endl;
//     }
// };

// class Person                             //不同的访问权限，以人为例。
// {
// public: 
//     string name;

// protected:
//     string car;

// private:
//     int password;

// public:
//     void func()
//     {
//         name = "zhangyiwei";
//         car = "奔驰";
//         password = 2016001951;
//     }
   
// };

// int main()
// {
    // Circle c1;                      //通过圆类，创建一个圆类的对象=实例化。
    // c1.r = 2;                       //给圆对象的属性进行赋值
    // cout<<c1.get_calculateZC()<<endl;

    // student stu1;                   //练习例子
    // stu1.stu_name = "zhangyiwei";
    // stu1.stu_ID = 101101;
    // stu1.inputStu("张义伟", 2016001951);
    // stu1.PringStu();

    // Person peo1;
    // peo1.name = "张三";
    // peo1.car = "宝马";                  //本句反例，类外无法访问protected权限下的成员
    // peo1.password = 165151;             //本句反例，类外无法访问private权限下的成员

    // return 0;
// }



/*
    05 类和对象。
    struct与class。突然觉得类和结构体比较像。
    在C++中struct和class唯一的区别就在于默认的访问权限不同。
    struct默认权限为公共。class默认权限为私有。成员能否类外访问，想清楚！
    开发过程中建议将所有成员属性设置为私有，通过成员函数来设置私有成员变量的读和写，作为接口。优点是可以自己控制读写权限，
    读要函数返回，写要函数输入。 对于写权限，我们可以在成员函数内可以加判断语句来检测数据的有效性。

    在一个类中，也可以将另一个类作为成员，更具实际意义。比如，圆是类，圆点也是类。
    不同的类分写，将一个类分写为两部分：.h头文件和.cpp源文件。
    在.h头文件中删掉成员函数的实现，只留声明并分号结尾。添加#pragma once。
    在.cpp源文件中，包含头文件和与之相关的类的头文件。只留下成员函数的实现。
    注意标明类，比如void setR(int r)改写为void point::setR(int r)，其中point为成员函数setR的类。
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class func1
// {
//     int a1;                      //默认权限是私有权限。此时没有设置权限，看看它默认什么权限，类外能不能访问
// };

// struct func2
// {
//     int a2;                      //默认权限是公共权限
// };

// class Person
// {
// public:
//     void set_name(string name1)         //设置姓名可写
//     {
//         name = name1;
//         cout<<"姓名设置为："<<name<<endl;
//     }

//     string get_name()                                //姓名可读
//     {
//         return name;
//     }

//     int get_age()                 //年龄可读
//     {
//         return age;
//     }

//     void set_age(int p_age)
//     {
//         if(p_age>0 && p_age<150)
//         {
//             age = p_age;
//             cout<<"年龄已设置为"<<age<<endl;
//         }
//         else
//         {
//             cout<<"年龄输入错误"<<endl;
//         }
//     }

//     void set_lover(string lover1)         //情人可写
//     {
//         lover = lover1;
//         cout<<"爱人是："<<lover<<endl;
//     }



// private:
//     string name;
//     int age = 10;                        
//     string lover;                
// };

// int main()
// {
//     func1 c1;
//     func2 c2;
//     // c1.a1 = 101;                 //本句反例，因为c1是class，默认权限为私有，所以类外无法访问成员a1
//     c2.a2 = 121;

//     Person p1;
//     // p1.set_name("张义伟");
//     // cout<<"当前姓名为："<<p1.get_name()<<endl;
//     // cout<<"当前年龄为："<<p1.get_age()<<endl;
//     // p1.set_lover("林");
//     p1.set_age(130);

//     return 0;
// }


/*
    06 对象的初始化和清理：构造函数和析构函数。
    C++中的面向对象来源于生活，每个对象也都应该有初始化设置以及对象销毁前的清理数据的设置，非常重要的安全问题。
    C++利用构造函数和析构函数解决上述问题，这两个函数会被编译器自动调用，完成对象初始化和清理工作。
    对象的初始化和清理工作是编译器强制要做的事，如果我们不提供构造函数和析构函数，编译器也会提供，只不过是空实现，默认权限为public。
    构造函数和析构函数是特殊的成员函数，如果自己手动编写，权限不是public，就连对象实例化都不能进行。    

    构造函数在创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用，执行初始化工作。
    析构函数在对象销毁前系统自动调用，执行清理工作。
    构造函数语法：类名(){}。构造函数没有返回值也不写void；函数名称与类名相同；构造函数可以有参数，因此可以发生重载；
    程序在调用对象时候会自动调用构造，无需手动调用，而且只会调用一次。
    析构函数语法：~类名(){}。析构函数也没有返回值不用写void；函数名称与类名相同，在名称前加~；析构函数不可以有参数，因此不可以发生重载；
    程序在对象被释放销毁前会自动调用析构， 无需手动调用，而且只会调用一次。   

    构造函数的分类与调用。根据不同的情况和需求来使用。
    两种分类方式：按参数分为有参构造和无参构造（默认构造），按类型分为普通构造和拷贝构造。
    有参-拷贝构造函数的函数参数固定写法：const + 引用传递
    三种调用方式：括号法，显示法，隐式转换法。
    注意：括号法调用无参-普通构造函数，要省略括号，不然会当成函数声明！
    显示法相当于使用括号法对匿名对象设置，然后进行赋值。
    注意：类名(),叫做匿名对象。比如Person(10)，person为类名。当前行执行结束，会立即回收匿名对象。
    注意：不要用拷贝构造函数初始化匿名函数。编译器会认为这是对象声明。比如编译器会认为Person(p3) === Person p3，
    之前已经定义过对象p3了，会出现重定义。
    隐式转换法就是显示法的简化版，去掉了类名。
    推荐括号法。

    C++中拷贝构造函数调用时机通常有三种情况：
    使用一个已经创建完毕的对象来初始化一个新对象。
    值传递的方式给函数参数传值，实参传给形参的时候也调用了拷贝构造函数。
    以值方式返回局部对象。

    默认情况下，C++编译器至少给一个类添加3个函数。
    1.默认构造函数，无参，函数体为空。
    2.默认析构函数，无参，函数体为空。
    3.默认拷贝构造函数，对属性进行拷贝，也就是值拷贝。
    构造函数调用规则如下：
    如果用户定义有参构造函数，C++不再提供默认构造函数，但是会提供默认拷贝构造函数。自己也没有定义无参构造的话，就不能再调用无参构造函数了！
    如果用户定义拷贝构造函数，C++不再提供其他构造函数。要用其他的构造函数就得自己去定义！

    深拷贝与浅拷贝。面试经典问题，常见的一个坑。
    浅拷贝：简单的赋值拷贝操作。深拷贝：在堆区重新申请空间，进行拷贝操作。
    析构函数，将堆区开辟的数据做释放操作。
    类成员有堆区指针时，浅拷贝带来的问题就是指针指向同一块内存，堆区的内存被重复释放，非法操作。
    为了解决上述问题，引出深拷贝，使用自定义拷贝构造函数，而不是默认拷贝构造函数。重新开辟内存，指针地址不一样，但是指向的数据是一样的。
    
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//     Person()                 //无参-普通构造函数进行初始化
//     {
//         cout<<"Person 无参构造函数调用"<<endl;
//         m_height = nullptr;
//     }

//     Person(int a)                 //有参-普通构造函数进行初始化
//     {
//         age = a;
//         cout<<"Person 有参构造函数调用"<<endl;
//         m_height = nullptr;
//     }

//     Person(int a, int height)
//     {
//         age = a;
//         m_height = new int(height);
//     }

//     Person(const Person& p)              //有参-拷贝构造函数的函数参数固定写法：const + 引用传递
//     {
//         age = p.age;
//         cout<<"Person 拷贝构造函数调用"<<endl;
//         if (p.m_height) {
//             m_height = new int(*p.m_height);
//         } else {
//             m_height = nullptr;
//         }       
//         // m_height =new int(*p.m_height);                //利用深拷贝来解决浅拷贝的问题
//         // *m_height = *p.m_height;
//     }

//     ~Person()                //析构函数进行清理
//     {
//         if(m_height != NULL)
//         {
//             delete m_height;                   //容易出现问题，就是堆区同一块内存不能被释放两次。
//             m_height = NULL;
//         }
//         cout<<"Person 析构函数调用"<<endl;
//     }

//     int age;
//     int* m_height;
// };

// void test01(Person p)
// {

// }



// Person test02()
// {
//     Person p;
//     return p;
// }

// int main()
// {
    // Person p1;         //实例化，括号法调用无参-普通构造函数，要省略括号，不然会当成函数声明！
    // Person p1(10);        //实例化，括号法调用有参-普通构造函数.
    // Person p2(p1);           //实例化，括号发调用有参-拷贝构造函数。使用一个已经创建完毕的对象来初始化一个新对象。
    // cout<<"p2的年龄："<<p2.age<<endl;

    // Person p3 = Person(10);         //实例化，显示法调用有参-普通构造函数
    // Person p4 = Person(p3);         //实例化，显示法调用有参-拷贝构造函数
    // // Person(p3);                    //本句反例，不要使用拷贝构造函数初始化匿名对象

    // Person p5 = 10;                 //实例化，隐式转换法调用有参-普通构造函数。相当于写了Person p5 =Person(10);
    // Person p6 = p5;                 //实例化，隐式转换法调用有参-拷贝构造函数。相当于写了Person p6 = Person(p5)

    // Person p7;   
    // test01(p7);                      //值传递的方式给函数参数传值，实参传给形参的时候也调用了拷贝构造函数

    // Person p8 = test02();               //以值方式返回局部对象。

    // Person p9;
    // p9.age = 18;
    // Person p10(p9);                     // 注释掉自己写的拷贝构造，使用默认拷贝构造函数，对属性进行拷贝，也就是值拷贝。
    // cout<<"年龄为："<<p10.age<<endl;

    // Person p10(28);
    // cout<<"p10年龄为："<<p10.age<<endl;
    // Person p11(p10);                      //使用默认拷贝构造，进行浅拷贝。
    // cout<<"p11年龄为："<<p11.age<<endl;

    // Person p12(26, 170);
    // cout<<"p12年龄和身高分别为："<<p12.age<<"   "<<*p12.m_height<<endl;
    // Person p13(p12);
    // cout<<"p13年龄和身高分别为："<<p13.age<<"   "<<*p13.m_height<<endl;
    // return 0;
// }


/*
    07  初始化列表
    C++提供了初始化列表语法，用来初始化属性。
    语法：构造函数（）：属性1（值1），属性2（值2）...{}，使用有参构造使初始化列表更加灵活。
    Person(int a, int b, int c):属性1(a),属性2(b),属性3(c){ }
    感觉除了这种初始化方法，还可以用之前给构造函数传入参数，构造函数内赋值的方法。也可以直接类内成员变量赋初值。

*/

// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//     Person():age(26),score(353),height(172)
//     {
//         cout<<"Person 无参构造函数调用"<<endl;
//     }

//     Person(int a, int b, int c):age(a),height(b),score(c)
//     {

//     }

//     int age;
//     int height;
//     int score;

// };

// int main()
// {
//     Person p1;                                  //初始化值固定了
//     cout<<"p1的年龄为："<<p1.age<<endl;
//     cout<<"p1的身高为："<<p1.height<<endl;
//     cout<<"p1的分数为："<<p1.score<<endl;

//     Person p2(26, 172, 353);                                  //初始化值定义更加灵活
//     cout<<"p2的年龄为："<<p2.age<<endl;
//     cout<<"p2的身高为："<<p2.height<<endl;
//     cout<<"p2的分数为："<<p2.score<<endl;


//     return 0;
// }



/*
    08 类对象作为类成员。
    C++类中的成员可以是另一个类的对象，我们称该成员为对象成员。
    假如B类中有对象A作为成员，A为对象成员。在创建B对象时，A与B的构造和析构顺序如何？
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class phone
// {
// public:
//     phone(string pname)
//     {
//         cout<<"调用phone构造函数"<<endl;
//         m_PName = pname;
//     }

//     ~phone()
//     {
//         cout<<"调用phone析构函数"<<endl;
//     }

//     string m_PName;
// };

// class Person
// {
// public:
//     Person(string name, string phone):m_name(name), m_phone(phone)
//     {
//         cout<<"调用person构造函数"<<endl;
//     }


//     ~Person()
//     {
//         cout<<"调用person析构函数"<<endl;
//     }

//     string m_name;
//     phone m_phone;
// };

// void test01()
// {
//     Person p("张义伟","华为");

//     cout<< p.m_name<<"使用"<<p.m_phone.m_PName<<"手机"<<endl;
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    09 静态成员变量与函数
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//     Person()
//     {
//         cout<<"调用person构造函数"<<endl;
//     }


//     ~Person()
//     {
//         cout<<"调用person析构函数"<<endl;
//     }

//     static string m_name;

// private:
//     static string n_name;

// };

// string Person::m_name = "zhangyiwei";
// string Person::n_name = "baiqi";

// void test01()
// {
//     Person p1;

//     cout<< p1.m_name<<endl;

//     Person p2;
//     Person::m_name = "张义伟";             //注意调用方式
//     cout<< p1.m_name<<endl;

//     Person p3;
//     // cout<<Person::n_name<<endl;
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    10 类对象的内存空间
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//     int a;
//     static string m_name;

//     void func(){}
//     static void func1(){}

// };

// string Person::m_name = "zhangyiwei";

// void test01()
// {
//     Person p1;
//     cout<<"p1的内存空间大小为："<<sizeof(p1)<<endl;
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    11 this指针
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//     Person(int age)
//     {
//         this->age = age;
//     }

//     Person& PersonAddAge(Person& p)           //返回值注意用引用
//     {
//         this->age += p.age;

//         return *this;
//     }

//     int age;

// };


// void test01()
// {
//     Person p1(18);
//     // cout<<"p1的年龄为："<<p1.age<<endl;

//     Person p2(10);
//     // cout<<"p2的年龄为："<<p2.age<<endl;

//     p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//     cout<<"p2的年龄为："<<p2.age<<endl;

// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    12 空指针
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//     int m_age;

//     void showName()
//     {
//         cout<<"this is zhangyiwei's program!"<<endl;
//     }

//     void showAge()
//     {
//         if(this == NULL)
//         {
//             return;
//         }
//         cout<<"张义伟的年龄是："<<m_age<<endl;
//     }
// };

// void test01()
// {
//     Person* p = NULL;
//     p->showName();
//     p->showAge();
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    13 const修饰成员函数
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//     mutable int m_age;

//     Person()
//     {

//     }

//     void showName() const
//     {
//         m_age = 100;
//         cout<<m_age<<endl;
//     }
// };

// void test01()
// {
//     Person p;
//     p.showName();
// }

// void test02()
// {
//     const Person p1;
//     p1.m_age = 10;
//     cout<<p1.m_age<<endl;
//     p1.showName();
// }

// int main()
// {
//     // test01();
//     test02();

//     return 0;
// }


/*
    14 友元技术
    全局函数作友元
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class Building 
// {
// friend void goodGay(Building* p);

// public:
//     string sittingRoom;
// private:
//     string bedRoom;

// public:
//     void building()
//     {
//         sittingRoom = "客厅";
//         bedRoom = "卧室";
//     }

// };

// void goodGay(Building* p)
// {
//     cout<<"正在访问："<<p->sittingRoom<<endl;
//     cout<<"正在访问："<<p->bedRoom<<endl;
// }

// void test01()
// {
//     Building building;
//     goodGay(&building);
// }

// int main()
// {
//     test01();

//     return 0;
// }


// /*
//     15 友元技术
//     另一个类作友元
// */
// #include <iostream>
// #include <string>
// using namespace std;

// class Building 
// {
// friend class goodGay;


// public:
//     string sittingRoom;
// private:
//     string bedRoom;

// public:
//     void building();
// };

// void Building:: building()
// {
//     sittingRoom = "客厅";
//     bedRoom = "卧室";
// }

// class goodGay
// {
// public:
//     Building home;

//     void visit()
//     {
//         home.building();
//         cout<<"访问："<<home.sittingRoom<<endl;
//         cout<<"访问："<<home.bedRoom<<endl;
//     }

// };


// void test01()
// {
//     goodGay p1;
//     p1.visit();
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    16 友元技术
    成员函数作友元
*/
// #include <iostream>
// #include <string>
// using namespace std;


// class Building;
// class goodGay
// {
// public:
//     Building* building;
//     goodGay();
    
//     void visit();                 //设置为可以访问卧室
//     void visit2();                //设置为不可以访问卧室
// };

// class Building 
// {
// friend void goodGay::visit();
// friend void goodGay::visit2();

// public:
//     string sittingRoom;
// private:
//     string bedRoom;
// public:
//     Building();
// };

// Building::Building()
// {
//     cout<<"building构造中"<<endl;
//     sittingRoom = "客厅";
//     bedRoom = "卧室";
// }

// goodGay::goodGay()
// {
//     cout<<"goodGay构造中"<<endl;
//     building = new Building;
// }

// void goodGay::visit()
// {
//     cout<<"访问："<<building->sittingRoom<<endl;
//     cout<<"访问："<<building->bedRoom<<endl;
// }

// void goodGay::visit2()                
// {
//     cout<<"访问："<<building->sittingRoom<<endl;
//     cout<<"访问："<<building->bedRoom<<endl;
// }

// void test01()
// {
//     goodGay p1;
//     p1.visit();
//     p1.visit2();
// }

// int main()
// {
//     test01();

//     return 0;
// }


// /*
//     17 继承
//     语法
//     构造析构顺序
// */
// #include <iostream>
// #include <string>
// using namespace std;

// class basicPeople
// {
// public:

//     basicPeople()
//     {
//         cout<<"调用父类构造"<<endl;
//     }

//     ~basicPeople()
//     {
//         cout<<"调用父类析构"<<endl;
//     }

//     void face()
//     {
//         cout<<"每个人都有脸"<<endl;
//     }
//     void eye()
//     {
//         cout<<"每个人都有眼睛"<<endl;
//     }
// };

// class zhangyiwei:public basicPeople
// {
// public:
//     zhangyiwei()
//     {
//         cout<<"调用子类构造"<<endl;
//     }

//     ~zhangyiwei()
//     {
//         cout<<"调用子类析构"<<endl;
//     }

//     void name()
//     {
//         cout<<"我的名字叫张义伟！"<<endl;
//     }
// };

// void test01()
// {
//     zhangyiwei p1;
//     p1.name();
//     p1.eye();
//     p1.face();
// }

// int main()
// {
//     test01();

//     return 0;
// }



/*
    18 继承
    继承中同名成员的处理方式
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class basicPeople
// {
// public:
//     int m = 100;

//     void face()
//     {
//         cout<<"父类的脸"<<endl;
//     }

// };

// class zhangyiwei:public basicPeople
// {
// public:
//     int m = 200;

//     void face()
//     {
//         cout<<"子类的脸"<<endl;
//     }
// };

// void test01()
// {
//     zhangyiwei p1;
//     cout<<"父类的m = "<<p1.basicPeople::m<<endl;
//     cout<<"子类的m = "<<p1.m<<endl;
//     p1.face();
//     p1.basicPeople::face();
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    19 菱形继承
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class animal
// {
// public:
//     int m_age;
// };

// class sheep:virtual public animal
// {

// };

// class tuo:virtual public animal
// {

// };

// class sheepTuo:public sheep, public tuo
// {

// };

// void test01()
// {
//     sheepTuo s1;
//     s1.sheep::m_age = 10;
//     s1.tuo::m_age = 20;
//     cout<<"sheepTuo::sheep的年龄："<<s1.sheep::m_age<<endl;
//     cout<<"sheepTuo::tuo的年龄："<<s1.tuo::m_age<<endl;
//     cout<<"sheepTuo的大小为："<<sizeof(s1)<<endl;
// }

// int main()
// {
//     test01();

//     return 0;
// }


// /*
//     20 多态
// */
// #include <iostream>
// #include <string>
// using namespace std;

// class animal
// {
// public:
//     virtual void speak()
//     {
//         cout<<"动物在说话"<<endl;
//     }
// };

// class cat:public animal
// {
// public:
//     void speak()
//     {
//         cout<<"猫在说话"<<endl;
//     }
// };

// void doSpeak(animal& animal)
// {
//     animal.speak();
// }

// void test01()
// {
//     cat s1;
//     doSpeak(s1);
// }

// void test02()
// {
//     cout<<sizeof(animal)<<endl;
// }

// int main()
// {
//     // test01();
//     test02();

//     return 0;
// }


/*
    21 多态
    纯虚函数和抽象类
*/
// #include <iostream>
// #include <string>
// using namespace std;

// class animal
// {
// public:
//     virtual void speak() = 0;
// };

// class cat:public animal
// {
// public:
//     void speak()
//     {
//         cout<<"猫在说话"<<endl;
//     }
// };

// void test01()
// {
//     animal*animal = new cat;
//     animal->speak();
// }


// int main()
// {
//     test01();

//     return 0;
// }


// /*
//     22 函数模板
// */
// #include <iostream>
// #include <string>
// using namespace std;

// template <typename T>          //注意结尾没有分号，因为这句话和下面的函数模板是一体的。
// void swap01(T& a, T& b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// template <typename T>
// void swap02()
// {
//     cout<<"到这里了"<<endl;
// }

// void test01()
// {
//     int a = 10;
//     int b = 20;
//     // swap01(a, b);              //自动类型推导
//     swap01<int>(a, b);            //手动指定类型
//     cout<<"a = "<<a<<endl;
//     cout<<"b = "<<b<<endl;

//     // double c = 1.5;
//     // double d = 3.3;
//     // // swap01(c, d);               //自动类型推导
//     // swap01<double>(c, d);          //手动指定类型
//     // cout<<"c = "<<c<<endl;
//     // cout<<"d = "<<d<<endl;

//     swap02<int>();
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    23 函数模板
    类型转换
*/
// #include <iostream>
// #include <string>
// using namespace std;

// int add01(int a, int b)
// {
//     return a+b;
// }

// template <class T>          
// //T add02(T& a, T& b)必定报错，
// //因为无法把下面的char c变成int&，只能把char强制转换为int
// T add02(T a, T b){
//     return a+b;
// }


// void test01()
// {
//     int a = 10;
//     int b = 20;
//     char c = 'c';

//     // cout<<add01(a, b)<<endl;

//     // cout<<add02(a, c)<<endl;               //自动类型推导
//     cout<<add02<int>(a, c)<<endl;          //手动指定类型

// }

// int main()
// {
//     test01();

//     return 0;
// }

/*
    24 普通函数与函数模板的调用规则
*/
// #include <iostream>
// #include <string>
// using namespace std;

// void myprint(int a, int b)
// {
//     cout<<"调用普通函数"<<endl;
// }

// template <typename T>
// void myprint(T a, T b)
// {
//     cout<<"调用函数模板1"<<endl;
// }

// template <typename T>
// void myprint(T a)
// {
//     cout<<"调用函数模板2"<<endl;
// }

// void test01()
// {
//     int num1 = 1;
//     int num2 = 2;
//     // myprint(num1, num2);          //优先调用普通函数
//     // myprint<>(num1, num2);            //空模板参数列表来强制调用函数模板
//     // myprint(num1);                    //函数模板也可以发生重载

//     char a = 'a';
//     char b = 'b';
//     myprint(a, b); //函数模板可以产生更好的匹配，优先调用函数模板，而不是去做诸如强制转换类型这种操作
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    25 类模板
*/
// #include <iostream>
// #include <string>
// using namespace std;

// template <class nametype, class agetype> 
// class Person
// {
// public:
//     Person(nametype name, agetype age)
//     {
//         this->m_name = name;
//         this->m_age = age;
//     }

//     void showme()
//     {
//         cout<<"名字为："<<this->m_name<<endl;
//         cout<<"年龄为："<<this->m_age<<endl;
//     }

//     nametype m_name;
//     agetype m_age;
// };

// int main()
// {
//     Person<string, int>p1("张义伟", 27);
//     p1.showme();
//     return 0;
// }

/*
    26 类模板与函数模板的区别
*/
// #include <iostream>
// #include <string>
// using namespace std;

// template <class nametype, class agetype = int>
// class Person
// {
// public:
//     Person(nametype name, agetype age)
//     {
//         m_name = name;
//         m_age = age;
//     }

//     void showMe()
//     {
//         cout<<"姓名："<<this->m_name<<endl;
//         cout<<"年龄："<<this->m_age<<endl;
//     }

//     nametype m_name;
//     agetype m_age;
// };

// void test01()
// {
//     Person<string>p1("张义伟", 27);
//     p1.showMe();
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    27 类模板对象做函数参数
*/
// #include <iostream>
// #include <string>
// using namespace std;

// template <class nametype, class agetype>
// class Person
// {
// public:
//     Person(nametype name, agetype age)
//     {
//         m_name = name;
//         m_age = age;
//     }

//     nametype m_name;
//     agetype m_age;
// };

// void showMe(Person<string, int>& p1)
// {
//     cout<<p1.m_name<<"的年龄为："<<p1.m_age<<endl;
// }

// void test01()
// {
//     Person<string, int>p1("张义伟", 27);
//     showMe(p1);
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    28 类模板与继承
*/
// #include <iostream>
// #include <string>
// #include <cxxabi.h>                //要显示全称，必须添加此头文件
// using namespace std;

// template <class T>
// class Father
// {
// public:

//     T m_name1;

// };

// template <class T1, class T2>
// class Son:public Father<T1>            //继承的时候，灵活指定父类的自定义类型
// {
// public:
//     Son()
//     {
//         cout<<"T1的类型为："<<typeid(T1).name()<<endl;   //实例化后，显示当前自定义类型为哪种数据类型。结果为单个字符
//         cout<<"T2的类型为："<<abi::__cxa_demangle(typeid(T2).name(),0,0,0)<<endl;//结果为全称
//     }

//     T2 m_age;
// };

// void test01()
// {
//     Son<char, int>p2;
// }

// int main()
// {
//     test01();

//     return 0;
// }


/*
    29 类模板的成员函数在类外实现
*/
// #include <iostream>
// #include <string>
// using namespace std;

// template <class nametype, class agetype>
// class Person
// {
// public:
//     Person(nametype name, agetype age);

//     void showMe();

//     nametype m_name;
//     agetype m_age;
// };

// template <class nametype, class agetype>
// Person<nametype, agetype>::Person(nametype name, agetype age)
// {
//     m_name = name;
//     m_age = age;
// }

// template <class nametype, class agetype>
// void Person<nametype, agetype>::showMe()
// {
//     cout<<"姓名："<<this->m_name<<endl;
//     cout<<"年龄："<<this->m_age<<endl;
// }

// void test01()
// {
//     Person<string, int>p1("张义伟", 27);
//     p1.showMe();
// }

// int main()
// {
//     test01();

//     return 0;
// }