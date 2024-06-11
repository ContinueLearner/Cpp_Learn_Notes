## 原始字面量

1. 用途：一般是为了原样输出字符串和换行的时候使用
2. 语法：R"XXX(D:\hello\world\test.text)XXX";   这样可以不加转义字符，保持原样输出字符串，而且左右两边的提示词必须保持一致，否则报错

```c++
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str = "D:\hello\world\test.text";
    cout << str << endl;
    string str1 = "D:\\hello\\world\\test.text";
    cout << str1 << endl;
    string str2 = R"(D:\hello\world\test.text)";
    cout << str2 << endl;

	string str = "<html>\
        <head>\
        <title>\
        海贼王\
        </title>\
        </head>\
        <body>\
        <p>\
        我是要成为海贼王的男人!!!\
        </p>\
        </body>\
        </html>";
    cout << str << endl;

    return 0;
}
```

## nullptr

1. 因为在C++中NULL被define成了0，所以程序的健壮性不够好，因此补充了C++自己的空指针nullptr，建议以后都使用nullptr



## constexpr

1. 常量表达式是在编译阶段就可以计算好的，但是C++11以前无法识别常量表达式，因此加入了constexpr就可以识别常量表达式了
2. constexpr修饰普通函数时，必须要有返回值、返回的必须是常量、函数内部实现只能由常量构成

```C++
constexpr int func2()
{
    using mytype = int;
    constexpr mytype a = 100;
    constexpr mytype b = 10;
    constexpr mytype c = a * b;
    return c - (a + b);
}
```

3. 如果使用constexpr修饰构造函数的话，函数体内部必须是空的，成员的赋值只能写在初始化列表里面

```c++
#include <iostream>
using namespace std;

struct Person {
    constexpr Person(const char* p, int age) :name(p), age(age)
    {
    }
    const char* name;
    int age;
};

int main()
{
    constexpr struct Person p1("luffy", 19);
    cout << "luffy's name: " << p1.name << ", age: " << p1.age << endl;
    return 0;
}
```

