
#include <iostream>
using namespace std;
#include "list"

class tanke_driver	//命令的的执行者
{
public:
	void turn_left()
	{
		cout << "驾驶员左转" << endl;
	}

	void turn_right()
	{
		cout << "驾驶员右转" << endl;
	}
};

class Command	//统一接口，具体的行为细节子类实现，每个子类为一个类，所以可以记录、拆解执行者的行为
{
public:
	virtual void turn() = 0;
};

class Commandturnleft : public Command	//命令者行为的实现，组合命令执行者，提供调用命令执行者的一种功能行为的接口
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

class Commandturnright : public Command	//命令者行为的实现，组合命令执行者，提供调用命令执行者的一种功能行为的接口
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

class tanke_Head		//命令的管理者，组合命令
{
public:
	tanke_Head()
	{
		m_list.clear();
	}

public:
	void AddCommand(Command *command)//组织命令
	{
		m_list.push_back(command);
	}
	void SubmittedCase() //下达命令
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

