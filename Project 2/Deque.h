#pragma once

#include "Node.h"
#include <assert.h>

template <class Type>
class Deque {
private:
	int s;
	Node<Type>* firstNode;
	Node<Type>* lastNode;

public:

	Deque(){ //constructor
		s = 0;
		firstNode = lastNode = nullptr;
	}

	~Deque() { //deconstructor
		Node<Type>* nextNode;
		while(firstNode!=nullptr){
			nextNode = firstNode->getNext();
			delete firstNode;
			firstNode = nextNode;
		}
	}
	
	bool isEmpty() { //return the boolean value testing if the deque is empty
		if (s==0){
			return true;
		}
			return false;
	}

	int size() { //return s (size of deque)
		return s;
	}

	Type first() {
		if(isEmpty()){ //error when the deque is empty
			assert(false);
		}
		return firstNode->getData();
	}

	Type last() {
		if(isEmpty()){ //error when the deque is empty
			assert(false);
		}
		return lastNode->getData();
	}

	void insertFirst(Type o) {
		s=s+1; //increment size by one
		Node<Type>* newFirstNode = new Node<Type>(o);
		if(firstNode == nullptr){ //if the list is just one node then firstNode and lastNode point to the same node
			firstNode = lastNode = newFirstNode; // this would all point to the same node if the
		}
		else{
			newFirstNode->setNext(firstNode); //algorithm when insert at front
			firstNode->setPrev(newFirstNode);
			firstNode = newFirstNode;
		}
	}

	void insertLast(Type o) {
		s=s+1; //increment size by one
		Node<Type>* newLastNode = new Node<Type>(o);
		if(lastNode == nullptr){ //if the list is just one node then firstNode and lastNode point to the same node
			firstNode = lastNode = newLastNode;
		}
		else{
			newLastNode->setPrev(lastNode); //algorithm when insert at back
			lastNode->setNext(newLastNode);
			lastNode = newLastNode;
		}
	}
	
	Type removeFirst() {
		if(isEmpty()){ //error when the deque is empty
			assert(false);
		}
		s = s - 1; //decrement s by 1
		Type o = firstNode->getData(); //saves the data of firstNode into o
		Node<Type>* temp = firstNode; //temporary node point to firstNode
		firstNode = firstNode->getNext(); // new firstNode is the next node
		if(firstNode == nullptr){ //when the size hits zero, then change the lastNode to nullptr as well.
			lastNode = nullptr;
		}
		else{ //if not empty then the lastNode next pointer is nullptr
			firstNode->setPrev(nullptr);
		}
		delete temp; //delete temp which was the previous firstNode
		return o;
	}

	Type removeLast() {
		if(isEmpty()){ //error when the deque is empty
			assert(false);
		}
		s = s - 1; //decrement s by 1
		Type o = lastNode->getData(); //saves the data of lastNode into o
		Node<Type>* temp = lastNode; //temp hold the lastNode of the linkedlist
		lastNode = lastNode->getPrev(); //lastNode is now the previous node
		if(lastNode == nullptr){
			firstNode = nullptr; //when the size hits zero, then change the firstNode to nullptr as well.
		}
		else{
			lastNode->setNext(nullptr); //if not empty then the lastNode next pointer is nullptr
		}
		delete temp; //delete temp which was the previous lastNode
		return o;
	}
};
