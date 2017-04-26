#include "negative.h"
#include <stdexcept>

using namespace std;

void Negative::calculate_result_value(){
	if(children.size()==1 && children[0]->get_is_finished()){
		result_value=(-1)*children[0]->get_result();
		is_finished=true;
		cout<<"NEGATIVE :"<< children[0]->get_result()<<" -> "<< result_value<<endl;
	}
	if(children.size() != 1){
		throw runtime_error("Nagative oparation does not have one oprand!");
	}
}
bool Negative::completed_oprands(){
	if(children.size() == 1){
		return true;
	}
	return false;
}