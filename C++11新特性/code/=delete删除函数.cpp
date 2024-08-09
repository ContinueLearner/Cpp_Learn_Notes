#include<bits/stdc++.h>
using namespace std;

class Test
{
public:
	Test()
	{
		
	}
	Test(const Test& t) = delete;
	Test& operator=(const Test&& t) = delete;
	void print(int a)
	{
		cout<<a<<endl;
	}
	void print(char c) = delete;
};

int main()
{
	Test t;
	//Test tt(t);报错显示函数已经被删除
	//Test tt1;
	//tt1 = t;报错显示函数已经被删除
	t.print(1);
	//t.print('c');报错显示函数已经被删除
	
	return 0;
}
