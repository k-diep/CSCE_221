
#ifndef DOUBLING_ARRAY_STACK_H
#define DOUBLING_ARRAY_STACK_H

#include "stackException.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

using namespace std;

template <class Type>
class DoublingArrayStack
{

private:
	int capacity; //holds the maximum capacity of the stack
    int topArray; //holds the index of the stack
    Type* array1;
public: //declarations

    DoublingArrayStack(void);
   ~DoublingArrayStack(void);
   bool isEmpty(void);
   int size(void);
   Type top();
   Type pop();
   void push ( Type e );
};

//class definitions
template <class Type>
DoublingArrayStack<Type>::DoublingArrayStack() : capacity(100), topArray(-1) //class constructor
{ //the constructor for ArrayStack
	array1 = new Type[capacity];
}

template <class Type>
DoublingArrayStack<Type>::~DoublingArrayStack() //deconstructor
{
	delete[] array1;
}

template <class Type>
bool DoublingArrayStack<Type>::isEmpty(void) { //function for checking if the stack is emplty
	return topArray == -1;
}

template <class Type>
int DoublingArrayStack<Type>::size(void) { //returns the size of the stack
	return topArray + 1;
}

template <class Type>
Type DoublingArrayStack<Type>::top(){ //return the top of the stack
	if (topArray == -1){
		throw stackException("Error, the stack is empty");
	}
	else
	return array1[topArray];
}

template <class Type>
Type DoublingArrayStack<Type>::pop(){ //pop function
	if (topArray== -1){ //error statement if the array is empty
		throw stackException("Error, the stack is empty");
	}
		topArray = topArray - 1; //deallocate memory in the stack
		return array1[topArray+1]; //return the top of the stack
}

template <class Type>
void DoublingArrayStack<Type>::push (Type e) { //push function
	int sizeStack = size(); //returns size
	if (sizeStack == capacity){ //if the size reaches the capacity of the stack then we go thru this if statement
		capacity = capacity*2; //increase the capacity size by doubling it
		Type *tempArray = new Type[capacity]; //allocate new tempArray

		for(int i=0; i<sizeStack; i++){ //copy array1 to tempArray
			tempArray[i] = array1[i];
		}
		delete[] array1; //delete array1 to prevent memory leaks
		array1 = tempArray; //array points to tempArray
	}
	topArray = topArray + 1;  //increment topArray by one (allocating memory on the stack)
	array1[topArray] = e; //the new space holds e

}
#endif
