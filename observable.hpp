#pragma once

#include "observer.hpp"

class Observable {
public:
	virtual void notify() = 0;
	virtual void add(Observer *obs) = 0;
	virtual ~Observable() {}
};
