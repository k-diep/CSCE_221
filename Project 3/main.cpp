#include <stdio.h>
#include <exception>
#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"


using namespace std;

int main()
{
	



	SortedPQ<int> SPQ;

	SPQ.insertItem(-7);
	SPQ.insertItem(1);
	SPQ.insertItem(2);
	SPQ.insertItem(3);
	SPQ.insertItem(5);
	SPQ.insertItem(4);
	//cout<< UPQ.minValue()<<" " <<UPQ.size()<<endl;
	SPQ.print();
	cout<<endl;
	cout<<SPQ.removeMin()<<" ";
	cout<<SPQ.removeMin()<<" ";
	cout<<SPQ.removeMin()<<" ";
	cout<<SPQ.removeMin()<<" ";
	cout<<SPQ.removeMin()<<" ";
	cout<<SPQ.removeMin()<<" ";

	cout<<endl;
	SPQ.print();
	cout<<endl;

//-----------------------------------------------------------------------------------------------------------------------

	UnsortedPQ<int> UPQ;

	UPQ.insertItem(-7);
	UPQ.insertItem(1);
	UPQ.insertItem(2);
	UPQ.insertItem(3);
	UPQ.insertItem(5);
	UPQ.insertItem(4);
	//cout<< UPQ.minValue()<<" " <<UPQ.size()<<endl;
	UPQ.print();
	cout<<endl;
	cout<<UPQ.removeMin()<<" ";
	cout<<UPQ.removeMin()<<" ";
	cout<<UPQ.removeMin()<<" ";
	cout<<UPQ.removeMin()<<" ";
	cout<<UPQ.removeMin()<<" ";
	cout<<UPQ.removeMin()<<" ";

	cout<<endl;
	UPQ.print();
	cout<<endl;

//------------------------------------------------------------------------------------
	//testing HeapPQ

	HeapPQ<int> HPQ;

	HPQ.insertItem(7);
	HPQ.insertItem(23);
	HPQ.insertItem(9);
	HPQ.insertItem(3);
	HPQ.insertItem(12);
	HPQ.insertItem(5);
	HPQ.insertItem(2);
	HPQ.insertItem(32);
	HPQ.insertItem(6);
	HPQ.insertItem(42);

	HPQ.print();
	cout<<HPQ.minValue()<<endl;
	HPQ.removeMin();
	cout<<HPQ.minValue()<<endl;
	HPQ.removeMin();
	cout<<HPQ.minValue()<<endl;
	HPQ.removeMin();
	cout<<HPQ.minValue()<<endl;
	HPQ.removeMin();
	cout<<HPQ.minValue()<<endl;
	HPQ.removeMin();
	cout<<HPQ.minValue()<<endl;
	HPQ.print();
	HPQ.removeMin();
	cout<<HPQ.minValue()<<endl;
	HPQ.print();
	HPQ.removeMin();
	cout<<HPQ.minValue()<<endl;
	HPQ.removeMin();
	cout<<HPQ.minValue()<<endl;
	HPQ.print();

// -------------------------------------------------------------------------------

	//assuming that number.txt is formated correctly
	//and assuming that the number.txt file will be just integers


	ifstream ist{"numbers.txt"};
	int PQimp;
	int sizePQ;

	ist >> PQimp;
	ist >> sizePQ;


	if(PQimp==0){
		UnsortedPQ<int> NumberPQ;
		for(int i=0;i<sizePQ;++i){
			int numberInsert;
			ist>>numberInsert;
			NumberPQ.insertItem(numberInsert);
		}
		cout<<"This is the PQ before removing: ";
		NumberPQ.print();
		cout<<endl<<"These are the numbers being removed: ";
		for(int i=0;i<sizePQ;++i){
			cout<<NumberPQ.removeMin()<<" ";
		}
	}

	if(PQimp==1){
		SortedPQ<int> NumberPQ;
		for(int i=0;i<sizePQ;++i){
			int numberInsert;
			ist>>numberInsert;
			NumberPQ.insertItem(numberInsert);
		}
		cout<<"This is the PQ before removing: ";
		NumberPQ.print();
		cout<<endl<<"These are the numbers being removed: ";
		for(int i=0;i<sizePQ;++i){
			cout<<NumberPQ.removeMin()<<" ";
		}

	}
	if(PQimp==2){
		HeapPQ<int> NumberPQ;
		for(int i=0;i<sizePQ;++i){
			int numberInsert;
			ist>>numberInsert;
			NumberPQ.insertItem(numberInsert);
		}
		cout<<"This is the PQ before removing: ";
		NumberPQ.print();
		cout<<endl<<"These are the numbers being removed: ";
		for(int i=0;i<sizePQ;++i){
			cout<<NumberPQ.removeMin()<<" ";
		}
		cout<<endl;
	}

//-------------------------------------------------------------------------------------------------
/*
	SortedPQ<int> SPQ;

	for(int j = 1; j<=2;j++){
	auto start = std::chrono::high_resolution_clock::now();
	int numberAR = j*10000;
		for(int i = 0; i<numberAR;i++){
			SPQ.insertItem(rand());
		}
		//for(int i = 0; i<numberAR;i++){
		//	SPQ.removeMin();
		//}
		auto finish = std::chrono::high_resolution_clock::now();
		auto elapsed = (finish - start)/1000000;
		std::cout << "Elapsed time for "<< j <<"0000"<<": " << elapsed.count() << " milliseconds\n";
	}

*/


/*
	UnsortedPQ<int> UPQ;

	for(int j = 1; j<=20;j++){
		auto start = std::chrono::high_resolution_clock::now();
		int numberAR = j*10000;
		for(int i = 0; i<numberAR;i++){
			UPQ.insertItem(rand());
		}
		//for(int k = 0; k<numberAR;k++){
		//	UPQ.removeMin();
		//}
		auto finish = std::chrono::high_resolution_clock::now();
		auto elapsed = (finish - start)/1000000;
		std::cout << "Elapsed time for insertion "<< j <<"0000"<<": " << elapsed.count() << " milliseconds\n";
	}
*/



/*
	HeapPQ<int> HPQ;

	for(int j = 1; j<=20;j++){
	auto start = std::chrono::high_resolution_clock::now();
	int numberAR = j*10000;
		for(int i = 0; i<numberAR;i++){
			HPQ.insertItem(rand());
		}
		for(int i = 0; i<numberAR;i++){
			HPQ.removeMin();
		}
		auto finish = std::chrono::high_resolution_clock::now();
		auto elapsed = (finish - start)/1000000;
		std::cout << "Elapsed time for "<< j <<"0000"<<": " << elapsed.count() << " milliseconds\n";
	}
*/
	return 0;
}
