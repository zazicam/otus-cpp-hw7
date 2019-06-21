#include "command.hpp"
#include "bulk.hpp"

#include <sstream>
#include <string>

// Class Command

Command::Command(std::string name) : name(name) {}

void Command::handle(Observable& subject)  {
	Bulk& bulk = dynamic_cast<Bulk&>(subject);
	std::shared_ptr<Observer> pcurrent(this);
	std::string separator = (bulk.is_last(pcurrent))? "\n" : ", ";
	bulk.get_output() << name << separator;
}

Command::~Command()  {}
