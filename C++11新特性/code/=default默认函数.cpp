#include<bits/stdc++.h>
using namespace std;

class Test
{
	Test() = default;
	~Test() = default;
	Test(const Test&t) = default;
	Test(Test && t) = default;
	Test& operator=(const Test&t) = default;
	Test& operator=(Test && t) = default;
	Test(int a)
	{
		
	}
};
//为了使自定义的类是POD类型，可以使用default实现默认函数
int main()
{
	cout<<"Test是不是POD类型："<<is_trivial<Test>::value<<endl;
	return 0;
}
