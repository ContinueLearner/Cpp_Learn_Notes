#include<bits/stdc++.h>
using namespace std;

class Observer
{
public:
	virtual void handle(int msgid) = 0;
};

class Observer1:public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid) {
		case 1:
			cout<<"Observer1 recv 1 msg"<<endl;
			break;
		case 2:
			cout<<"Observer1 recv 2 msg"<<endl;
			break;
		default:
			cout<<"Observer1 recv unknow msg"<<endl;
			break;
		}
	}
};

class Observer2:public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid) {
		case 1:
			cout<<"Observer2 recv 1 msg"<<endl;
			break;
		case 3:
			cout<<"Observer2 recv 3 msg"<<endl;
			break;
		default:
			cout<<"Observer2 recv unknow msg"<<endl;
			break;
		}
	}
};

class Observer3:public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid) {
		case 3:
			cout<<"Observer3 recv 3 msg"<<endl;
			break;
		default:
			cout<<"Observer3 recv unknow msg"<<endl;
			break;
		}
	}
};

class Subject
{
public:
	void addObserver(Observer* ob,int msgid)
	{
		Hash[msgid].push_back(ob);
	}
	void notify(int msgid)
	{
		auto it = Hash.find(msgid);
		if(it != Hash.end())
		{
			for(auto item:it->second)
			{
				item->handle(msgid);
			}
		}
	}
private:
	unordered_map<int,list<Observer*>> Hash;
};
int main()
{
	Subject subject;
	Observer *p1 = new Observer1();
	Observer *p2 = new Observer2();
	Observer *p3 = new Observer3();
	
	subject.addObserver(p1,1);
	subject.addObserver(p1,2);
	subject.addObserver(p2,1);
	subject.addObserver(p2,3);
	subject.addObserver(p3,3);
	
	while(1)
	{
		cout<<"请输入消息id:";
		int msgid;
		cin>>msgid;
		if(msgid == -1)
		{
			break;
		}
		subject.notify(msgid);
	}
	
 	return 0;
}
