#include <iostream>
#include <string>
using namespace std;

class myrotate
{
public:
	string& set_rotation(string _rotation)
	{
		cout << _rotation << endl;
		return _rotation;
	}

private:
	string rotation;
};

class Expression
{
public:
	virtual void  interpreter(myrotate *r) = 0;
private:
	myrotate		*r;
};

//Ë³Ê±Õë
class PlusExpression : public Expression
{
public:
	virtual void  interpreter(myrotate *r)
	{
		r->set_rotation("Ë³Ê±Õë");
	}
private:
	myrotate *context;
};

//ÄæÊ±Õë
class MinusExpression : public Expression
{
public:
	virtual void  interpreter(myrotate *r)
	{
		r->set_rotation("ÄæÊ±Õë");
	}
};

void main()
{

	Expression		*expression = NULL;
	myrotate			*context = NULL;

	Expression		*expression2 = NULL;

	context = new myrotate();

	expression = new PlusExpression;
	expression->interpreter(context);

	//////////////////////////////////////////////////////////////////////////
	expression2 = new MinusExpression;
	expression2->interpreter(context);

	cout << "hello..." << endl;
	system("pause");
	return;
}