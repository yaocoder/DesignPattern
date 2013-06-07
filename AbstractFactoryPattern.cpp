/*
抽象工厂模式：生产济南，北京食物的工厂
*/
#include <iostream>
#include <string>
using namespace std;

class Pizza
{
public:
	virtual void Production() = 0;
};

class BeijingCheesePizza:public Pizza
{
public:

	void Production()
	{
		cout << "Beijing CheesePizza production.\n";
	}

};

class JinanCheesePizza:public Pizza
{
public:

	void Production()
	{
		cout << "Jinan CheesePizza production.\n";
	}

};

class Cake
{
public:
	virtual void Production() = 0;
};

class BeijingCheeseCake:public Cake
{
public:

	void Production()
	{
		cout << "Beijing Cake production.\n";
	}

};

class JinanCheeseCake:public Cake
{
public:

	void Production()
	{
		cout << "Jinan Cake production.\n";
	}

};

class Factory
{
public:
	virtual Pizza* CreatePizza() = 0;
	virtual Cake*  CreateCake() = 0;

};

class BeijingFactory:public Factory
{
public:
	Pizza* CreatePizza()
	{
		return new BeijingCheesePizza;
	}

	Cake* CreateCake()
	{
		return new BeijingCheeseCake;
	}
};

class JinanFactory:public Factory
{
public:
	Pizza* CreatePizza()
	{
		return new JinanCheesePizza;
	}

	Cake* CreateCake()
	{
		return new JinanCheeseCake;
	}
};

int main()
{
	BeijingFactory pBf;
	pBf.CreatePizza()->Production();
	pBf.CreateCake()->Production();

	JinanFactory pJf;
	pJf.CreatePizza()->Production();
	pJf.CreateCake()->Production();

	system("pause");
	return 0;
}

