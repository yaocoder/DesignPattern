/*
简单工厂模式： 
*/
#include <iostream>
#include <string>
using namespace std;

class Pizza
{
public:
	virtual void Prapare() = 0;
	virtual void Bake() = 0;
};

class CheesePizza:public Pizza
{
public:

	void Prapare()
	{
		cout << "CheesePizza Prapare.\n";
	}

	void Bake()
	{
		cout << "CheesePizza Bake.\n";
	}
};

class VeggiePizza:public Pizza
{
public:

	void Prapare()
	{
		cout << "VeggiePizza Prapare.\n";
	}

	void Bake()
	{
		cout << "VeggiePizza Bake.\n";
	}
};


class SimplePizzaFactory
{
public:

	static Pizza* CreatePizza(string type)
	{
		if (0 == type.compare("cheese"))
		{
			pizza_ = new CheesePizza;
		}
		else if (0 == type.compare("veggie"))
		{
			pizza_ = new VeggiePizza;
		}

		return pizza_;
	}

private:
	static Pizza* pizza_;
};

Pizza* SimplePizzaFactory::pizza_ = NULL;

int main()
{
	SimplePizzaFactory::CreatePizza("cheese")->Prapare();
	SimplePizzaFactory::CreatePizza("veggie")->Prapare();
	system("pause");
	return 0;
}

