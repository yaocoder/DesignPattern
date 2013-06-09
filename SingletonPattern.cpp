/*
单例模式：一个类只能拥有一个实例
*/
#include <iostream>
#include <string>
using namespace std;

class Singleton
{
public:

	static Singleton* GetInstance()
	{
		if (NULL == singleton_)
		{
			singleton_ = new Singleton();
		}
		return singleton_;
	}

private:

	static Singleton* singleton_;
};

Singleton* Singleton::singleton_ = NULL;

class SingletonMultiThread
{
public:
	static SingletonMultiThread* GetInstance()
	{
		if (NULL == singleton_)
		{
			/*TODO:同步*/
			if (NULL == singleton_)
			{
				singleton_ = new SingletonMultiThread();
			}
		}

		return singleton_;
	}

private:
	static SingletonMultiThread* singleton_;
};

SingletonMultiThread* SingletonMultiThread::singleton_ = NULL;

int main()
{
	system("pause");
	return 0;
}
