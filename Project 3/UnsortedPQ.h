#ifndef UNSORTED_PRIORITY_QUEUE_H
#define UNSORTED_PRIORITY_QUEUE_H

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
class UnsortedPQ
{
private:
	int s;
	Node<Type>* head;
	Node<Type>* tail;
public:
	UnsortedPQ(void);

   ~UnsortedPQ(void);

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

//definitions of the class

template <class Type> // default constructor
UnsortedPQ<Type>::UnsortedPQ() {
	s = 0;
	head = nullptr;
	tail = nullptr;
}

template <class Type>
UnsortedPQ<Type>::~UnsortedPQ() { //deconstructor
	Node<Type>* curr = head;
	while (curr != nullptr) {
		Node<Type>* deleteNode = curr;
		curr = curr->next;
		delete deleteNode;
	}
	head = nullptr;
}

template <class Type> //return bool if the pq is empty or not
bool UnsortedPQ<Type>::isEmpty(void){
	if (s == 0){
		return true;
	}
	else {
		return false;
	}
}

template <class Type>
int UnsortedPQ<Type>::size(void){
	return s;
}

template <class Type>
void UnsortedPQ<Type>::insertItem ( Type data ){
	s = s+1;
	Node<Type> *temp = new Node<Type>();
	temp->data = data;
	if(head == nullptr){
		head = tail = temp;
		temp->next = nullptr;
	}
	else{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

template <class Type>
Type UnsortedPQ<Type>::removeMin(){
	if(s == 0){ //throwing empty exception
		throw runtime_error("Priority queue is empty");
	}
	s = s-1;
	Type min = head->data; //min hold the head's data
	Node<Type>* curr = head;
	Node<Type>* deleteNode = head;

	while(curr != nullptr){ //searching for the min
		if(curr->data <= min){
			min = curr->data;
			deleteNode = curr;
		}
		curr = curr->next; //traverse the linked list
	}
	if(deleteNode->prev == nullptr && deleteNode->next == nullptr){
		tail = nullptr;
		head = nullptr;
	}
	else if(deleteNode->prev == nullptr){ //min is at the head
		head = head->next;
		head->prev = nullptr;
	}
	else if(deleteNode->next == nullptr){ //min is at the tail
		tail = tail->prev;
		tail->next = nullptr;
	}
	else{ //min is in the middle
		Node<Type>* prevNode = deleteNode->prev;
		Node<Type>* nextNode = deleteNode->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
	}
	delete deleteNode;
	return min;
}

template <class Type>
Type UnsortedPQ<Type>::minValue(void){
	if(isEmpty()){ //throwing empty exception
		throw runtime_error("Priority queue is empty");
	}
	Type min = head->data; //min hold the head's data
	Node<Type>* curr = head;

	while(curr != nullptr){ //searching for the min
		if(curr->data < min){
			min = curr->data;
		}
		curr = curr->next; //traverse the linked list
	}
	return min;
}

template <class Type>
void UnsortedPQ<Type>::print(void){ //prints the PQ using cout
	Node<Type>* curr = head;

	while (curr != nullptr) {
		cout<< curr->data << " ";
		curr = curr->next;
	}
/*
	Node<Type>* curr2 = tail;
	cout<<endl; //prints tail to head (testing)
	while (curr2 != nullptr) {
		cout<< curr2->data << " ";
		curr2 = curr2->prev;
	}
*/
}
#endif
