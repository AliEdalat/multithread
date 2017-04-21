#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <iostream>
#include <vector>

class Functor
{
public:
	Functor(std::string _functor_type);
	bool get_is_finished(){return is_finished;}
	int get_result(){return result_value;}
	std::vector<Functor*> get_children(){return children;}
	void add_child_to_functor(Functor* child);
	virtual void calculate_result_value(){}
	std::string get_type(){return functor_type;}
	//~Functor();
private:
	std::string functor_type;
	
protected:
	bool is_finished;
	int result_value;
	std::vector<Functor*> children;
};

#endif