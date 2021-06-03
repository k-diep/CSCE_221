#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <exception>
template <class Type>
void merge(Type* arr, int start, int middle, int finish){
	//assume start to middle and middle + 1 is sorted
	int start1 = start; //start of the 1st sorted array
	int start2 = middle +1; //start of the 2nd sorted array
	Type temp[finish - start + 1]; //creating a temp array to write into the stack
	int i = 0;

	while (start1 <= middle && start2 <= finish){
		if(arr[start1]<arr[start2]){ //if the current data of the first part is less than the second
			temp[i] = arr[start1];
			start1 = start1 + 1;
		}
		else{
			temp[i] = arr[start2];
			start2 = start2 + 1;
		}
		i = i + 1; //incrementing the index of the array

		if(start1 > middle){ //inserting remaining values from middle + 1 to finish into temp
			while(start2<=finish){
				temp[i] = arr[start2];
				start2 = start2 + 1;
				i = i + 1;
			}
		}
		if(start2 > finish){ //inserting remaining values from start to middle into temp
			while(start1<=middle){
				temp[i] = arr[start1];
				start1 = start1 + 1;
				i = i + 1;
			}
		}
	}

	//rewriting temp[] into arr
	for(int i = start; i <= finish; i++){
		arr[i] = temp [i-start];
	}

}

template <class Type>
Type* mergesort(Type *arr, int start, int finish){
	int middle;
	if(start < finish){
		middle = (start + finish) / 2;

		//recursively call and divide the sort
		mergesort(arr, start, middle);
		mergesort(arr, middle+1, finish);

		//merging them together
		merge(arr, start, middle, finish);
	}
	return arr;
}

#endif /* MERGESORT_H_ */
