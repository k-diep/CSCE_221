#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

#include <exception>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class HeapPQ
{
private:
	int s; //size of the array
	int capacity; //maximum amount of the array
	Type* heap;

public:
	HeapPQ(void);

   ~HeapPQ(void);

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

   void print(void);
};

template <class Type> //constructor
HeapPQ<Type>::HeapPQ(void){
	s = -1;
	capacity = 100;
	heap = new Type[capacity];
}

template <class Type> //deconstructor
HeapPQ<Type>::~HeapPQ(void){
	delete[] heap;
}

template <class Type> //returns if the heap is empty or not
bool HeapPQ<Type>::isEmpty(void){
	if (s == -1){
		return true;
	}
	else {
		return false;
	}
}

template <class Type>
int HeapPQ<Type>::size(void){ //return the size of the heap
	return s+1;
}

template <class Type>
void HeapPQ<Type>::insertItem(Type data){
	int sizePQ = size(); //returns size
	if (sizePQ == capacity){ //if the size reaches the capacity of the stack then we go thru this if statement
		capacity = capacity * 2; //increase the capacity size by doubling it
		Type *tempArray = new Type[capacity]; //allocate new tempArray
		for(int i=0; i<sizePQ; i++){ //copy heap to tempArray
			tempArray[i] = heap[i];
		}
		delete[] heap; //delete heap to prevent memory leaks
		heap = tempArray; //array points to tempArray
	}
	s = s+1;
	if(s == -1){ // if the heap is empty,
		heap[0] = data; //then initialize the 0th element to the data(root)
	}
	else{
		heap[s] = data;
		int parentIndex = floor((s-1)/2);
		int childIndex = s;
		Type parent = heap[parentIndex];
		while(data<parent){
			heap[parentIndex] = data; //swapping the parent and the child
			heap[childIndex] = parent;
			childIndex = parentIndex; //new childIndex is the parentIndex
			parentIndex = floor((childIndex-1)/2); //update the parentIndex to be the parent of the new childIndex
			parent = heap[parentIndex]; //update the parent to be the parent of the new child
		}
	}
}

template <class Type>
Type HeapPQ<Type>::removeMin ( void ){
	if(s == -1){ //throwing empty exception
		throw runtime_error("Priority queue is empty");
	}

	Type min = heap[0]; //store the min value

	//swap the last with the min

	heap[0] = heap[s];

	s = s-1;

	int parentIndex = 0; //initialing the parent, leftChild, rightChild and their indexes
	int leftchildIndex = 2*parentIndex + 1;
	int rightchildIndex = 2*parentIndex + 2;


	Type parent = heap[parentIndex];
	Type leftchild = heap[leftchildIndex];
	Type rightchild = heap[rightchildIndex];


	while(((leftchild<=parent) || (rightchild<=parent))  &&  ( (leftchildIndex<=s) ||  (rightchildIndex<=s) ) ){
		if(leftchild<=rightchild){ //if leftChild is less or equal to than rightChild
			heap[leftchildIndex] = parent;
			heap[parentIndex] = leftchild;
			//updating the parent, leftchild, rightchild and their indexes
			parentIndex = leftchildIndex;
			leftchildIndex = 2*parentIndex + 1;
			rightchildIndex = 2*parentIndex + 2;

			parent = heap[parentIndex];
			if(leftchildIndex <= s+1){
				leftchild = heap[leftchildIndex];
			}
			if(rightchildIndex <= s+1){
				rightchild = heap[rightchildIndex];
			}
		}
		else{
			heap[rightchildIndex] = parent;
			heap[parentIndex] = rightchild;
			//updating the parent, leftchild, rightchild and their indexes
			parentIndex = rightchildIndex;
			leftchildIndex = 2*parentIndex + 1;
			rightchildIndex = 2*parentIndex + 2;

			parent = heap[parentIndex];
			if(leftchildIndex <= s+1){
				leftchild = heap[leftchildIndex];
			}
			if(rightchildIndex <= s+1){
				rightchild = heap[rightchildIndex];
			}
		}
	}

	return min;
}

template <class Type>
Type HeapPQ<Type>::minValue ( void ){
	if(s == -1){ //throwing empty exception
		throw runtime_error("Priority queue is empty");
	}
	return heap[0];
}

template <class Type> //print to tes
void HeapPQ<Type>::print(void){
	for(int i = 0; i<s+1 ;++i){
		cout<<heap[i]<< " ";
	}

	cout<<endl;

}


#endif
