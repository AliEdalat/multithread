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
void create_functor_tree(vector<Functor*>  functors){
	int index=functors.size()-1;
	if(functors.size() > 1){
		for (int i = functors.size()-2; i >=0 ; i--)
		{
			if(functors[i]->completed_oprands() == false){
				cout<<"father :"<<functors[i]->get_type()<<endl;
				cout<<"child :"<<functors[index]->get_type()<<endl;
				functors[i]->add_child_to_functor(functors[index]);
				break;
			}
		}
	}

}
Json_reader::Json_reader(string name){
	input_file.open(name.c_str());
	
}
void Json_reader::parse_file(){
	string line;
	bool seen_thraed=false;
	while(getline(input_file,line)){
		//string thread_type;
		if(line.find("thread_type") != -1){
			for (int i = 0; i < functors.size(); ++i)
			{
					cout<<i<<')'<<functors[i]->get_type()<<endl;
					std::vector<Functor*> children_op=functors[i]->get_children();
					for (int i = 0; i < children_op.size(); ++i)
					{
						cout<<"child :"<<i<<')'<<functors[i]->get_type()<<endl;
					}
			}
			//int find=line.find(':');
			//thread_type=line.substr(find+1);
			cout<<"Thread :"<<line<<endl;
			if(seen_thraed == true){
			//	create_functor_tree(functors);
				
				threads[threads.size()-1]->add_root(functors[0]);
				functors.clear();
				seen_thraed=false;
			}
			threads.push_back(craete_thraed(line));
			seen_thraed=true;
		}
		if(line.find("thread_priority") != -1){
			int number;
			std::stringstream stream(line);
			stream>>number;
			threads[threads.size()-1]->set_priority(number);
		}
		if(line.find("functor_type") != -1){
			cout<<"Functor :"<<line<<endl;
			functors.push_back(create_functor(line));
			create_functor_tree(functors);
		}
	}
	if(seen_thraed == true){
			//	create_functor_tree(functors);
				for (int i = 0; i < functors.size(); ++i)
			{	
					cout<<i<<')'<<functors[i]->get_type()<<endl;
					std::vector<Functor*> children_op=functors[i]->get_children();
					for (int j = 0; j < children_op.size(); ++j)
					{
						cout<<"child :"<<j<<')'<<functors[j]->get_type()<<endl;
					}
			}
				threads[threads.size()-1]->add_root(functors[0]);
				functors.clear();
				seen_thraed=false;
			}
}