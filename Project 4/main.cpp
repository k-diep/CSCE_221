#include "Heap.h"
#include "heapsort.h"
#include "bubblesort.h"
#include "mergesort.h"
#include "quicksort.h"
#include <exception>
#include <chrono>
#include <iostream>

using namespace std;

template <class Type> //printing the array
void printArray(Type* arr, int n)
{
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

//---------------------------------------------------------------
	//heapsort testing
	int* heapArray = new int[9];
    for (int i=0; i<10; ++i) {
    	heapArray[i] = rand()%1000;
    }
    int *heap = heapsort<int>(heapArray, 10);
    printArray<int>(heap, 10);
    delete[] heapArray;
    delete[] heap;
//----------------------------------------------------------------
    //bubblesort testing
	int* bubbleArray = new int[9];
    for (int i=0; i<10; ++i) {
    	bubbleArray[i] = rand()%1000;
    }
    int* bubble = bubblesort<int>(bubbleArray, 10);
    printArray<int>(bubble, 10);
    delete[] bubble;
//---------------------------------------------------------------
    //mergesort testing
    int* mergeArray = new int[9];
    for (int i=0; i<10; ++i) {
    	mergeArray[i] = rand()%1000;
    }
    printArray<int>(mergeArray, 10);
    int* merge = mergesort<int>(mergeArray, 0, 9);
    printArray<int>(merge, 10);
    delete[] merge;

//---------------------------------------------------------------
    //quicksort testing
    int* quickArray = new int[19];
    for (int i=0; i<20; ++i) {
    	quickArray[i] = i;
    }
    printArray<int>(quickArray, 20);
    cout<<partition(quickArray, 0, 19)<<endl;
    printArray<int>(quickArray, 20);
    int* quick = quicksort<int>(quickArray, 0, 19);
    printArray<int>(quick, 20);
    delete[] quickArray;
//---------------------------------------------------------------


/*
    for(int i = 1; i<=20;i++){
    	int* heapArray = new int[i*10000]; //allocation an array

    	for(int j = 0; j<i*10000;j++){
    		heapArray[j] = rand();
    	}

    	auto start = std::chrono::high_resolution_clock::now();
    	heapsort(heapArray, i*10000);
    	auto finish = std::chrono::high_resolution_clock::now();
    	auto elapsed = (finish - start)/1000000;
    	cout << "Elapsed time for "<< i <<"0000"<<": " << elapsed.count() << " milliseconds\n";
    	delete[] heapArray;
    }
*/
	/*
    for(int i = 1; i<=20;i++){
    	int* bubbleArray = new int[i*10000]; //allocation an array

    	for(int j = 0; j<i*10000;j++){
    		bubbleArray[j] = i*10000-j;
    	}

    	auto start = std::chrono::high_resolution_clock::now();
    	bubblesort(bubbleArray, i*10000);
    	auto finish = std::chrono::high_resolution_clock::now();
    	auto elapsed = (finish - start)/1000000;
    	cout << "Elapsed time for "<< i <<"0000"<<": " << elapsed.count() << " milliseconds\n";
    	delete[] bubbleArray;
    }
    */
	/*
    for(int i = 1; i<=20;i++){
    	int* mergeArray = new int[i*10000]; //allocation an array

    	for(int j = 0; j<i*10000;j++){
    		mergeArray[j] = rand();
    	}

    	auto start = std::chrono::high_resolution_clock::now();
    	mergesort(mergeArray, 0 , i*10000-1);
    	auto finish = std::chrono::high_resolution_clock::now();
    	auto elapsed = (finish - start)/1000000;
    	cout << "Elapsed time for "<< i <<"0000"<<": " << elapsed.count() << " milliseconds\n";
    	delete[] mergeArray;
    }
    */

    for(int i = 1; i<=3;i++){
    	int* quickArray = new int[i*10000]; //allocation an array

    	for(int j = 0; j<i*10000;j++){
    		quickArray[j] = j;
    	}

    	auto start = std::chrono::high_resolution_clock::now();
    	quicksort<int>(quickArray, 0 , i*10000-1);
    	auto finish = std::chrono::high_resolution_clock::now();
    	auto elapsed = (finish - start)/1000000;

    	cout << "Elapsed time for "<< i <<"0000"<<": " << elapsed.count() << " milliseconds\n";
    	delete[] quickArray;
    }

    return 0;
}
