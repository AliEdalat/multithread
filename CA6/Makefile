all:functor.o cin.o cout.o multiply.o add.o negative.o if_else.o thread.o single_run_thread.o recurrent_thread.o scheduler.o random_scheduler.o priority_scheduler.o json_reader.o main.o
	g++  functor.o cin.o cout.o multiply.o add.o negative.o if_else.o thread.o single_run_thread.o recurrent_thread.o scheduler.o random_scheduler.o priority_scheduler.o json_reader.o main.o
	./a.out
main.o:main.cpp
	g++ -c main.cpp
cin.o:cin.cpp cin.h
	g++ -c cin.cpp
cout.o:cout.cpp cout.h
	g++ -c cout.cpp
add.o:add.cpp add.h
	g++ -c add.cpp
negative.o:negative.cpp negative.h
	g++ -c negative.cpp
multiply.o:multiply.cpp multiply.h
	g++ -c multiply.cpp
thread.o:thread.cpp thread.h
	g++ -c thread.cpp
functor.o:functor.cpp functor.h
	g++ -c functor.cpp
if_else.o:if_else.cpp if_else.h
	g++ -c if_else.cpp
single_run_thread.o:single_run_thread.cpp  single_run_thread.h
	g++ -c single_run_thread.cpp
recurrent_thread.o :recurrent_thread.cpp recurrent_thread.h
	g++ -c recurrent_thread.cpp
scheduler.o:scheduler.cpp scheduler.h
	g++ -c scheduler.cpp
random_scheduler.o :random_scheduler.cpp random_scheduler.h
	g++ -c random_scheduler.cpp
priority_scheduler.o :priority_scheduler.cpp priority_scheduler.h
	g++ -c priority_scheduler.cpp
json_reader.o :json_reader.cpp json_reader.h
	g++ -c json_reader.cpp

