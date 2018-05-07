
#include <iostream>
using namespace std;
#include "string"
#include "list"


class sentinel;

class soldier	//�۲��� 
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

	virtual void send_info(string info) = 0;	//������Ϣ�ӿ�

public:
	list<soldier*> army;	//�۲��߼���
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
		cout << "�����ϱ�!\n";
	}
};

class fresh_soldier :public soldier
{
	virtual void rec_info(string info)
	{
		cout << info << endl;
		cout << "�����±���лл����!\n";
	}
};

void main()
{
	sentinel* sent = new clairvoyance();

	soldier* old = new old_soldier();
	soldier* fre = new fresh_soldier();

	sent->army.push_back(old);
	sent->army.push_back(fre);

	sent->send_info("����ǧ���ۣ��ҿ��������о��ӽ���");
	sent->send_info("����ǧ���ۣ��ҿ����о���Զ��");

	delete sent;
	sent = new Omniscient();

	sent->army.push_back(old);
	sent->army.push_back(fre);

	sent->send_info("����˳����������������о��ӽ���");
	sent->send_info("����˳������������о���Զ��");

	delete sent;
	delete old;
	delete fre;

	system("pause");
	return;
}