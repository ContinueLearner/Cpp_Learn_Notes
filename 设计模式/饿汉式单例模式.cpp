#include<bits/stdc++.h>
using namespace std;

/*
  单例模式就是一个类只能有一个实例对象
  饿汉式单例模式：程序一启动就存在该类的对象
  懒汉式单例模式：直到调用时才会创建该类的对象
 */
class Singleton
{
public:
	static Singleton* getinstance()
	{
		return &instance;
	}
private:
	static Singleton instance;
	Singleton()
	{
		
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator==(const Singleton&) = delete;
};
Singleton Singleton::instance;

int main()
{
	Singleton* p1 = Singleton::getinstance();
	Singleton* p2 = Singleton::getinstance();
	Singleton* p3 = Singleton::getinstance();
	
	//Singleton t1 = *p1;已经禁用了赋值重载函数和拷贝构造函数
	 
	return 0;
}
