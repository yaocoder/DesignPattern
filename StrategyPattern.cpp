/*
策略模式：定义了算法族，分别封装起来，让它们之间可以互相替换，
此模式让算法的变化独立于使用算法的客户。 
*/
#include <iostream>
using namespace std;

class QuackBehavior
{
public:
	virtual void Quack() = 0;
};

class FlyBehavior
{
public:
	virtual void Fly() = 0;
};

class Duck
{
public:
	void Swim()
	{
		cout << "All duck can swim.\n";
	};

	virtual void Display() = 0;

	void PerformQuack()
	{
		pQuackBehavior_->Quack();
	}

	void PerformFly()
	{
		pFlyBehavior_->Fly();
	}

	void SetFlyBehavior(FlyBehavior*	pFlyBehavior)
	{
		pFlyBehavior_ = pFlyBehavior;
	}

	void SetQuackBehavior(QuackBehavior*	pQuackBehavior)
	{
		pQuackBehavior_ = pQuackBehavior;
	}

private:
	
	QuackBehavior*	pQuackBehavior_;
	FlyBehavior*	pFlyBehavior_;	
};



class SqueakDuck:public Duck
{
	void Display()
	{
		cout << "This is a squeak duck.\n";
	}
};

class SqueakSquckBehavior:public QuackBehavior
{
public:
	void Quack()
	{
		cout << "zi zi zi ...\n";
	}
};

class SqueakFlyBehavior:public FlyBehavior
{
public:
	void Fly()
	{
		cout << "Can' fly.\n";
	}
};



int main()
{
	Duck* d = new SqueakDuck;

	d->SetFlyBehavior(new SqueakFlyBehavior);
	d->PerformFly();
	
	d->SetQuackBehavior(new SqueakSquckBehavior);
	d->PerformQuack();

	system("pause");
	return 0;
}

