all: src/mt.cpp test/test.cpp
	g++ src/mt.cpp test/test.cpp -o mt_tests

clean: 
	rm mt_tests
