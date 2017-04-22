#ifndef JSON_READER_h
#define JSON_READER_h

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
#include <cstdlib>

class Json_reader
{
public:
	Json_reader(std::string name);
	void parse_file();
	std::vector<Thread*> get_threads(){return threads;}
private:
	std::ifstream input_file;
	std::vector<Thread*> threads;
	std::vector<Functor*> functors;
};

#endif