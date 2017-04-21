#include "functor.h"

using namespace std;

Functor::Functor(string _functor_type){
	functor_type=_functor_type;
	is_finished=false;
}
void Functor::add_child_to_functor(Functor* child){
	children.push_back(child);
}
/*Functor::~Functor(){
	for (int i = 0; i < children.size(); ++i)
	{
		cout<<children[i]->get_type()<<' ';
	}
	cout<<endl;
	if(children.size() != 0){
		for (std::vector<Functor*>::iterator it = children.begin(); it != children.end(); ++it) {
	    	delete *it;
		}
	}
}
*/