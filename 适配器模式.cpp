#include <iostream>
using namespace std;

class Fruit
{
public:
	virtual void getFruit() = 0;	//Э����涨�Ŀ��ýӿ�

protected:
private:
};


class juce_make
{
public:
	void make_product(Fruit* myFruit)	//�ͻ����࣬ʹ�ýӿ�Э��
	{
		myFruit->getFruit();
		cout << "����ե�ɣ�����\n";
	}
};

class money
{
public:
	void BuyFruit()		//ί����ӿ�
	{
		cout << "��Ǯûˮ������û��Ǯ�򲻵���ˮ�����ϰ������֣�����" << endl;
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
		mymoney->BuyFruit();	//�������࣬��ɽӿ�ת��


		cout << "���������Ĵ��㽶��������ʹ�ã�����" << endl;
	}
protected:
private:
	money* mymoney;		//ί���࣬�����������֮��
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