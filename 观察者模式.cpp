
#include <iostream>
using namespace std;
#include "string"
#include "list"


class sentinel;

class soldier	//观察者 
{
public:
	virtual void rec_info(string info) = 0;
};

class sentinel
{
public:
	sentinel()
	{
		army.clear();
	}

	virtual void send_info(string info) = 0;	//发送消息接口

public:
	list<soldier*> army;	//观察者集合
};

class clairvoyance :public sentinel
{
public:
	virtual void send_info(string info)
	{	
		for (auto s : army)
		{
			s->rec_info(info);
		}
	}
};

class Omniscient :public sentinel
{
public:
	virtual void send_info(string info)
	{
		for (auto s : army)
		{
			s->rec_info(info);
		}
	}
};

class old_soldier :public soldier
{
	virtual void rec_info(string info)
	{
		cout << info << endl;
		cout << "我是老兵!\n";
	}
};

class fresh_soldier :public soldier
{
	virtual void rec_info(string info)
	{
		cout << info << endl;
		cout << "我是新兵，谢谢提醒!\n";
	}
};

void main()
{
	sentinel* sent = new clairvoyance();

	soldier* old = new old_soldier();
	soldier* fre = new fresh_soldier();

	sent->army.push_back(old);
	sent->army.push_back(fre);

	sent->send_info("我是千里眼，我看见大批敌军接近！");
	sent->send_info("我是千里眼，我看见敌军走远！");

	delete sent;
	sent = new Omniscient();

	sent->army.push_back(old);
	sent->army.push_back(fre);

	sent->send_info("我是顺风耳，我听见大批敌军接近！");
	sent->send_info("我是顺风耳，我听见敌军走远！");

	delete sent;
	delete old;
	delete fre;

	system("pause");
	return;
}