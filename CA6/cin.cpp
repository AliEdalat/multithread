#include "cin.h"
#include <iostream>
#include <stdexcept>


using namespace std;

void Cin::calculate_result_value(){
	if(cin>>result_value){

	}else{
		throw runtime_error("Cin functor can not get user number!");
	}
	is_finished=true;
	cout<<"CIN :"<<result_value<<endl;
}