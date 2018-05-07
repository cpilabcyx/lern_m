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
	Mediator *mediator;	//����н���
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
			cout << "ͬ���� ֮�� �����Ҷ��� " << endl;
			return;
		}
		if (pWoman->getCondi() == pMan->getCondi())
		{
			cout << pWoman->getName() << " �� " << pMan->getName() << "���� " << endl;
		}
		else
		{
			cout << pWoman->getName() << " �� " << pMan->getName() << "���� " << endl;
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
	virtual void getParter(Person *p)//�Ҷ���ͳһ�ӿڣ��н���ִ�о�����Ϊ
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
		mediator->getParter(); //�Ҷ��� 
	}
};

void main()
{
	//string name, int sex, int condi
	Mediator *m = new Mediator;
	Person *xiaofang = new Woman("С��", 2, 5, m);

	Person *zhangsan = new Man("����", 1, 4, m);

	Person *lisi = new Man("����", 1, 5, m);
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