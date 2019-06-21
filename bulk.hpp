#pragma once

#include <list>
#include <sstream>
#include <memory>

class Command;

class Bulk {
	std::list<std::shared_ptr<Command>> observers;	
	std::stringstream output;
	int time;

public:
	Bulk();
	void notify(); 
	void add(std::shared_ptr<Command> obs);

	std::stringstream& get_output();
	bool is_last(const Command* obs);

	void process(); 
	size_t count() const; 

	void clear();
	~Bulk();
};
