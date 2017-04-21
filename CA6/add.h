#ifndef ADD_H
#define ADD_H

#include "functor.h"

class Add:public Functor
{
public:
	Add(Functor* first_oprand,Functor* second_oprand):Functor("add"){
		children.push_back(first_oprand);
		children.push_back(second_oprand);
		is_finished=false;
	};
	void calculate_result_value();	
};

#endif