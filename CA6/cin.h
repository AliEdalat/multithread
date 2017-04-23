#ifndef CIN_H
#define CIN_H

#include "functor.h"
#include <iostream>

class Cin :public Functor
{
public:
	Cin():Functor("cin"){is_finished=false;};
	bool completed_oprands(){return true;}
	void calculate_result_value();
};

#endif