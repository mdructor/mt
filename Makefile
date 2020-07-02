
all: mt.cpp test.cpp
	g++ mt.cpp test.cpp -o mt_tests

clean: 
	rm mt_tests