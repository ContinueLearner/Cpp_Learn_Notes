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

class Light
{
public:
	virtual void show() = 0;
};

class BmwLight:public Light
{
public:
	void show()
	{
		cout<<"Bmw Light"<<endl;
	}
};

class AudiLight:public Light
{
public:
	void show()
	{
		cout<<"Audi Light"<<endl;
	}
};

//简单工厂的话就是一个类包含了所有其它类实例的创建，显然不合理
//那么就需要用到工厂方法，每个工厂创造自己的实例对象

class AbstractFactory
{
public:
	virtual Car* CreateCar(string name) = 0;
	virtual Light* createLight() = 0;
};

//宝马工厂
class BmwFactory:public AbstractFactory
{
public:
	Car* CreateCar(string name)
	{
		return new Bmw(name);
	}
	Light* createLight()
	{
		return new BmwLight();
	}
};

//奥迪工厂
class AudiFactory:public AbstractFactory
{
public:
	Car* CreateCar(string name)
	{
		return new Audi(name);
	}
	Light* createLight()
	{
		return new AudiLight();
	}
};

int main()
{
	unique_ptr<AbstractFactory> bmwfactory(new BmwFactory());
	unique_ptr<AbstractFactory> audifactory(new AudiFactory());
	unique_ptr<Car> p1(bmwfactory->CreateCar("X6"));
	unique_ptr<Car> p2(audifactory->CreateCar("A8"));
	
	unique_ptr<Light> l1(bmwfactory->createLight());
	unique_ptr<Light> l2(audifactory->createLight());
	
	p1->show();
	p2->show();
	l1->show();
	l2->show();
	
	return 0;
}
