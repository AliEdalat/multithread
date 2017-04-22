#include "json_reader.h"

using namespace std;

Thread* craete_thraed(string line){
	if(line.find("basic_thread") != -1){
		return new Thread();
	}else if(line.find("singlerun_thread") != -1){
		return new single_run_thread();
	}else{
		return new Recurrent_thread();
	}
}
Functor* create_functor(string line){
	if(line.find("add") != -1){
		return new Add();
	}else if(line.find("cin") != -1){
		return new Cin();
	}else if(line.find("cout") != -1){
		return new Cout();
	}else if(line.find("mul") != -1){
		return new Multiply();
	}else if(line.find("neg") != -1){
		return new Negative();
	}else{
		return new If();
	}
}
Functor* create_functor_tree(vector<Functor*>  functors){

}
Json_reader::Json_reader(string name){
	input_file.open(name.c_str());
	
}
void Json_reader::parse_file(){
	string line;
	while(getline(input_file,line)){
		//string thread_type;
		if(line.find("thread_type") != -1){
			//int find=line.find(':');
			//thread_type=line.substr(find+1);
			threads.push_back(craete_thraed(line));
			create_functor_tree(functors);
		}
		if(line.find("thread_priority") != -1){
			int number;
			std::stringstream stream(line);
			stream>>number;
			threads[threads.size()-1]->set_priority(number)
		}
		if(line.find("functor_type") != -1){
			functors.push_back(create_functor(line));
		}
	}
}