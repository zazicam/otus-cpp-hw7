#pragma once

#include <list>
#include <sstream>
#include <memory>

#include "observable.hpp"

class Bulk: public Observable {
	std::list<std::shared_ptr<Observer>> observers;	
	std::stringstream output;
	int time;

public:
	Bulk();
	void notify() override; 
	void add(std::shared_ptr<Observer> obs) override;

	std::stringstream& get_output();
	bool is_last(const std::shared_ptr<Observer> obs);

	void process(); 
	int count(); 

	void clear();
	~Bulk();
};
