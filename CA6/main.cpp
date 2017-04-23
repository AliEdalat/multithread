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
#include "json_reader.h"
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
	//threads_k.push_back(&mom);
	threads_k.push_back(&thth);
	threads_k.push_back(&single);
	Random_scheduler e_scheduler(threads_k);
	e_scheduler.do_threads();
	Json_reader reader("a.json");
	reader.parse_file();
	std::vector<Thread*> thereads=reader.get_threads();
	for (int i = 0; i < thereads.size(); ++i)
	{
		cout<<"json :"<< thereads[i]->get_type()<<' '<<thereads[i]->get_priority()<<endl;

	}
	Scheduler json_sch(thereads);
	cout<<"Json file reading ...!"<<endl;
	json_sch.do_threads();
	return 0;
}