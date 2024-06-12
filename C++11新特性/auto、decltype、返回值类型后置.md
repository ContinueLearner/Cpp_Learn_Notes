## auto

1. 使用auto声明的变量**必须初始化**，否则会报错
2. auto的四个限制
   1. auto不能用作**形参**，因为只有在被调用的时候才能确定变量的类型
   2. auto不能用作类内**非静态成员变量**的初始化，同样是因为其是属于对象的，没有被初始化
   3. auto不能定义**数组**
   4. 不能使用auto**推导模板的参数**
3. auto的应用
   1. 用于**STL**的遍历
   2. 用于**泛型编程**（较为高阶）

## decltype

1. decltype (表达式)，decltype的推导是在**编译期**完成的，**用于表达式类型的推导**，并不会计算表达式的值
2. 推导规则
   1. 表达式为**普通变量**或者**普通表达式**或者**类表达式**，在这种情况下，使用decltype推导出的类型和表达式的类型是一致的。
   2. 表达式是**函数调用**，使用decltype推导出的类型和函数返回值一致。
   3. 表达式是一个**左值**，或者被**括号( )包围**，使用 decltype推导出的是表达式类型的**引用**。左值就是变量，右值就是常量
3. decltype的应用：泛型编程，decltype(T().begin()) m_it声明一个模板类型的迭代器

```C++
#include <list>
#include <iostream>
using namespace std;

template <class T>
class Container
{
public:
    void func(T& c)
    {
        for (m_it = c.begin(); m_it != c.end(); ++m_it)
        {
            cout << *m_it << " ";
        }
        cout << endl;
    }
private:
    decltype(T().begin()) m_it;  // 这里不能确定迭代器类型
};

int main()
{
    const list<int> lst{ 1,2,3,4,5,6,7,8,9 };
    Container<const list<int>> obj;
    obj.func(lst);
    return 0;
}
```

## 返回值类型后置 == auto + decltype

1. 在泛型编程中，可能需要通过参数的运算来得到返回值的类型，比如下面这个场景：

```C++
#include <iostream>
using namespace std;
// R->返回值类型, T->参数1类型, U->参数2类型
template <typename R, typename T, typename U>
R add(T t, U u)
{
    return t + u;
}

int main()
{
    int x = 520;
    double y = 13.14;
    // auto z = add<decltype(x + y), int, double>(x, y);
    auto z = add<decltype(x + y)>(x, y);	// 简化之后的写法
    cout << "z: " << z << endl;
    return 0;
}
```

但是这样是不现实的，因为对于调用者来说，是不知道函数内部执行了什么样的处理动作的。

2. auto 会追踪 decltype() 推导出的类型，因此上边的add()函数可以做如下的修改：

```C++
#include <iostream>
using namespace std;

template <typename T, typename U>
// 返回类型后置语法
auto add(T t, U u) -> decltype(t+u) 
{
    return t + u;
}

int main()
{
    int x = 520;
    double y = 13.14;
    // auto z = add<int, double>(x, y);
    auto z = add(x, y);		// 简化之后的写法
    cout << "z: " << z << endl;
    return 0;
}
```

