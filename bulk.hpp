#pragma once

#include <list>
#include <sstream>

class Observable;

class Observer {
public:
	virtual void handle(Observable& subject) = 0;
	virtual ~Observer() {}
};
//------------------------------------------------------------

class Observable {
public:
	virtual void notify() = 0;
	virtual void add(Observer *obs) = 0;
	virtual ~Observable() {}
};
//------------------------------------------------------------

class Bulk: public Observable {
	std::list<Observer*> observers;	
	std::stringstream output;
	int time;

public:
	void notify() override; 
	void add(Observer *obs) override;

	std::stringstream& get_output();
	bool is_last(const Observer* obs);

	void process(); 
	int count(); 

	void clear();
	~Bulk();
};
//------------------------------------------------------------

class Command: public Observer {
	std::string name;
public:
	Command(std::string name);
	virtual void handle(Observable& subject) override;
	virtual ~Command() override;
};
