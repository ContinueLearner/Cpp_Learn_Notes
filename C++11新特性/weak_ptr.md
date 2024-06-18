## 弱引用智能指针

### 基本使用方法

1. 弱引用智能指针`std::weak_ptr`可以看做是`shared_ptr`的助手，它不管理`shared_ptr`内部的指针。`std::weak_ptr`没有重载操作符`*`和`->`，因为它不共享指针，不能操作资源，所以**它的构造不会增加引用计数**，析构也不会减少引用计数，**它的主要作用就是作为一个旁观者监视`shared_ptr`中管理的资源是否存在。**

#### 初始化方法

```c++
#include <iostream>
#include <memory>
using namespace std;

int main() 
{
    shared_ptr<int> sp(new int);

    weak_ptr<int> wp1;
    weak_ptr<int> wp2(wp1);
    weak_ptr<int> wp3(sp);
    weak_ptr<int> wp4;
    wp4 = sp;
    weak_ptr<int> wp5;
    wp5 = wp3;
    
    return 0;
}
```



#### 其它常用方法

1. use_count()：用来返回管理的shared_ptr的引用计数的
2. expired()：来观测管理的shared_ptr对象是否已经释放掉
3. lock()：返回管理的shared_ptr对象
4. reset()：清空weak_ptr对象，使其不观测任何资源



### 应用：解决shared_ptr的问题

#### 解决返回管理this的shared_ptr

```c++
#include <iostream>
#include <memory>
using namespace std;

struct Test : public enable_shared_from_this<Test>
{
    shared_ptr<Test> getSharedPtr()
    {
        return shared_from_this();//如果此处直接返回shared_ptr的this指针，那么main函数会析构两次出现错误，在此函数中，会调用weak_ptr的lock方法返回一个已管理的shared_ptr
    }
    ~Test()
    {
        cout << "class Test is disstruct ..." << endl;
    }
};

int main() 
{
    shared_ptr<Test> sp1(new Test);
    cout << "use_count: " << sp1.use_count() << endl;
    shared_ptr<Test> sp2 = sp1->getSharedPtr();
    cout << "use_count: " << sp1.use_count() << endl;
    return 0;
}
```

#### 解决循环引用问题

```c++
#include <iostream>
#include <memory>
using namespace std;

struct TA;
struct TB;

struct TA
{
    weak_ptr<TB> bptr;//如果此处也为shared_ptr，那么在main中会造成循环引用的问题，导致内存泄漏
    ~TA()
    {
        cout << "class TA is disstruct ..." << endl;
    }
};

struct TB
{
    shared_ptr<TA> aptr;
    ~TB()
    {
        cout << "class TB is disstruct ..." << endl;
    }
};

void testPtr()
{
    shared_ptr<TA> ap(new TA);
    shared_ptr<TB> bp(new TB);
    cout << "TA object use_count: " << ap.use_count() << endl;
    cout << "TB object use_count: " << bp.use_count() << endl;

    ap->bptr = bp;
    bp->aptr = ap;
    cout << "TA object use_count: " << ap.use_count() << endl;
    cout << "TB object use_count: " << bp.use_count() << endl;
}

int main()
{
    testPtr();
    return 0;
}
```

