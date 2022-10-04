#pragma once
#include <iostream>
#include <list>
#include <stdio.h>
#include "algorithm"
class ObserveBase
{
public:
	ObserveBase(){}
	~ObserveBase() {}
	//每个观察者必须实现本函数，来响应得到通知进行的操作
	virtual void update() = 0;
};



class Subjetct
{
public:
	Subjetct() {}
	~Subjetct() {}
	//注册观察者
	virtual void registerObserver(ObserveBase* o) = 0;
	//删除观察者
	virtual void removeObserver(ObserveBase* o) = 0;
	//状态改变时通知所有的观察者
	virtual void notifyObservers() = 0;
};

class FirstProcress : public Subjetct
{
public:
	FirstProcress() { m_lstObservers.clear(); }
	~FirstProcress() {}
	void registerObserver(ObserveBase* obs)
	{
		m_lstObservers.push_back(obs);
	}
	void removeObserver(ObserveBase* o)
	{
		if (m_lstObservers.size() > 0) {
			m_lstObservers.remove(o);
		}
	}
	void notifyObservers() {

		for (auto obj : m_lstObservers)
		{
			obj->update();
		}
	}
	void wakeUp() {
		std::cout<<"first completed!!!!" << std::endl;
		notifyObservers();
	}



private:
	std::list<ObserveBase*> m_lstObservers;
};

// 既是观察者也是主题对象
class SecondProgress : public ObserveBase,public Subjetct

{
public:
	SecondProgress() { m_lstObservers.clear(); }
	~SecondProgress() {}

	void registerObserver(ObserveBase* obs)
	{
		m_lstObservers.push_back(obs);
	}
	void removeObserver(ObserveBase* o)
	{
		if (m_lstObservers.size() > 0) {
			m_lstObservers.remove(o);
		}
	}
	void notifyObservers() {

		for (auto obj : m_lstObservers)
		{
			obj->update();
		}
	}
	void update() {
		std::cout << "second completed!!!!" << std::endl;
		notifyObservers();
	}
private:
	std::list<ObserveBase*> m_lstObservers;
};

//单纯的观察者
class thirtyProgress : public ObserveBase
{
public:
	thirtyProgress() {}
	~thirtyProgress () {}
	void update() {
		std::cout << "thirty completed!!!!"<<std::endl;
	}

};
//单纯的观察者
class fourthProgress : public ObserveBase
{
public:
	fourthProgress() {}
	~fourthProgress() {}
	void update() {
		std::cout << "fourth completed!!!!" << std::endl;
	}

};

