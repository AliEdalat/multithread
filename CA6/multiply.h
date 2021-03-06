#ifndef MULTIPLY
#define MULTIPLY

#include "functor.h"

class Multiply:public Functor
{
public:
	Multiply(Functor* first_oprand , Functor* second_oprand):Functor("multiply"){
		children.push_back(first_oprand);
		children.push_back(second_oprand);
		is_finished=false;
	};
	Multiply():Functor("multiply"){
		is_finished=false;	
	}
	bool completed_oprands();
	void calculate_result_value();	
};

#endif