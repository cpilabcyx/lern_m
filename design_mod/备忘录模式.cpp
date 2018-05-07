
#include <iostream>
using namespace std;
#include "string"

//Caretaker ������
// MememTo  ����¼

class MememTo
{
public:
	MememTo(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}

	void setName(string name)
	{
		this->m_name = name;
	}
	void setAge(int age)
	{
		this->m_age = age;
	}
private:
	string	m_name;
	int		m_age;
};

class  Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}

	void setName(string name)
	{
		this->m_name = name;
	}
	void setAge(int age)
	{
		this->m_age = age;
	}

	//����
	MememTo* createMememTo()
	{
		return new MememTo(m_name, m_age);
	}
	//��ԭ 
	void setMememTo(MememTo* memto)
	{
		this->m_age = memto->getAge();
		this->m_name = memto->getName();
	}
public:
	void printT()
	{
		cout << "m_name:" << m_name << " m_age:" << m_age << endl;
	}
private:
	string	m_name;
	int		m_age;
};

class Caretaker
{
public:
	Caretaker(MememTo *memto=NULL)
	{
		this->memto = memto;
	}
	MememTo *getMememTo()
	{
		return memto;
	}
	void setMememTo(MememTo *memto)
	{
		this->memto = memto;
	}
protected:
private:
	MememTo *memto;//////////////////////////////////////////////
};

void main()
{
	Person* brother = new Person("���Ĳ�", 38);
	Caretaker* record = new Caretaker(brother->createMememTo());
	brother->printT();

	brother->setAge(28);
	brother->printT();

	brother->setMememTo(record->getMememTo());
	brother->printT();

	delete brother;
	delete record;

	return;
}