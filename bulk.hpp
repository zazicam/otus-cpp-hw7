#pragma once

#include <list>
#include <sstream>
#include <memory>

class Command;

using smart_ptr = std::shared_ptr<Command>;

class Bulk {
	std::list<smart_ptr> observers;	
	std::stringstream output;
	int time;

public:
	Bulk();
	void notify(); 
	void add(smart_ptr obs);

	std::stringstream& get_output();
	bool is_last(const Command * obs);

	void process(); 
	size_t count() const; 

	void clear();
	~Bulk();
};
