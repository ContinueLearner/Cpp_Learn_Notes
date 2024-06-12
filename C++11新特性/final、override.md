## final

1. 如果使用final修饰函数，只能**修饰虚函数**，这样就能**阻止子类重写父类的这个函数**了：

```C++
class Base
{
public:
    virtual void test()
    {
        cout << "Base class...";
    }
};

class Child : public Base
{
public:
    void test() final
    {
        cout << "Child class...";
    }
};

class GrandChild : public Child
{
public:
    // 语法错误, 不允许重写
    void test()
    {
        cout << "GrandChild class...";
    }
};
```

1. 使用final关键字**修饰过的类是不允许被继承的**，也就是说这个类不能有派生类。

```C++
class Base
{
public:
    virtual void test()
    {
        cout << "Base class...";
    }
};

class Child final: public Base
{
public:
    void test()
    {
        cout << "Child class...";
    }
};

// error, 语法错误
class GrandChild : public Child
{
public:
};
```



## override

1. override关键字确保在**派生类中声明的重写函数与基类的虚函数有相同的函数名**。写错了函数名或者函数参数或者返回值编译器都会提示语法错误，提高了程序的正确性，降低了出错的概率。

```C++
class Base
{
public:
    virtual void test()
    {
        cout << "Base class...";
    }
};

class Child : public Base
{
public:
    void test() override
    {
        cout << "Child class...";
    }
};

class GrandChild : public Child
{
public:
    void test() override
    {
        cout << "Child class...";
    }
};
```



