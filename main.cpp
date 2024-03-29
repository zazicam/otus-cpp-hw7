#include "bulk.hpp"
#include "command.hpp"

#include <iostream>
#include <memory>

int main(int argc, char **argv) {
	size_t N = 3;
	if(argc>=2)
		N = atoi(argv[1]);
	
	Bulk bulk;

	int level = 0;
	
	std::string line;
	while(getline(std::cin, line)) {
		if(line=="{") {
			if(level==0)
				bulk.process();
			++level;
		}
		else if(line=="}") {
			if(level>0)
				--level;
			if(level==0)
				bulk.process();
		}
		else {
			bulk.add(std::make_shared<Command>(line));
			if(level==0 && bulk.count()==N)
				bulk.process();
		}
	}

	if(level==0)
		bulk.process();
	else
		bulk.clear();

	return 0;
}
