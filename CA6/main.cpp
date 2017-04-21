#include <iostream>
#include "cout.h"
#include "cin.h"
#include "add.h"
#include "multiply.h"
#include "negative.h"
#include "thread.h"
#include "single_run_thread.h"
#include "scheduler.h"
#include "random_scheduler.h"
#include "priority_scheduler.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Thread* craete_thraed(string type){
	Thread* result;
	if(type == "basic_thread,"){
		return new Thread();
	}else if(type == "singlerun_thread"){
		//result=new single_run_thread();
	}
	return result;
}
int main(){
	Cin in;
	Cin ine;
	Cin inee;
	Cin ip;
	Cin yu;
	Cout rrrr;
	Add bbbbb(&ip,&yu);
	rrrr.add_child_to_functor(&bbbbb);
	Thread ere(&rrrr);
	ere.set_priority(5);
	//in.calculate_result_value();
	//ine.calculate_result_value();
	
	Cout c;
	Add result(&in, &ine);
	//result.calculate_result_value();
	//inee.calculate_result_value();
	Multiply r(&result,&inee);
	//r.calculate_result_value();
	Negative w(&r);
	//w.calculate_result_value();
	c.add_child_to_functor(&w);
	Thread f(&c);
	f.set_priority(10);
	//TT.do_functor();
	std::vector<Thread*> pp;
	pp.push_back(&f);
	pp.push_back(&ere);
	Random_scheduler s(pp);
	s.do_threads();
	//c.calculate_result_value();
	ifstream input;
	input.open("a.txt");
	string line;
	while (std::getline(input, line))
	{
	    if(line.find("thread_name") != -1){
	    	int found=line.find(':');
	    	string thread_name=line.substr(found+1);
	 		std::getline(input, line);
	 		found=line.find(':');
	 		string thread_type=line.substr(found+1);
	 		cout<<thread_type<<endl;
	 		Thread* t=craete_thraed(thread_type);
	 		cout<<t->get_priority()<<endl;   	
	    }
	}
	return 0;
}