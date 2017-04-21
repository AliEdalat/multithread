all:functor.o cin.o cout.o multiply.o add.o negative.o thread.o main.o
	g++ functor.o cin.o cout.o multiply.o add.o negative.o thread.o main.o
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

