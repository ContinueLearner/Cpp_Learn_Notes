#include<bits/stdc++.h>
using namespace std;
using namespace chrono;


void systemClockTest()
{
	//创建一个时间点对象
	system_clock::time_point epoch;
	time_t allSec = system_clock::to_time_t(epoch);
	cout<<"创建的时间点对象是："<<ctime(&allSec)<<endl;
	//获取当前的时间并格式化成能看懂的形式
	
	system_clock::time_point nowTime = system_clock::now();
	time_t nowSec = system_clock::to_time_t(nowTime);
	cout<<"当前的时间是："<<ctime(&nowSec)<<endl;
}

void steadyClockTest()
{
	auto p1 = steady_clock::now();
	for(int i = 0;i<1000;i++)
	{
		cout<<"*";
	}
	auto p2 = steady_clock::now();
	auto d1 = p2 - p1;
	cout<<"时间间隔是："<<d1.count()<<endl;
}
int main()
{
	systemClockTest();
	
	steadyClockTest();
	return 0;
}
