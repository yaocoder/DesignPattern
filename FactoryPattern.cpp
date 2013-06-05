/*
工厂模式
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

class BeijingVeggiePizza:public Pizza
{
public:

	void Production()
	{
		cout << "Beijing VeggiePizza Prapare.\n";
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

class JinanVeggiePizza:public Pizza
{
public:

	void Production()
	{
		cout << "Jinan VeggiePizza Prapare.\n";
	}
};

class PizzaFactory
{
public:
	virtual Pizza* CreatePizza(string type) = 0;

};

class BeijingPizzaFactory:public PizzaFactory
{
public:
	Pizza* CreatePizza(string type)
	{
		if (0 == type.compare("cheese"))
		{
			pizza_ = new BeijingCheesePizza;
		}
		else if (0 == type.compare("veggie"))
		{
			pizza_ = new BeijingVeggiePizza;
		}
		return pizza_;
	}

private:

	Pizza* pizza_;
};

class JinanPizzaFactory:public PizzaFactory
{
public:
	Pizza* CreatePizza(string type)
	{
		if (0 == type.compare("cheese"))
		{
			pizza_ = new JinanCheesePizza;
		}
		else if (0 == type.compare("veggie"))
		{
			pizza_ = new JinanVeggiePizza;
		}
		return pizza_;
	}

private:

	Pizza* pizza_;
};

int main()
{
	PizzaFactory *beijing = new BeijingPizzaFactory;
	beijing->CreatePizza("veggie")->Production();

	PizzaFactory* jinan = new JinanPizzaFactory;
	jinan->CreatePizza("cheese")->Production();
	system("pause");
	return 0;
}

