#ifndef SORTED_PRIORITY_QUEUE_H
#define SORTED_PRIORITY_QUEUE_H

#include <iostream>
#include <exception>
#include "Node.h"

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class SortedPQ
{
private:
	int s;
	Node<Type>* head;
	Node<Type>* tail;
public:
	SortedPQ(void);

   ~SortedPQ(void);

   bool isEmpty(void);

   int size(void);

   // inserts a piece of data into the priority queue
   void insertItem ( Type data );

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void );

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void );
   void print(void); //use for testing (prints the PQ)
};

template <class Type> // default constructor
SortedPQ<Type>::SortedPQ() {
	s = 0;
	head = nullptr;
	tail = nullptr;
}

template <class Type>
SortedPQ<Type>::~SortedPQ() { //deconstructor
	Node<Type>* curr = head;
	while (curr != nullptr) {
		Node<Type>* deleteNode = curr;
		curr = curr->next;
		delete deleteNode;
	}
	head = nullptr;
}

template <class Type> //return if the PQ is empty
bool SortedPQ<Type>::isEmpty(void){
	if (s == 0){
		return true;
	}
	else {
		return false;
	}
}

template <class Type> //returns the size
int SortedPQ<Type>::size(void){
	return s;
}

template <class Type> //inserts an item
void SortedPQ<Type>::insertItem ( Type data ){
	s = s+1;
	Node<Type> *newNode = new Node<Type>();
	newNode->data = data;

	if (head == nullptr){ // if the PQ is empty
		head = newNode;
		tail = newNode;
	}
	else{
		if(newNode->data < head->data){ // if the data is less than the head's data
			newNode->next = head;
			head->prev = newNode; // we will insert at the front
			head = newNode;
		}
		else if(newNode->data > tail->data){ // if the data is more than the tail's data
			newNode->prev = tail;
			tail->next = newNode; // we will insert at the back
			tail = newNode;
		}
		else{
			Node<Type>* curr = head; //inserting at the middle
			while(curr->next->data < data){ // finding the node before the insertion
				curr = curr->next; //traverse the linked list
			}
			Node<Type>* nextNode = curr->next; //hold the nextNode to prevent memory leaks
			curr->next = newNode; //updating the pointers
			newNode->prev = curr;
			newNode->next = nextNode;
			nextNode->prev = newNode;
		}
	}
}

template <class Type>
Type SortedPQ<Type>::removeMin ( void ){
	if(s == 0){ //throwing empty exception
		throw runtime_error("Priority queue is empty");
	}

	Type min = head->data;
	Node<Type>* curr = head;
	Node<Type>* deleteNode = curr;
	curr = curr->next;
	delete deleteNode;
	head = curr;

	s = s-1;
	return min;
}

template <class Type>
Type SortedPQ<Type>::minValue ( void ){
	return head->data;
}
template <class Type>
void SortedPQ<Type>::print(void){ //prints the PQ using cout
	Node<Type>* curr = head;

	while (curr != nullptr) {
		cout<< curr->data << " ";
		curr = curr->next;
	}

}
#endif
