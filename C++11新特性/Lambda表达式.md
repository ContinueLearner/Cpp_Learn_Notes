## Lambda表达式

1. 基本语法

```c++
[capture](params) opt -> ret {body;};
```

其中capture是捕获列表，params是参数列表，opt是函数选项，ret是返回值类型，body是函数体。

[] - 不捕捉任何变量
[&] - 捕获外部作用域中所有变量, 并作为引用在函数体内使用 (**按引用捕获)**
[=] - 捕获外部作用域中所有变量, 并作为副本在函数体内使用 (**按值捕获**)

​	拷贝的副本在匿名函数体内部是只读的

[=, &foo] - 按值捕获外部作用域中所有变量, 并按照引用捕获外部**变量** foo
[bar] - 按值捕获 bar 变量, 同时不捕获其他变量
[&bar] - 按引用捕获 bar 变量, 同时不捕获其他变量
[this] - 捕获当前**类中的this指针**

​	让lambda表达式拥有和当前类成员函数同样的访问权限
​	**如果已经使用了 & 或者 =, 默认添加此选项**

2. 示例

```C++
#include <iostream>
#include <functional>
using namespace std;

class Test
{
public:
    void output(int x, int y)
    {
        auto x1 = [] {return m_number; };                      // error
        auto x2 = [=] {return m_number + x + y; };             // ok
        auto x3 = [&] {return m_number + x + y; };             // ok
        auto x4 = [this] {return m_number; };                  // ok
        auto x5 = [this] {return m_number + x + y; };          // error
        auto x6 = [this, x, y] {return m_number + x + y; };    // ok
        auto x7 = [this] {return m_number++; };                // ok
        auto x8 = [&]()mutable -> void
        {
            for(int i = 0;i<10;i++)cout<<i<<" ";
            cout<<endl;
        };
    }
    int m_number = 100;
};
```

