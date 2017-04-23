#include "cout.h"

using namespace std;

void Cout::calculate_result_value(){
	if(children.size()>0 && children[0]->get_is_finished()){
		result_value=children[0]->get_result();
		is_finished=true;
		cout<<"COUT :";
		cout<<result_value<<endl;
	}else{
		cout<<"ERROR IN COUT NODE!"<<endl;
	}
}
bool Cout::completed_oprands(){
	if(children.size() == 1){
		return true;
	}
	return false;
}