#include "command.hpp"
#include "bulk.hpp"

#include <sstream>
#include <string>

// Class Command

Command::Command(std::string name) : name(name) {}

void Command::handle(Bulk& subject)  {
	Bulk& bulk = subject;
	const std::string separator = (bulk.is_last(this))? "\n" : ", ";
	bulk.get_output() << name << separator;
}

Command::~Command()  {}
