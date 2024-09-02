#include<bits/stdc++.h>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
	Car(string name):_name(name){}
	
protected:
	string _name;
};

class Bmw:public Car
{
public:
	Bmw(string name):Car(name){}
	void show()
	{
		cout<<"获取了一辆宝马："<<_name<<endl;
	}
	
};

class Audi:public Car
{
public:
	Audi(string name):Car(name){}
	void show()
	{
		cout<<"获取了一辆奥迪："<<_name<<endl;
	}
};
//简单工厂的话就是一个类包含了所有其它类实例的创建，显然不合理
//那么就需要用到工厂方法，每个工厂创造自己的实例对象

class Factory
{
public:
	virtual Car* CreateCar(string name) = 0;
};

//宝马工厂
class BmwFactory:public Factory
{
public:
	Car* CreateCar(string name)
	{
		return new Bmw(name);
	}
};

//奥迪工厂
class AudiFactory:public Factory
{
public:
	Car* CreateCar(string name)
	{
		return new Audi(name);
	}
};

int main()
{
	unique_ptr<Factory> bmwfactory(new BmwFactory());
	unique_ptr<Factory> audifactory(new AudiFactory());
	unique_ptr<Car> p1(bmwfactory->CreateCar("X6"));
	unique_ptr<Car> p2(audifactory->CreateCar("A8"));
	p1->show();
	p2->show();
	return 0;
}
