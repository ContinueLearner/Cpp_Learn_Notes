#include<bits/stdc++.h>
#include<mutex>
using namespace std;

once_flag flag;

class Base
{
public:
	Base(){};
	Base(const Base & obj) = delete;
	Base& operator=(const Base& obj) = delete;
	static Base* getInstance()
	{
		call_once(flag,[&](){
			obj = new Base();
			cout<<"实例被创建"<<endl;
		});
		return obj;
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return this->name;
	}
	
private:
	string name;
	static Base* obj;
};
Base* Base::obj = nullptr;

void myFunc(string name)
{
	Base::getInstance()->setName(name);
	cout<<"Base name:"<<Base::getInstance()->getName()<<endl;
}
int main()
{
	thread t1(myFunc,"路飞");
	thread t2(myFunc,"学城");
	t1.join();
	t2.join();
	return 0;
}
