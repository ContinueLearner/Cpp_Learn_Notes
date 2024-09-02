#include<bits/stdc++.h>
using namespace std;

 
class Car
{
public:
	virtual void show() = 0;
};

class Bmw:public Car
{
public:
	void show()
	{
		cout<<"这是宝马，基本配置";
	}
};

class Audi:public Car
{
public:
	void show()
	{
		cout<<"这是奥迪，基本配置";
	}
};

class ConcreteDecorator:public Car
{
public:
	ConcreteDecorator(Car* p):pCar(p){}
	void show()
	{
		pCar->show();
		cout<<"，自动巡航";
	}
private:
	Car *pCar;
};

class ConcreteDecorator01:public Car
{
public:
	ConcreteDecorator01(Car* p):pCar(p){}
	void show()
	{
		pCar->show();
		cout<<"，车道偏离";
	}
private:
	Car *pCar;
};
int main()
{
	Car* p1 = new ConcreteDecorator(new Bmw());
	p1 = new ConcreteDecorator01(p1);
	p1->show();
	cout<<endl;
	
	Car* p2 = new ConcreteDecorator(new Audi());
	p2->show();
	cout<<endl;
	return 0;
}
