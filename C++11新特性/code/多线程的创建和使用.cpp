#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

void func()
{
	cout<<"我是子线程： "<<"我的线程id:"<<this_thread::get_id()<<endl;
}

void func1(string name,int age)
{
	cout<<"姓名："<<name<<"年龄："<<age<<"线程id:"<<this_thread::get_id()<<endl;
}

int main()
{
	//创建可用的子线程对象
	thread t1(func);
	
	thread t2(func1,"鸣人",18);
	
	//使用lambda表达式创建线程
	thread t3([](int a){
		cout<<"参数是："<<a<<"线程id:"<<this_thread::get_id()<<endl;
	},1001);
	
	thread&& t4 = move(t3);
	
	t1.join();
	t2.join();
	t4.join();
	
	int num = thread::hardware_concurrency();
	cout<<"CPU核心数："<<num<<endl;
	return 0;
}
