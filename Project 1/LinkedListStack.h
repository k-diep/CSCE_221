
#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include "stackException.h"
#include <iostream>
#include "Node.h"
#include <sstream>
#include <exception>
#include <stdexcept>

using namespace std;

template <class Type>
class LinkedListStack
{

private:
	Node<Type>* head; //head points to the start of linked list
	int sizeList; //holds the maximum capacity of the stack

public: //declarations

    LinkedListStack(void);
   ~LinkedListStack(void);
   bool isEmpty(void);
   int size(void);
   Type top();
   Type pop();
   void push ( Type e );
};

template <class Type>
LinkedListStack<Type>::LinkedListStack(void): head(nullptr), sizeList(0){ //constructor
}

template <class Type>
LinkedListStack<Type>::~LinkedListStack(void){ //deconstructor
	Node<Type>* curr = head;
	while (curr != nullptr) {
	        Node<Type>* deleteNode = curr;
	        curr = curr->next;
	        delete deleteNode;
	}
	head = nullptr;
}

template <class Type>
bool LinkedListStack<Type>::isEmpty(void){ //return true if linkedlist/stack is empty
	return sizeList == 0;
}

template <class Type>
int LinkedListStack<Type>::size(void){ //return size of stack
	return sizeList;
}

template <class Type>
Type LinkedListStack<Type>::top(){ //return the top of the stack
	if ( isEmpty() ){
		throw stackException("Error, the stack is empty");
	}
	else{
	return head->data;
	}
}

template <class Type>
Type LinkedListStack<Type>::pop(){ //pop function
	if ( isEmpty() ){ //error handling
		throw stackException("Error, the stack is empty");
	}
	else{
		sizeList = sizeList - 1; //decrement the sizeList
		Node<Type>* temp = head; //insertfront of singly linked list
		Type dataOfTop = temp->data;
		head = head->next;
		delete(temp); //delete the previous head
		return dataOfTop;

	}
}

template <class Type>
void LinkedListStack<Type>::push( Type e ){ //push function of the stack
	sizeList = sizeList + 1; //increment the sizeList
	Node<Type> *temp = new Node<Type>();
	temp->data = e;
	temp->next = head;
	head = temp;
}
#endif /* LINKEDLISTSTACK_H_ */
