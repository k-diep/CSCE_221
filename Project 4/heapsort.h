#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include "Heap.h"
#include <exception>
using namespace std;

template <class Type>
Type* heapsort(Type* arr, int n)
{
	Heap<Type> *heap = new Heap<Type>(arr, n); //constructing the heap using the input array;
	Type* writeArray = new Type[n];//new array to write to

	for(int i=0; i<n; ++i){ //removing min
		Type min = heap->removeMin();
		writeArray[i] = min; //writing min into the new array
	}
	return writeArray;
}
#endif
