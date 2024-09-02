#include<bits/stdc++.h>
using namespace std;

/*
  需要有一个代理类来控制其它类对委托类的访问权限，简单写一个电影访问权限网站
 */ 

class VideoSite
{
public:
	virtual void freeMovie() = 0;
	virtual void vipMovie() = 0;
	virtual void ticketMovie() = 0;
};

class FixBugVideoSite:public VideoSite
{
public:
	virtual void freeMovie()
	{
		cout<<"观看免费电影"<<endl;
	}
	virtual void vipMovie()
	{
		cout<<"观看vip电影"<<endl;
	}
	virtual void ticketMovie()
	{
		cout<<"观看用券电影"<<endl;
	}
};

class FreevideoSiteProxy:public VideoSite
{
public:
	FreevideoSiteProxy()
	{
		Video = new FixBugVideoSite();
	}
	~FreevideoSiteProxy()
	{
		delete Video;
	}
	virtual void freeMovie()
	{
		Video->freeMovie();
	}
	virtual void vipMovie()
	{
		cout<<"您不是vip"<<endl;
	}
	virtual void ticketMovie()
	{
		cout<<"您没有券"<<endl;
	}
	
private:
	VideoSite * Video;
};

class VipvideoSiteProxy:public VideoSite
{
public:
	VipvideoSiteProxy()
	{
		Video = new FixBugVideoSite();
	}
	~VipvideoSiteProxy()
	{
		delete Video;
	}
	virtual void freeMovie()
	{
		Video->freeMovie();
	}
	virtual void vipMovie()
	{
		Video->vipMovie();
	}
	virtual void ticketMovie()
	{
		cout<<"您没有券"<<endl;
	}
	
private:
	VideoSite * Video;
};

void watch(unique_ptr<VideoSite> &p)
{
	p->freeMovie();
	p->vipMovie();
	p->ticketMovie();
}

int main()
{
	unique_ptr<VideoSite> p1(new FreevideoSiteProxy());
	unique_ptr<VideoSite> p2(new VipvideoSiteProxy());
	watch(p1);
	watch(p2);
	return 0;
}
