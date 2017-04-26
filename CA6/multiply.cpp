#include "multiply.h"
#include <stdexcept>

using namespace std;

void Multiply::calculate_result_value(){
	if(children.size() == 2 && children[0]->get_is_finished() && children[1]->get_is_finished()){
		result_value=children[0]->get_result() * children[1]->get_result();
		is_finished=true;
		cout<<"MULTIPLY :"<< children[0]->get_result() <<" * "<<children[1]->get_result()<<endl; 
	}
	if(children.size() != 2){
		throw runtime_error("Multiply does not have two oprands!");
	}
}
bool Multiply::completed_oprands(){
	if(children.size() == 2){
		return true;
	}
	return false;
}