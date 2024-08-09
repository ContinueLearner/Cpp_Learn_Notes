#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Rectangle
{
public:
	friend T;
	Rectangle(int w,int h):w(w),h(h){}
private:
	int w,h;
};

template<typename T>
class Circle
{
public:
	friend T;
	Circle(int r):r(r){}
private:
	int r;
};

class Verify
{
public:
	Verify(int w,int h,Rectangle<Verify> &r)
	{
		if(w > r.w && h > r.h)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	
	Verify(int r,Circle<Verify> c)
	{
		if(r > c.r)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
};
int main()
{
	Rectangle<Verify> r(100,200);
	Circle<Verify> c(50);
	Verify(50,50,r);
	Verify(30,c);
	return 0;
}
