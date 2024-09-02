#include<bits/stdc++.h>
using namespace std;


class VGA
{
public:
	virtual void play() = 0;
};

class Tv01:public VGA
{
public:
	void play()
	{
		cout<<"通过VGA接口连接投影仪，进行视频播放"<<endl;
	} 
};

class computer
{
public:
	void playVideo(VGA* p)
	{
		p->play();
	}
};

class HDMI
{
public:
	virtual void play() = 0;
};

class Tv02:public HDMI
{
public:
	void play()
	{
		cout<<"通过HDMI接口连接投影仪，进行视频播放"<<endl;
	}
};

class VGA2HDMIAdapter:public VGA
{
public:
	VGA2HDMIAdapter(HDMI* p):pHDMI(p){}
	void play()
	{
		pHDMI->play();
	}
private:
	HDMI* pHDMI;
};
int main()
{
	computer c;
	c.playVideo(new VGA2HDMIAdapter(new Tv02()));
	return 0;
}
