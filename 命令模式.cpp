
#include <iostream>
using namespace std;
#include "list"

class tanke_driver	//����ĵ�ִ����
{
public:
	void turn_left()
	{
		cout << "��ʻԱ��ת" << endl;
	}

	void turn_right()
	{
		cout << "��ʻԱ��ת" << endl;
	}
};

class Command	//ͳһ�ӿڣ��������Ϊϸ������ʵ�֣�ÿ������Ϊһ���࣬���Կ��Լ�¼�����ִ���ߵ���Ϊ
{
public:
	virtual void turn() = 0;
};

class Commandturnleft : public Command	//��������Ϊ��ʵ�֣��������ִ���ߣ��ṩ��������ִ���ߵ�һ�ֹ�����Ϊ�Ľӿ�
{
public:
	Commandturnleft(tanke_driver *driver)
	{
		m_driver = driver;
	}
	virtual void turn()
	{
		m_driver->turn_left();
	}
private:
	tanke_driver *m_driver;
};

class Commandturnright : public Command	//��������Ϊ��ʵ�֣��������ִ���ߣ��ṩ��������ִ���ߵ�һ�ֹ�����Ϊ�Ľӿ�
{
public:
	Commandturnright(tanke_driver *driver)
	{
		m_driver = driver;
	}
	virtual void turn()
	{
		m_driver->turn_right();
	}
private:
	tanke_driver *m_driver;
};

class tanke_Head		//����Ĺ����ߣ��������
{
public:
	tanke_Head()
	{
		m_list.clear();
	}

public:
	void AddCommand(Command *command)//��֯����
	{
		m_list.push_back(command);
	}
	void SubmittedCase() //�´�����
	{
		for (list<Command *>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->turn();
		}
	}
private:
	list<Command *> m_list;
};

void main()
{
	tanke_Head *boose = new tanke_Head;
	tanke_driver* laosiji = new tanke_driver();
	Command* turn_order = new Commandturnleft(laosiji);

	boose->AddCommand(turn_order);
	boose->AddCommand(turn_order);

	turn_order = new Commandturnright(laosiji);
	boose->AddCommand(turn_order);

	boose->SubmittedCase();


	delete turn_order;
	delete laosiji;
	delete boose;

	system("pause");
	return;
}

