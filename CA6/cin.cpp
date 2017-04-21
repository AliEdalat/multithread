#include "cin.h"
#include <iostream>

using namespace std;

void Cin::calculate_result_value(){
	cin>>result_value;
	is_finished=true;
	cout<<"CIN :"<<result_value<<endl;
}