#include <exception>
#include <chrono>
#include <iostream>
#include <string>
#include "HashTable.h"
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
#include "node.h"
using namespace std;



int main()
{
//---------------------------------------------------------------------------------------------------------------------------------------------
	//random testing
	/*
	vector< vector<int> > chainHash;
	chainHash(4);
	vector<int> Row(2, 5);
	chainHash.push_back(Row);
	chainHash[0].push_back(4);
	cout << chainHash[0][0] << endl;
	cout << chainHash[0][1] << endl;
	cout << chainHash[0][2] << endl;
	*/

	/*
	vector< vector<node> > nodeHash;
	nodeHash.resize(20);
	node newNode;
	newNode.key = "test";
	newNode.val = 1;
	node newNode2;
	newNode2.key = "test2";
	newNode2.val = 2;

	nodeHash[0].push_back(newNode);
	nodeHash[0].push_back(newNode2);
	nodeHash[0].erase(nodeHash[0].begin()+0);
	nodeHash.clear();
	cout<<nodeHash[0].size()<<endl;
	//cout<<nodeHash[0].at(0).key;
	*/
//---------------------------------------------------------------------------------------------------------------------------------------------
	//testing each implementation


	//ChainingHashTable CHT;

	//CHT.insert("marginally", 1);
	//CHT.remove("boy");


	//CHT.printAll("out");


	//ProbingHashTable PHT;

	//PHT.insert("astronaut", 5);
	//PHT.insert("boys", 3);
	//PHT.remove("boys");
	//cout<<PHT.get("apples")<<endl;

	//PHT.printAll("out2");


	//DoubleHashTable DHT;

	//cout <<DHT.secondHash("marginally") <<endl;
	//DHT.get("marginally");
	//DHT.insert("boys", 3);
	//DHT.remove("boys");
	//cout<<DHT.get("apples")<<endl;

	//DHT.printAll("out3");


//---------------------------------------------------------------------------------------------------------------------------------------------
	/*
	//dictionary.txt testing
	string inputfile; //input file
	string word; 	//holds the key temporarily
	ChainingHashTable CHT; // the implementations of the hashtables
	ProbingHashTable PHT;
	DoubleHashTable DHT;
	int frequency; //holds the frequency of the key temporarily


	cout << "What is the input file name (do not include .txt at the end) ? ";
	cin >> inputfile;
	inputfile = inputfile + ".txt"; //adding txt to the end

	ifstream ist{inputfile};
	if(!ist.good()){ //error if the file cannot be opened
		cout<< "Error: file is not open" ;
		exit(1);
	}

	while(!ist.eof()){
		ist >> word; //"word" now hold the current word from the the input file


		frequency = CHT.get(word); //frequency will now be the amount of times the word appears in the hash table
		frequency = frequency + 1; //update the frequency of the key/word
		if(frequency > 1){
			CHT.remove(word);
		}
		CHT.insert(word, frequency);

		/*
		frequency = PHT.get(word); //frequency will now be the amount of times the word appears in the hash table
		frequency = frequency + 1; //update the frequency of the key/word
		if(frequency > 1){
			PHT.remove(word);
		}
		PHT.insert(word, frequency);


		frequency = DHT.get(word); //frequency will now be the amount of times the word appears in the hash table
		frequency = frequency + 1; //update the frequency of the key/word
		if(frequency > 1){
			DHT.remove(word);
		}
		DHT.insert(word, frequency);

	}

	CHT.printAll("Chaining");
	PHT.printAll("Probing");
	DHT.printAll("Double");
	*/
//---------------------------------------------------------------------------------------------------------------------------------------------.
	//timing
	string inputfile; //input file
	string word; 	//holds the key temporarily
	ChainingHashTable CHT; // the implementations of the hashtables
	ProbingHashTable PHT;
	DoubleHashTable DHT;
	int frequency; //holds the frequency of the key temporarily
	inputfile = "dictionary.txt";


		ifstream ist{inputfile};
		auto start = std::chrono::high_resolution_clock::now();
		for(int i = 0;i<200000;++i){
				ist >> word; //"word" now hold the current word from the the input file

				//to time each implementation, uncomment the specific implementation and change the i < _____ in the for loop (inefficent but can repeat cases often)
				/*
				frequency = CHT.get(word); //frequency will now be the amount of times the word appears in the hash table
				frequency = frequency + 1; //update the frequency of the key/word
				if(frequency > 1){
					CHT.remove(word);
				}
				CHT.insert(word, frequency);
				 */
				/*
				frequency = PHT.get(word); //frequency will now be the amount of times the word appears in the hash table
				frequency = frequency + 1; //update the frequency of the key/word
				if(frequency > 1){
					PHT.remove(word);
				}
				PHT.insert(word, frequency);
				*/

				frequency = DHT.get(word); //frequency will now be the amount of times the word appears in the hash table
				frequency = frequency + 1; //update the frequency of the key/word
				if(frequency > 1){
					DHT.remove(word);
				}
				DHT.insert(word, frequency);


			}
		auto finish = std::chrono::high_resolution_clock::now();
	    auto elapsed = (finish - start)/1000000;
	    cout << "Elapsed time: "  << elapsed.count() << " milliseconds\n";


    return 0;
}

