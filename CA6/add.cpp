#include "add.h"

using namespace std;

void Add::calculate_result_value(){
	if(children[0]->get_is_finished() && children[1]->get_is_finished()){
		result_value=children[0]->get_result() + children[1]->get_result();
		is_finished=true;
		cout<<"ADD :"<< children[0]->get_result() <<" + "<<children[1]->get_result()<<endl; 
	}
}