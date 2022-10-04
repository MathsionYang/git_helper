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
	//ÿ���۲��߱���ʵ�ֱ�����������Ӧ�õ�֪ͨ���еĲ���
	virtual void update() = 0;
};



class Subjetct
{
public:
	Subjetct() {}
	~Subjetct() {}
	//ע��۲���
	virtual void registerObserver(ObserveBase* o) = 0;
	//ɾ���۲���
	virtual void removeObserver(ObserveBase* o) = 0;
	//״̬�ı�ʱ֪ͨ���еĹ۲���
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

// ���ǹ۲���Ҳ���������
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

//�����Ĺ۲���
class thirtyProgress : public ObserveBase
{
public:
	thirtyProgress() {}
	~thirtyProgress () {}
	void update() {
		std::cout << "thirty completed!!!!"<<std::endl;
	}

};
//�����Ĺ۲���
class fourthProgress : public ObserveBase
{
public:
	fourthProgress() {}
	~fourthProgress() {}
	void update() {
		std::cout << "fourth completed!!!!" << std::endl;
	}

};

