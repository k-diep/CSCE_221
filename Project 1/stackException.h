#ifndef STACK_EXCEPTION_H
#define STACK_EXCEPTION_H
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

class Exception: public std::runtime_error {
	public:
	StackException(const char* se) : runtime_error(se) {}
};
#endif

example

if(condition){
	throw StackException("Error, the stack is empty")
}
