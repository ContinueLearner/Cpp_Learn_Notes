#include<bits/stdc++.h>
using namespace std;

class Singleton
{
public:
	static Singleton* getinstance()
	{
		static Singleton instance;
		return &instance;
	}
private:
	Singleton()
	{
		
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator==(const Singleton&) = delete;
};

int main()
{
	Singleton* p1 = Singleton::getinstance();
	Singleton* p2 = Singleton::getinstance();
	Singleton* p3 = Singleton::getinstance();
	
	//Singleton t1 = *p1;已经禁用了赋值重载函数和拷贝构造函数
	
	return 0;
}
