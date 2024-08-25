#include<bits/stdc++.h>
using namespace std;

void threadHandle(int time)
{
	this_thread::sleep_for(chrono::seconds(time));
	cout<<"threadHandle"<<endl;
}

int main()
{
	
	thread t1(threadHandle,2);
	t1.join();
	cout<<"子线程结束"<<endl;
	return 0;
}
