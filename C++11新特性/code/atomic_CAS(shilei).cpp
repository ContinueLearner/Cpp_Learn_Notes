#include<bits/stdc++.h>
using namespace std;

atomic_bool isReady = false;
atomic_int num = 0;

void task()
{
	while(!isReady)
	{
		this_thread::yield();
	}
	for(int i = 1;i<=100;i++)
	{
		num++;
	}
}

int main()
{
	vector<thread> tvec;
	for(int i = 1;i<=10;i++)
	{
		tvec.push_back(thread(task));
	}
	
	this_thread::sleep_for(chrono::seconds(2));
	isReady = true;
	
	for(auto& t:tvec)
	{
		t.join();
	}
	
	cout<<num<<endl;
	
	return 0;
}
