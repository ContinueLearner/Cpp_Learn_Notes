#include<bits/stdc++.h>
using namespace std;

enum class color:int{Red,Green,Blue};

int main()
{
	//强类型枚举,必须加作用域，必须显示类型转换
	cout<<"red:"<<(int)color::Red<<endl;
	int m = (int)color::Red;
	cout<<m<<endl;
	
	cout<<"color size:"<<sizeof(color::Red)<<endl;
	return 0;
}
