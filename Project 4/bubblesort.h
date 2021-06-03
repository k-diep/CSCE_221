#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include <exception>
using namespace std;

template <class Type>
Type* bubblesort(Type* arr, int n){
	bool swap; //to see if we have to swap
	for(int i = 0; i<n; ++i){
		swap = false;
		for(int j = 0; j<n-i-1;++j){
			if(arr[j] > arr[j+1]){
				Type temp = arr[j]; //swapping
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swap = true; //flag swap turns true
			}
		}
		if(swap == false){ //if we didnt swap in the inner for loop then break the outer loop
			break;
		}
	}
	return arr;
}
#endif /* BUBBLESORT_H_ */
