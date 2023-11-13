// /*
//     封装一个函数，利用冒泡排序，实现对整型数组的升序排序。
//     冒泡排序算法熟练记住。
//     用指针接收数组首地址。
// */
// #include <iostream>
// #include <string>
// using namespace std;

// void BubbleSort(int* arr, int len)
// {
//     for(int i=0; i<len; i++)
//     {
//         for(int j=0;j<len-i-1;j++)
//         {
//             if(arr[j]>arr[j+1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// void PrintArray(int* arr, int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         cout<<arr[i]<<"\t";
//     }
// }

// int main()
// {
//     int arr[10] = {15,26,48,75,12,46,93,85,27,38};
//     int* p = arr;
//     int len = sizeof(arr)/sizeof(arr[0]);
//     // cout<<p<<endl;
//     // cout<<len<<endl;
//     // cout<<sizeof(arr)<<endl;
//     // cout<<sizeof(arr[0])<<endl;

//     cout<<"排序前的数组："<<endl;
//     PrintArray(arr, len);
//     BubbleSort(p,len);
//     cout<<"\n排序后的数组："<<endl;
//     PrintArray(arr, len);

//     return 0;
// }



/*
    02 结构体案例。三位老师，各带五名学生。函数赋值信息，函数打印信息。
*/
// #include <iostream>
// #include <string>
// using namespace std;

// struct student                //定义结构体数据类型
// {
//     string stuname;
//     int score;
// };

// struct teacher                //定义结构体数据类型
// {
//     string teaname;
//     student stu[5];
// };

// void allocateSpace(teacher* p, int len)
// {
//     string nameSeed = "ABCDE";
//     for (int i = 0; i < len; i++)
//     {
//         p->teaname = "老师";
//         p->teaname += nameSeed[i];
//         for (int j = 0; j< 5; j++)
//         {
//             p->stu[j].stuname = "学生";
//             p->stu[j].stuname += nameSeed[j];
//         }
//         p++;
//     }
    
// }

// void PrintTea(teacher* p)
// {
//     for (int i = 0; i < 3; i++)
//     {
//         cout<<"老师姓名:"<<p->teaname<<endl;
//         for (int j = 0; j < 5; j++)
//         {
//             cout<<"所带学生姓名:"<<p->stu[j].stuname<<"        所带学生分数:"<<p->stu->score<<endl;
//         }    
//         p++;
//     }
    
    
// }

// int main()
// {
//     teacher tea[3];              //创建三位老师的结构体数组，
//     teacher* p = tea;

//     int len = sizeof(tea)/sizeof(tea[0]);

//     allocateSpace(tea, len);         //切记此处传结构体数组名也是在传地址，用指针和结构体数组名一个效果。指针多了++的操作。

//     teacher* q = tea;
//     PrintTea(q);                   //打印所有老师和所带学生的信息

//     return 0;
// }



/*
    03 结构体案例2。通过冒泡排序，将英雄结构体按照年龄进行升序排列，并打印排序后的结果。
*/
// #include <iostream>
// #include <string>
// using namespace std;

// struct hero
// {
//     string name;
//     int age;
//     string sex;
// };

// void SortHero(hero array[] , int len)
// {
//     for (int i = 0; i < len-1; i++)
//     {
//         for (int j = 0; j < len-i-1; j++)
//         {
//             if (array[j].age > array[j+1].age)
//             {
//                 hero temp = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = temp;
//             }
            
//         }
        
//     }
    
// } 

// void PrintHero(hero array[], int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         cout<<"姓名："<<array[i].name<<"      年龄："<<array[i].age<<"       性别："<<array[i].sex<<endl;
//     }
    
// }

// int main()
// {
//     hero heroArray[5];

//     heroArray[0] = {"刘备", 23, "男"};
//     heroArray[1] = {"关羽", 22, "男"};
//     heroArray[2] = {"张飞", 20, "男"};
//     heroArray[3] = {"赵云", 21, "男"};
//     heroArray[4] = {"貂蝉", 19, "女"};

//     SortHero(heroArray, 5);

//     PrintHero(heroArray, 5);        //受结构体案例一的影响，这里不传指针，用结构体数组名！

//     return 0;
// }



/*
    04 类和对象-封装。
    立方体类设计
    分别用全局函数和成员函数来判断两个立方体是否相等。
    在一个类中，也可以将另一个类作为成员，更具实际意义。比如，圆是类，圆点也是类。
    不同的类分写，将一个类分写为两部分：.h头文件和.cpp源文件。
    在.h头文件中删掉成员函数的实现，只留声明并分号结尾。添加#pragma once。
    在.cpp源文件中，包含头文件和与之相关的类的头文件。只留下成员函数的实现。
    注意标明类，比如void setR(int r)改写为void point::setR(int r)，其中point为成员函数setR的类。
*/
#include <iostream>
#include <string>
using namespace std;

class Cube
{
public:
    void set_cube( int l, int w, int h)
    {
        m_L = l;
        m_W = w;
        m_H = h;
        cout<<"立方体的长宽高设置为："<<m_L<<"  "<<m_W<<"   "<<m_H<<endl;
    }

    int get_cube_l()
    {
        return m_L;
    }

    int get_cube_w()
    {
        return m_W;
    }

    int get_cube_h()
    {
        return m_H;
    }

    int get_cube_s()
    {
        cube_s = (m_H*m_L+m_H*m_W+m_L*m_W)*2;
        return cube_s;
    }

    int get_cube_v( )
    {
        cube_v = m_H*m_L*m_W;
        return cube_v;
    }

    void isSame(Cube& c)                    //传入另外一个立方体来和自身进行对比
    {
        if (m_L==c.m_L && m_W==c.m_W && m_H==c.m_H)
        {
            cout<<"两个立方体相同"<<endl;
        }
        else
        {
            cout<<"两个立方体不相同"<<endl;
        }
    }

private:
    int m_L;
    int m_W;
    int m_H;
    int cube_s;
    int cube_v;
};

bool isSameCube(Cube& c1, Cube& c2)             //利用全局函数判断两个立方体是否相等，这里使用引用传递
{
    if(c1.get_cube_l() == c2.get_cube_l() && c1.get_cube_w() == c2.get_cube_w() && c1.get_cube_h() == c2.get_cube_h())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Cube lifangti;
    // lifangti.set_cube(10, 10, 10);
    // cout<<"立方体的面积为："<<lifangti.get_cube_s()<<endl;
    // cout<<"立方体的体积为："<<lifangti.get_cube_v()<<endl;

    Cube lifangti01;
    lifangti01.set_cube(10, 10, 10);
    Cube lifangti02;
    lifangti02.set_cube(10, 10, 10);
    // if(isSameCube(lifangti01, lifangti02))
    // {
    //     cout<<"两个立方体相同"<<endl;                     //这部分集成到函数内部好一点
    // }
    // else
    // {
    //     cout<<"两个立方体不相同"<<endl;
    // }

    lifangti01.isSame(lifangti02);

    return 0;
}