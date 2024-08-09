#include<bits/stdc++.h>
using namespace std;

class Test
{
public:
	Test() = default;
	Test(int a){};
};

class Base
{
	static int a;
};

class Child:public Base
{
	int b;
	Base bb;
};

class Child1:public Base
{
	Base bb;
	int b;
};

int main()
{
	cout<<"Test是不是平凡类型："<<is_trivial<Test>::value<<endl;
	cout<<"Child是不是标准布局类型："<<is_standard_layout<Child>::value<<endl;
	cout<<"Child1是不是标准布局类型："<<is_standard_layout<Child1>::value<<endl;
	return 0;
}

/*
  字节赋值，代码中我们可以安全地使用memset 和 memcpy 对 POD类型进行初始化和拷贝等操作。 
  提供对C内存布局兼容。C++程序可以与C 函数进行相互操作，因为POD类型的数据在C与C++ 间的操作总是安全的。 
  保证了静态初始化的安全有效。静态初始化在很多时候能够提高程序的性能，而POD类型的对象初始化往往更加简单。
 */
