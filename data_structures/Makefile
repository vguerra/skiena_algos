CC=clang
CXX=clang++

CXXFLAGS=-std=c++11 -g -v
CTAGS=/usr/local/bin/ctags -R

INCLUDES=-I/usr/local/repos/Catch/single_include

CXXFLAGS+=$(INCLUDES)

SOURCES=$(ls *cpp)

all: 3_1 darray darray_test 

darray: dynamic_array.cc 
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

darray_test: darray dynamic_array_test.cc
	$(CXX) $(CXXFLAGS) darray dynamic_array_test.cc -o $@

3_1: 3_1.cc
	$(CXX) $(CXXFLAGS) 3_1.cc -o $@

clean:
	rm -rf *dSYM 3_1 darray darray_test

tags:
	$(CTAGS) *

.PHONY : tags
