/*
观察者模式：在对象之间定义一对多的依赖，这样一来，
当一个对象状态改变，依赖它的对象都会收到通知，并自动更新
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observer
{
public:

	virtual void Update(float temperature, float humidity, float pressure) = 0;
};

class DisplayElement
{
public:

	virtual void Display() = 0;

};


class Subject
{
public:

	virtual void RegisterObserver(Observer* pObserver) = 0;

	virtual void RemoveObserver(Observer* pObserver) = 0;

	virtual void NotifyObservers() = 0;
};

class WeatherData:public Subject
{
public:

	void RegisterObserver(Observer* pObserver)
	{
		vec_pObserver_.push_back(pObserver);
	}

	void RemoveObserver(Observer* pObserver)
	{
		vec_pObserver_.erase(remove(vec_pObserver_.begin(), vec_pObserver_.end(), pObserver), vec_pObserver_.end());
	}

	void NotifyObservers()
	{
		vector<Observer*>::iterator iter;
		for(iter = vec_pObserver_.begin(); iter != vec_pObserver_.end(); ++iter)
		{
			(*iter)->Update(temperature_, humidity_, pressure_);	
		}
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(float temperature, float humidity, float pressure)
	{
		this->temperature_	= temperature;
		this->humidity_		= humidity;
		this->pressure_		= pressure;
		MeasurementsChanged();
	}

private:

	vector<Observer*> vec_pObserver_;

	float temperature_, humidity_, pressure_;

};

class CurrentConditionsDisplay:public Observer, DisplayElement
{
public:

	CurrentConditionsDisplay(WeatherData* pWeatherData)
	{
		pWeatherData->RegisterObserver(this);
	}

		void Update(float temperature, float humidity, float pressure)
	{
		this->temperature_	= temperature;
		this->humidity_		= humidity;
		this->pressure_		= pressure;
		Display();
	}

	void Display()
	{
		cout << "CurrentConditionsDisplay temperature = " << temperature_ << ", humidity = "
			<< humidity_ << ", pressure = " << pressure_ << endl;
	}

private:

	float temperature_, humidity_, pressure_;

};

class StatisticsDisplay:public Observer, DisplayElement
{
public:

	StatisticsDisplay(WeatherData* pWeatherData)
	{
		pWeatherData->RegisterObserver(this);
	}

	void Update(float temperature, float humidity, float pressure)
	{
		this->temperature_	= temperature;
		this->humidity_		= humidity;
		this->pressure_		= pressure;
		Display();
	}

	void Display()
	{
		cout << "StatisticsDisplay temperature = " << temperature_ << ", humidity = "
			<< humidity_ << ", pressure = " << pressure_ << endl;
	}

private:

	float temperature_, humidity_, pressure_;

};

int main()
{
	WeatherData* pWeather = new WeatherData;
	CurrentConditionsDisplay *pCu = new CurrentConditionsDisplay(pWeather);
	StatisticsDisplay *pSa = new StatisticsDisplay(pWeather);

	pWeather->SetMeasurements(80, 65, 30.1f);
	system("pause");
	return 0;
}



