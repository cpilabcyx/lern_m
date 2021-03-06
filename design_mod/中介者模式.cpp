#include <iostream>
using namespace std;
#include "string"

class Mediator;

class Person
{
public:
	Person(string name, int sex, int condi, Mediator *m)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
		mediator = m;
	}
	string getName()
	{
		return m_name;
	}
	int getSex()
	{
		return m_sex;
	}
	int getCondi()
	{
		return m_condi;
	}
	virtual void getParter(Person *p) = 0;

protected:
	string	m_name;
	int		m_sex;
	int		m_condi;
	Mediator *mediator;	//组合中介者
};

class Mediator
{
public:
	void setMan(Person *man)
	{
		pMan = man;
	}
	void setWoman(Person *woman)
	{
		pWoman = woman;
	}

public:
	virtual void getParter()
	{

		if (pWoman->getSex() == pMan->getSex())
		{
			cout << "同性恋 之间 不能找对象 " << endl;
			return;
		}
		if (pWoman->getCondi() == pMan->getCondi())
		{
			cout << pWoman->getName() << " 和 " << pMan->getName() << "绝配 " << endl;
		}
		else
		{
			cout << pWoman->getName() << " 和 " << pMan->getName() << "不配 " << endl;
		}
	}
private:
private:
	Person	*pMan;
	Person	*pWoman;
};

class Woman : public Person
{
public:
	Woman(string name, int sex, int condi, Mediator *m) : Person(name, sex, condi, m)
	{

	}
	virtual void getParter(Person *p)//找对象，统一接口，中介者执行具体行为
	{
		mediator->setMan(p);
		mediator->setWoman(this);
		mediator->getParter(); 
	}
};

class Man : public Person
{
public:
	Man(string name, int sex, int condi, Mediator *m) : Person(name, sex, condi, m)
	{

	}
	virtual void getParter(Person *p)
	{
		mediator->setMan(this);
		mediator->setWoman(p);
		mediator->getParter(); //找对象 
	}
};

void main()
{
	//string name, int sex, int condi
	Mediator *m = new Mediator;
	Person *xiaofang = new Woman("小芳", 2, 5, m);

	Person *zhangsan = new Man("张三", 1, 4, m);

	Person *lisi = new Man("李四", 1, 5, m);
	xiaofang->getParter(zhangsan);

	xiaofang->getParter(lisi);

	delete m; 
	delete xiaofang;
	delete zhangsan;
	delete lisi;

	cout << "hello..." << endl;
	system("pause");
	return;
}