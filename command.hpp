#pragma once

#include <sstream>

#include "observer.hpp"

class Command: public Observer {
	std::string name;
public:
	Command(std::string name);
	virtual void handle(Observable& subject) override;
	virtual ~Command() override;
};
