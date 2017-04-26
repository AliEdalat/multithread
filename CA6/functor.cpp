#include "functor.h"

using namespace std;

Functor::Functor(string _functor_type){
	functor_type=_functor_type;
	is_finished=false;
}
void Functor::add_child_to_functor(Functor* child){
	children.push_back(child);
}