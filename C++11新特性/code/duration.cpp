#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

int main()
{
	//小时、分钟、秒、毫秒、微秒、纳秒的简单定义
	hours h(1);
	minutes m(1);
	seconds s(1);
	chrono::milliseconds ms(1);
	microseconds mis(1);
	nanoseconds ns(1);
	
	cout<<m.count()<<endl;
	
	//也可以使用duration进行自定义时间间隔
	duration<int,ratio<3600>> hour(1);//这就是一小时
	
	
	//可以自定义半秒
	duration<double> s2(1.5);
	cout<<s2.count()<<endl;
	return 0;
}
