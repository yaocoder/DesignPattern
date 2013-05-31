/*
装饰着模式：动态的将责任加到对象上。想要扩展对象，装饰者提供有利于继承的另一种选择。
*/
#include <iostream>
#include <string>
using namespace std;

class Beverage
{
public:

	virtual double Cost() = 0;

	virtual string GetDescription()
	{
		return description_;
	}

	string description_;
};

class CondimentDecorator:public Beverage
{
public:

	virtual string GetDescription() = 0;

};

class Espresso:public Beverage
{
public:

	Espresso() {description_ = "Espresso";}

	double Cost() { return 1.99;}

};

class DarkRoast:public Beverage
{
public:

	DarkRoast() {description_ = "DarkRoast coffee";}

	double Cost() { return 1.00;}

};

class HouseBlend:public Beverage
{
public:

	HouseBlend() {description_ = "HouseBlend coffee";}

	double Cost() { return 0.89;}

};


class Mocha :public CondimentDecorator
{
public:

	Mocha(Beverage* pBeverage)
	{
		this->pBeverage_ = pBeverage;
	}

	string GetDescription()
	{
		return pBeverage_->GetDescription() + ", Mocha ";
	}

	double Cost()
	{
		return 0.20 + pBeverage_->Cost();
	}

private:

	Beverage* pBeverage_;
};

class Whip :public CondimentDecorator
{
public:

	Whip(Beverage* pBeverage)
	{
		this->pBeverage_ = pBeverage;
	}

	string GetDescription()
	{
		return pBeverage_->GetDescription() + ", Whip ";
	}

	double Cost()
	{
		return 0.10 + pBeverage_->Cost();
	}

private:

	Beverage* pBeverage_;
};

class Soy :public CondimentDecorator
{
public:

	Soy(Beverage* pBeverage)
	{
		this->pBeverage_ = pBeverage;
	}

	string GetDescription()
	{
		return pBeverage_->GetDescription() + ", Soy ";
	}

	double Cost()
	{
		return 0.30 + pBeverage_->Cost();
	}

private:

	Beverage* pBeverage_;
};

int main()
{
	Beverage* pBeverage = new Espresso;
	cout << pBeverage->GetDescription() << " $" << pBeverage->Cost() << endl;

	Beverage* pBeverage2 = new DarkRoast;
	pBeverage2 = new Mocha(pBeverage2);
	pBeverage2 = new Whip(pBeverage2);
	pBeverage2 = new Whip(pBeverage2);
	cout << pBeverage2->GetDescription() << " $" << pBeverage2->Cost() << endl;

	Beverage* pBeverage3 = new HouseBlend;
	pBeverage3 = new Mocha(pBeverage3);
	pBeverage3 = new Soy(pBeverage3);
	pBeverage3 = new Whip(pBeverage3);
	cout << pBeverage3->GetDescription() << " $" << pBeverage3->Cost() << endl;

	system("pause");
	return 0;
}





