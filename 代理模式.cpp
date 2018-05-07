#include <iostream>
using namespace std;

class Fruit
{
public:
	virtual void getFruit() = 0;

protected:
private:
};

class Banana : public Fruit   //ʵ�ֹ�ϵ
{
public:
	virtual void getFruit()
	{
		cout << "�����㽶...." << endl;
	}
protected:
private:
};

class south_Banana : public Fruit	//ʵ�ֹ�ϵ
{
public:

	south_Banana(Fruit* myFruit)
	{
		ptrFruit = myFruit;
	}

	virtual void getFruit()
	{
		ptrFruit->getFruit();
		cout << "�������Ϸ��㽶...." << endl;
	}

public:
	Fruit* ptrFruit;
};

class big_Banana : public Fruit	//ʵ�ֹ�ϵ
{
public:
	big_Banana(Fruit* myFruit)
	{
		ptrFruit = myFruit;
	}

	virtual void getFruit()
	{
		ptrFruit->getFruit();
		cout << "�����Ǵ��㽶...." << endl;
	}

public:
	Fruit* ptrFruit;
};

void main01()
{
	Fruit* ptr = new Banana();
	ptr->getFruit();

	Fruit*ptr1 = new south_Banana(ptr);
	ptr1->getFruit();

	Fruit*ptr2 = new big_Banana(ptr1);
	ptr2->getFruit();

	Fruit*ptr3 = new south_Banana(ptr2);
	ptr3->getFruit();

	delete ptr3;
	delete ptr2;
	delete ptr1;
	delete ptr;

	return;
}