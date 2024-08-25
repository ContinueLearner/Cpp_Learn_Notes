#include<bits/stdc++.h>
using namespace std;


mutex mtx;
condition_variable cv;

class Queue
{
public:
	void put(int val)
	{
		unique_lock<mutex> lock(mtx);
		while(!q.empty())
		{
			cv.wait(lock);
		}
		q.push(val);
		cv.notify_all();
		cout<<"生产者生产"<<val<<"号物品"<<endl;
	}
	
	int get()
	{
		unique_lock<mutex> lock(mtx);
		while(q.empty())
		{
			cv.wait(lock);
		}
		int val = q.front();
		q.pop();
		cv.notify_all();
		cout<<"消费者生产"<<val<<"号物品"<<endl;
		return val;
	}
private:
	queue<int> q;
};


void producer(Queue& q)
{
	for(int i = 1;i<=10;i++)
	{
		q.put(i);
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

void customer(Queue& q)
{
	for(int i = 1;i<=10;i++)
	{
		q.get();
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}


int main()
{
	Queue q;
	thread t1(producer,ref(q));
	thread t2(customer,ref(q));
	
	t1.join();
	t2.join();
	
	return 0;
}
