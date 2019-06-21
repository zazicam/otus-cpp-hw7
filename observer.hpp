#pragma once

class Observable;

class Observer {
public:
	virtual void handle(Observable& subject) = 0;
	virtual ~Observer() {}
};
