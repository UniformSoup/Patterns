#pragma once

#include <vector>

template <typename T>
class Observable;

template <typename T>
class Observer
{
		std::vector<Observable<T>*> observing;

	public:

		virtual void update(T const& data) {};
		~Observer()
		{
			for (Observable<T>* observable : observing) observable->remove(this);
		}
};

template <typename T>
class Observable
{
		std::vector<Observer<T>*> observers;

	public:

		void notify(T const& data)
		{
			for (Observer<T>* observer : observers) observer->update(data);
		}
		void add(Observer<T>* observer) { observers.push_back(observer); }
		void remove(Observer<T>* observer)
		{
			observers.erase(
				std::remove(
					observers.begin(),
					observers.end(),
					observer),
				observers.end());
		}
};