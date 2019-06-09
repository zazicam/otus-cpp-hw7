#include "bulk.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <chrono>

// Class Bulk

void Bulk::notify()  {
	for(auto obs : observers) {
		obs->handle(*this);
	}
}

void Bulk::add(Observer *obs)  {
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

bool Bulk::is_last(const Observer* obs) {
	auto last_iter = --observers.end();	
	return (obs == *last_iter);
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

int Bulk::count() {
	return observers.size();
}

void Bulk::clear() {
	for(auto obs : observers)
		delete obs;
	observers.clear();
}

Bulk::~Bulk() { clear(); }
// -------------------------------------------------------------

// Class Command

Command::Command(std::string name) : name(name) {}

void Command::handle(Observable& subject)  {
	Bulk& bulk = dynamic_cast<Bulk&>(subject);
	std::string separator = (bulk.is_last(this))? "\n" : ", ";
	bulk.get_output() << name << separator;
}

Command::~Command()  {}
