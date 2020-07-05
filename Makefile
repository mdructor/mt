all: format run_tests

format:
	clang-format --verbose -i -style="{BasedOnStyle: Microsoft, IndentWidth: 4}" src/mt.cpp test/test.cpp src/mt.hpp

docs: src/mt.cpp src/mt.hpp
	doxygen

run_tests: tests
	./mt_tests

tests: src/mt.cpp src/mt.hpp test/test.cpp
	g++ test/test.cpp src/mt.cpp -o mt_tests

clean: 
	rm -rf mt_tests docs/
