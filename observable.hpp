#pragma once

#include "observer.hpp"

#include <memory>

class Observable {
public:
	virtual void notify() = 0;
	virtual void add(std::shared_ptr<Observer> obs) = 0;
	virtual ~Observable() {}
};
