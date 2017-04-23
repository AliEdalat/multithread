#include "multiply.h"

using namespace std;

void Multiply::calculate_result_value(){
	if(children.size() == 2 && children[0]->get_is_finished() && children[1]->get_is_finished()){
		result_value=children[0]->get_result() * children[1]->get_result();
		is_finished=true;
		cout<<"MULTIPLY :"<< children[0]->get_result() <<" * "<<children[1]->get_result()<<endl; 
	}
}
bool Multiply::completed_oprands(){
	if(children.size() == 2){
		return true;
	}
	return false;
}