#include <iostream>
using namespace std;

class Fruit
{
public:
	virtual void getFruit() = 0;

protected:
private:
};

class Banana : public Fruit   //实现关系
{
public:
	virtual void getFruit()
	{
		cout << "我是香蕉...." << endl;
	}
protected:
private:
};

class south_Banana : public Fruit	//实现关系
{
public:

	south_Banana(Fruit* myFruit)
	{
		ptrFruit = myFruit;
	}

	virtual void getFruit()
	{
		ptrFruit->getFruit();
		cout << "但我是南方香蕉...." << endl;
	}

public:
	Fruit* ptrFruit;
};

class big_Banana : public Fruit	//实现关系
{
public:
	big_Banana(Fruit* myFruit)
	{
		ptrFruit = myFruit;
	}

	virtual void getFruit()
	{
		ptrFruit->getFruit();
		cout << "但我是大香蕉...." << endl;
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