all: src/mt.cpp test/test.cpp
	g++ src/mt.cpp test/test.cpp -o mt_tests

format:
	clang-format --verbose -i -style="{BasedOnStyle: Microsoft, IndentWidth: 4}" src/mt.cpp test/test.cpp src/mt.hpp

clean: 
	rm mt_tests
