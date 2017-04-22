#ifndef IF_ELSE_H
#define IF_ELSE_H

#include "functor.h"

class If:public Functor
{
public:
	If(Functor* condition,Functor* if_branch,Functor* else_branch):Functor("if"){
		children.push_back(condition);
		children.push_back(if_branch);
		children.push_back(else_branch);
		is_finished=false;
	};
	If():Functor("if"){
		is_finished=false;	
	}
	void calculate_result_value();
};

#endif