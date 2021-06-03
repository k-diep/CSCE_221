
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include "ArrayStack.h"
#include "DoublingArrayStack.h"
#include "LinkedListStack.h"
#include "stackException.h"
#include "StopWatch.h"


int main()
{

// ...................... testing ArrayStack
	ArrayStack<int> stack1;

	//testing the isEmpty function
	if (stack1.isEmpty() == TRUE){
		cout << "The ArrayStack is empty"<<endl;
	}

	//testing the push function
	for(int i = 0; i<101;i++){
		stack1.push(i);
	}

	//testing the size() function (should be 101)
	std::cout<<stack1.size()<<endl;

	//testing pop and top
	std::cout<<stack1.pop()<<" "<<stack1.top()<<" "<<stack1.pop()<<" "<<stack1.top()<<" "<<stack1.pop()<<" "<<endl<<endl;


// ...................... testing DoublingArrayStack

	DoublingArrayStack<int> stack2;

	//testing the isEmpty function
	if (stack2.isEmpty() == TRUE){
		cout << "The DoublingArrayStack is empty"<<endl;
	}

	//testing the push function
	for(int i = 0; i<201;i++){
		stack2.push(i);
	}

	//testing the size() function (should be 201)
	std::cout<<stack2.size()<<endl;

	//testing pop and top
	std::cout<<stack2.pop()<<" "<<stack2.top()<<" "<<stack2.pop()<<" "<<stack2.pop()<<" "<<stack2.pop()<<endl<<endl;


// ...................... testing LinkedListStack
	LinkedListStack<int> stack3;
	//testing the isEmpty function
	if (stack3.isEmpty() == TRUE){
		cout << "The LinkedListStack is empty"<<endl;
	}

	//testing the push function
	for(int i = 0; i<301;i++){
		stack3.push(i);
	}

	//testing the size() function (should be 201)
	std::cout<<stack3.size()<<endl;

	//testing pop and top
	std::cout<<stack3.pop()<<" "<<stack3.top()<<" "<<stack3.pop()<<" "<<stack3.top()<<" "<<stack3.pop()<<endl<<endl;

// the timing block
	auto start = std::chrono::high_resolution_clock::now();
	//clock_t start = clock();
	for(int i = 0; i<200000;i++){
		stack1.push(i);
	}
	auto finish = std::chrono::high_resolution_clock::now();
	auto elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " nano seconds\n";





}

