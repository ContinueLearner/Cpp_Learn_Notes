#include<bits/stdc++.h>
using namespace std;

int ticketCount = 100;
mutex mtx;

void sellTicket(int index)
{
	while(ticketCount > 0)
	{
		{
			lock_guard<mutex> lock(mtx);
			if(ticketCount > 0)
			{
				cout<<"窗口:"<<index<<"正在卖第"<<ticketCount<<"张票"<<endl;
				ticketCount--;
			}
		}
		this_thread::sleep_for(chrono::milliseconds(100));//线程的睡眠得放在while里面
	}
	
}
int main()
{
	vector<thread> tlist;
	for(int i = 1;i<=3;i++)
	{
		tlist.push_back(thread(sellTicket,i));
	}
	for(auto &t:tlist)
	{
		t.join();
	}
	return 0;
}
