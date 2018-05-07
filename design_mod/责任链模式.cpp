
#include <iostream>
using namespace std;


class track
{
public:
	virtual void track_methed() = 0;
};

class Convexhull : public track
{
public:
	virtual void track_methed()
	{
		cout << "凸包面积法" << endl;
	}
};

class flow : public track
{
public:
	virtual void track_methed()
	{
		cout << "光流法" << endl;
	}
};


class Context
{
public:
	void setStrategy(track *strategy)
	{
		this->strategy = strategy;
	}
	void dotrack()
	{
		strategy->track_methed();
	}

protected:
private:
	track *strategy;
};


void main()
{
	track *strategy = NULL;

	//strategy = new DES;
	strategy = new Convexhull;
	Context *context = new Context;
	context->setStrategy(strategy);
	context->dotrack();

	delete  strategy;
	strategy = new flow();
	context->setStrategy(strategy);
	context->dotrack();

	delete  strategy;
	delete  context;

	cout << "hello..." << endl;
	system("pause");
	return;
}