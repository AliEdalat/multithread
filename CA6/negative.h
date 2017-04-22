#ifndef NEGATIVE_H
#define NEGATIVE_H

#include "functor.h"

class Negative:public Functor
{
public:
	Negative(Functor* oprand):Functor("negative"){
		children.push_back(oprand);
		is_finished=false;
	}
	Negative():Functor("negative"){
		is_finished=false;	
	}
	void calculate_result_value();
};

#endif