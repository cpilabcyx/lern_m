#include <iostream>
using namespace std;

class Fruit
{
public:
	virtual void getFruit() = 0;	//协议类规定的可用接口

protected:
private:
};


class juce_make
{
public:
	void make_product(Fruit* myFruit)	//客户端类，使用接口协议
	{
		myFruit->getFruit();
		cout << "将你榨干！！！\n";
	}
};

class money
{
public:
	void BuyFruit()		//委托类接口
	{
		cout << "有钱没水果，但没有钱买不到的水果，老板来两吨！！！" << endl;
	}

protected:
private:
};


class Banana : public Fruit
{
public:
	Banana(money* t)
	{
		mymoney = t;
	}
	virtual void getFruit()
	{
		mymoney->BuyFruit();	//适配器类，完成接口转化


		cout << "我是买来的大香蕉，请随意使用！！！" << endl;
	}
protected:
private:
	money* mymoney;		//委托类，组合与适配器之中
};

void main()
{
	money* mycash = new money;
	Banana* ptr_b = new Banana(mycash);	
	juce_make* fac = new juce_make();

	fac->make_product(ptr_b);

	delete fac;
	delete ptr_b;
	delete mycash;

	return;
}