#include "bulk.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <chrono>
#include <memory>

// Class Bulk

#include "command.hpp"

Bulk::Bulk() {
}

void Bulk::notify()  {
	for(auto obs : observers) {
		obs->handle(*this);
	}
}

void Bulk::add(smart_ptr obs)  {
	// get time of first command in bulk
	using namespace std::chrono;
	if(count()==0) {
		milliseconds ms = duration_cast< milliseconds > (
			system_clock::now().time_since_epoch()
		);
		time = ms.count();
	}
	observers.push_back(obs);
}

std::stringstream& Bulk::get_output() {
	return output;
}

bool Bulk::is_last(const Command* obs) {
	auto last_iter = --observers.end();	
	return (obs == last_iter->get());
}

void Bulk::process() {
	if(count()==0) return;

	output.str(""); // prepare empty output 
	output<<"bulk: ";
	notify();

	std::cout<<output.str();

	std::stringstream filename;
	filename<<"bulk"<<time<<".log";
	std::ofstream fout(filename.str());
	fout<<output.str();
	fout.close();

	clear(); // clear processed observers
}

size_t Bulk::count() const {
	return observers.size();
}

void Bulk::clear() {
	observers.clear();
}

Bulk::~Bulk() { clear(); }
