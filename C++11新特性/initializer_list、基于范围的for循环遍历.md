## initializer_list

1. 对于std::initializer_list<T>而言，它可以接收任意长度的初始化列表，但是要求元素必须是同种类型T,内部有三个成员接口：size(), begin(), end()。并且只能被整体初始化或者赋值。

作为普通函数参数

```C++
#include <iostream>
#include <string>
using namespace std;

void traversal(std::initializer_list<int> a)
{
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(void)
{
    initializer_list<int> list;
    cout << "current list size: " << list.size() << endl;
    traversal(list);

    list = { 1,2,3,4,5,6,7,8,9,0 };
    cout << "current list size: " << list.size() << endl;
    traversal(list);
    cout << endl;
    
    list = { 1,3,5,7,9 };
    cout << "current list size: " << list.size() << endl;
    traversal(list);
    cout << endl;

    ////////////////////////////////////////////////////
    ////////////// 直接通过初始化列表传递数据 //////////////
    ////////////////////////////////////////////////////
    traversal({ 2, 4, 6, 8, 0 });
    cout << endl;

    traversal({ 11,12,13,14,15,16 });
    cout << endl;


    return 0;
}
```

作为构造函数参数

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test
{
public:
    Test(std::initializer_list<string> list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            cout << *it << " ";
            m_names.push_back(*it);
        }
        cout << endl;
    }
private:
    vector<string> m_names;
};

int main(void)
{
    Test t({ "jack", "lucy", "tom" });
    Test t1({ "hello", "world", "nihao", "shijie" });
    return 0;
}
```



## 基于范围的for循环遍历

1. **可以加引用，可以加const只读。**
2. 对应基于范围的for循环来说，**冒号后边的表达式只会被执行一次。**在得到遍历对象之后会先确定好迭代的范围，基于这个范围直接进行遍历。如果是普通的for循环，在每次迭代的时候都需要判断是否已经到了结束边界。

```C++
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> t{ 1,2,3,4,5,6 };
    for (const auto& value : t)
    {
        cout << value << " ";
    }

    return 0;
}
```

