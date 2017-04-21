#ifndef COUT_H
#define COUT_H

#include "functor.h"
#include <iostream>

class Cout :public Functor
{
public:
	Cout():Functor("cout"){is_finished=false;};
	void calculate_result_value();
};

#endif