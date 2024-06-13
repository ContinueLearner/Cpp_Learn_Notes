## using

1. using定义别名和函数指针，更加方便

```C++
using uint_t = int;
using func_ptr1 = int(*)(int, double);
```

2. using定义模板的别名

```c++
template <typename T>
using mymap = map<int, T>;
```

3. 最后在强调一点：using语法和typedef一样，并**不会创建出新的类型**，它们只是给某些类型**定义了新的别名**。using相较于typedef的优势在于定义函数指针别名时看起来**更加直观，并且可以给模板定义别名**。



## 委托构造函数

1. 委托构造函数允许**使用同一个类中的一个构造函数调用其它的构造函数**，从而简化相关变量的初始化。

```C++
#include <iostream>
using namespace std;

class Test
{
public:
    Test() {};
    Test(int max)
    {
        this->m_max = max > 0 ? max : 100;
    }

    Test(int max, int min):Test(max)
    {
        this->m_min = min > 0 && min < max ? min : 1;
    }

    Test(int max, int min, int mid):Test(max, min)
    {
        this->m_middle = mid < max && mid > min ? mid : 50;
    }

    int m_min;
    int m_max;
    int m_middle;
};

int main()
{
    Test t(90, 30, 60);
    cout << "min: " << t.m_min << ", middle: " 
         << t.m_middle << ", max: " << t.m_max << endl;
    return 0;
}
```

2. 这种链式的构造函数调用**不能形成一个闭环**（死循环），否则会在运行期抛异常。
3. 如果要进行多层构造函数的链式调用，建议将构造函数的调用的**写在初始列表中**而不是函数体内部，否则编译器会提示形参的重复定义。



## 继承构造函数

1. C++11中提供的继承构造函数可以让**派生类直接使用基类的构造函数**，而无需自己再写构造函数，尤其是在基类有很多构造函数的情况下，可以**极大地简化派生类构造函数的编写**

**未简化**版版本

```C++
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    Base(int i) :m_i(i) {}
    Base(int i, double j) :m_i(i), m_j(j) {}
    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base
{
public:
    Child(int i) :Base(i) {}
    Child(int i, double j) :Base(i, j) {}
    Child(int i, double j, string k) :Base(i, j, k) {}
};

int main()
{
    Child c(520, 13.14, "i love you");
    cout << "int: " << c.m_i << ", double: " 
         << c.m_j << ", string: " << c.m_k << endl;
    return 0;
}
```

**使用继承构造函数**的版本

```C++
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    Base(int i) :m_i(i) {}
    Base(int i, double j) :m_i(i), m_j(j) {}
    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base
{
public:
    using Base::Base;
};

int main()
{
    Child c1(520, 13.14);
    cout << "int: " << c1.m_i << ", double: " << c1.m_j << endl;
    Child c2(520, 13.14, "i love you");
    cout << "int: " << c2.m_i << ", double: " 
         << c2.m_j << ", string: " << c2.m_k << endl;
    return 0;
}
```

   2.在修改之后的子类中，没有添加任何构造函数，而是添加了**using Base::Base**;这样就可以在子类中直接继承父类的所有的构造函数，通过他们去构造子类对象了。

3. 另外如果在**子类中隐藏了父类中的同名函数**，也可以通过using的方式在子类中使用基类中的这些父类函数：

```C++
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    Base(int i) :m_i(i) {}
    Base(int i, double j) :m_i(i), m_j(j) {}
    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    void func(int i)
    {
        cout << "base class: i = " << i << endl;
    }
    
    void func(int i, string str)
    {
        cout << "base class: i = " << i << ", str = " << str << endl;
    }

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base
{
public:
    using Base::Base;
    using Base::func;
    void func()
    {
        cout << "child class: i'am luffy!!!" << endl;
    }
};

int main()
{
    Child c(250);
    c.func();
    c.func(19);
    c.func(19, "luffy");
    return 0;
}
```