#pragma once

#include <sstream>

#include "bulk.hpp"

class Command { 
	std::string name;
public:
	Command(std::string name);
	void handle(Bulk& subject);
	~Command();
};
