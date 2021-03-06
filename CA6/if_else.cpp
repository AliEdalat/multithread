#include "if_else.h"
#include <stdexcept>

using namespace std;


void If::calculate_result_value(){
	if(children.size() == 3 && children[0]->get_is_finished()){
		if(children[0]->get_result() != 0 && children[1]->get_is_finished()){
			result_value=children[1]->get_result();
			is_finished=true;
		}
		if(children[0]->get_result() == 0 && children[2]->get_is_finished()){
			result_value=children[2]->get_result();
			is_finished=true;
		}
	}
	if( children.size() != 3){
		throw runtime_error("If functor does not have three branches!");
	}
}
bool If::completed_oprands(){
	if(children.size() == 3){
		return true;
	}
	return false;
}