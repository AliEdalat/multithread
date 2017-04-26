#include "cout.h"
#include <stdexcept>

using namespace std;

void Cout::calculate_result_value(){
	if(children.size() == 1 && children[0]->get_is_finished()){
		result_value=children[0]->get_result();
		is_finished=true;
		cout<<"COUT :";
		cout<<result_value<<endl;
	}
	if(children.size() != 1){
		throw runtime_error("Cout oparation does not have one oprand!");
	}
}
bool Cout::completed_oprands(){
	if(children.size() == 1){
		return true;
	}
	return false;
}