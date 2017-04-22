#include "single_run_thread.h"

using namespace std;

bool runnable(vector<Functor*> funcotrs ,string type){
	if(funcotrs.size() == 0){
		return true;
	}
	if(type == "if" && funcotrs[0]->get_is_finished() && (funcotrs[1]->get_is_finished() || funcotrs[2]->get_is_finished())){
		return true;
	}
	for (int i = 0; i < funcotrs.size(); ++i)
	{
		//cout<<funcotrs[i]->get_type()<<funcotrs[i]->get_is_finished()<<endl; 
		if(funcotrs[i]->get_is_finished() == false){
			return false;
		}
	}
	return true;
}
void complete_small_part_single_run(Functor* root){
	vector<Functor*> children=root->get_children();
	string type=root->get_type();
	if(!runnable(children,type)){
		for (int i = 0; i < children.size(); ++i)
		{
			if(root->get_type() == "if" && children[0]->get_is_finished()){
				if(children[0]->get_result() == 0 && !children[2]->get_is_finished()){
					//cout<<"ELSE BRANCH !"<<endl;
					complete_small_part_single_run(children[2]);
					continue;

				}
				else if(children[0]->get_result() != 0 && !children[1]->get_is_finished()){
					//cout<<"IF BRANCH !"<<endl;
					complete_small_part_single_run(children[1]);
					continue;
				}else{
					continue;
				}				
			}
			if(!children[i]->get_is_finished()){
				//cout<<children[i]->get_type()<<' ';
				complete_small_part_single_run(children[i]);
			}
		}
		
		if(runnable(children,type)){
			root->calculate_result_value();
			//cout<<root->get_type()<<endl;
			return;
		}
	}else{
		root->calculate_result_value();
		//cout<<root->get_type()<<endl;
		return;
	}
}
void single_run_thread::do_functor(){
	complete_small_part_single_run(root_of_functors);
}