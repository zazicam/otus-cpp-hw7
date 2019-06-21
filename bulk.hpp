#pragma once

#include <list>
#include <sstream>

#include "observable.hpp"

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
