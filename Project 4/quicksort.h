#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <iostream>

template <class Type>

int partition(Type *arr, int start, int finish){
	Type pivot = arr[finish]; //let the pivot be the last element
	int pivot_index = start;

	for(int i = start; i < finish; ++i){ //
		if(arr[i] <= pivot){
			Type temp = arr[i]; //swapping the two elements
			arr[i] = arr[pivot_index];
			arr[pivot_index] = temp;
			pivot_index = pivot_index + 1;
		}
	}

	arr[finish] = arr[pivot_index]; //swap the last element(pivot) to the pivot_index is
	arr[pivot_index] = pivot;

	return pivot_index;
}

template <class Type>
Type* quicksort(Type* arr, int start, int finish){
	if (start < finish){ //Recurrence relationship
		int pivot_index = partition(arr, start, finish);

		quicksort(arr, start, pivot_index-1);
		quicksort(arr, pivot_index+1, finish);
	}
	return arr;
}

#endif
