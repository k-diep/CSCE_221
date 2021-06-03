
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "stackException.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

using namespace std;

template <class Type>
class ArrayStack
{

private:
    int capacity; //holds the maximum capacity of the stack
    int topArray; //holds the index of the stack
    Type* array1;
public: //declarations

    ArrayStack(void);
   ~ArrayStack(void);
   bool isEmpty(void);
   int size(void);
   Type top();
   Type pop();
   void push ( Type e );
};

//class definitions
template <class Type>
ArrayStack<Type>::ArrayStack() : capacity(100), topArray(-1) //class constructor
{ //the constructor for ArrayStack
	array1 = new Type[capacity];
}

template <class Type>
ArrayStack<Type>::~ArrayStack() //deconstructor
{
	delete[] array1;
}

template <class Type>
bool ArrayStack<Type>::isEmpty(void) { //function for checking if the stack is emplty
	return topArray == -1;
}

template <class Type>
int ArrayStack<Type>::size(void) { //returns the size of the stack
	return topArray + 1;
}

template <class Type>
Type ArrayStack<Type>::top(){ // return the top of the stack
	if (topArray == -1){ //if it is empty then throw this exception
		throw stackException("Error, the stack is empty");
	}
	else
	return array1[topArray];
}

template <class Type>
Type ArrayStack<Type>::pop(){ //pop function
	if (topArray== -1){ //error statement if the array is empty
		throw stackException("Error, the stack is empty");
	}
		topArray = topArray - 1; //deallocate memory in the stack
		return array1[topArray+1]; //return the top of the stack
}

template <class Type>
void ArrayStack<Type>::push (Type e) { //push function
	int sizeStack = size(); //returns size
	if (sizeStack == capacity){ //if the size reaches the capacity of the stack then we go thru this if statement
		capacity = capacity + 100; //increase the capacity size by adding 100
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
