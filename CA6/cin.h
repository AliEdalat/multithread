#ifndef CIN_H
#define CIN_H

#include "functor.h"
#include <iostream>

class Cin :public Functor
{
public:
	Cin():Functor("cin"){is_finished=false;};
	void calculate_result_value();
};

#endif