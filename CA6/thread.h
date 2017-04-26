#ifndef THREAD_H
#define THREAD_H

#include "functor.h"
#include <iostream>
#include <stdexcept>

class Thread
{
public:
	Thread(Functor* root);
	Thread();
	bool get_is_finished(){return root_of_functors->get_is_finished();}
	void set_priority(int number);
	int get_priority(){return priority;}
	std::string get_type(){return type;}
	void add_root(Functor* _root){root_of_functors=_root;}
	virtual void revert_functors_state(){};
	virtual void do_functor();
	~Thread();
protected:
	int priority;
	std::string type;
	Functor* root_of_functors;
	
};

#endif