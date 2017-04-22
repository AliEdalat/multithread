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
#include "if_else.h"
#include "recurrent_thread.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main(){
	Cin in;
	Cin ine;
	Cin inee;
	Cin ip;
	Cin yu;
	Add bbbbb(&ip,&yu);
	Cout rrrr(&bbbbb);
	//rrrr.add_child_to_functor(&bbbbb);
	Thread ere(&rrrr);
	ere.set_priority(5);
	//in.calculate_result_value();
	//ine.calculate_result_value();
	
	Add result(&in, &ine);
	//result.calculate_result_value();
	//inee.calculate_result_value();
	Multiply r(&result,&inee);
	//r.calculate_result_value();
	Negative w(&r);
	//w.calculate_result_value();
	Cout c(&w);
	//c.add_child_to_functor(&w);
	Thread f(&c);
	f.set_priority(10);
	//TT.do_functor();
	std::vector<Thread*> pp;
	pp.push_back(&f);
	pp.push_back(&ere);
	Priority_scheduler s(pp);
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
	 		//cout<<thread_type<<endl;
	 		Thread* t=craete_thraed(thread_type);
	 		//cout<<t->get_priority()<<endl;   	
	    }
	}
	Cin ehsan;
	Cin ebi;
	Cin se;
	Cin gir;
	Add sumation(&ehsan,&gir);
	If ali(&sumation,&ebi,&se);
	Cout output(&ali);
	//output.add_child_to_functor(&ali);
	Recurrent_thread mom(&output);
	Cin op1;
	Cin op2;
	Add sum(&op1,&op2);
	Cout zer(&sum);
	Thread thth(&zer);
	Cin first;
	Cin econd;
	Add point(&first,&econd);
	Cout pointer(&point);
	single_run_thread single(&pointer);
	std::vector<Thread*> threads_k;
	threads_k.push_back(&mom);
	threads_k.push_back(&thth);
	threads_k.push_back(&single);
	Random_scheduler e_scheduler(threads_k);
	e_scheduler.do_threads();
	return 0;
}