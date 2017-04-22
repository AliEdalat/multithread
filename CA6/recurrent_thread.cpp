#include "recurrent_thread.h"

using namespace std;

void revert_children(Functor* root){
	root->set_is_finished(false);
	vector<Functor*> children=root->get_children();
	for (int i = 0; i < children.size(); ++i)
	{
		revert_children(children[i]);
	}

}
void Recurrent_thread::revert_functors_state(){
	root_of_functors->set_is_finished(false);
	vector<Functor*> children=root_of_functors->get_children();
	for (int i = 0; i < children.size(); ++i)
	{
		revert_children(children[i]);
	}

}
void Recurrent_thread::do_functor(){
	this->Thread::do_functor();
}