#include "ProbingHashTable.h"

// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable() {
	capacity = 117017; //updating capacity to be more than double the number of entries and
	probingHash.resize(capacity);
}

// destructor
ProbingHashTable::~ProbingHashTable() {
	//dont need destructor (using vectors)
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	//using linear probing
	size = size + 1; //increment the size

	int index = hash(key); //finding the index using the key
	node newNode;
	newNode.key = key;
	newNode.val = val;
	while(probingHash[index].key!= ""){ //searching for an empty element (key = "" by default)
		index = (index + 1) % capacity;
	}
	probingHash[index] = newNode;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
	size = size - 1; //decrement the size

	int index = hash(key); //finding the index using the key
	while(probingHash[index].key!= key){ //searching for the key
		index = (index + 1) % capacity;
	}
	//saving the val
	int frequency = probingHash[index].val; //saving the val of the node
	//removing the element from the vector
	probingHash[index].key = "";
	probingHash[index].val = 0;
	return frequency;
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) {
	int index = hash(key); //finding the index of the key
	while(probingHash[index].key!= key && probingHash[index].key!= ""){ //searching for the key and stopping if we reach an empty element
		index = (index + 1) % capacity;
	}
	return probingHash[index].val;
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(std::string filename) {
	std::string outputFile = filename + ".txt";
	std::ofstream ost{outputFile};
	for(int i = 0; i < capacity; ++i){ //passing thru the hash table
		if(probingHash.at(i).key != ""){
			ost<< probingHash.at(i).key << " " << probingHash.at(i).val << std::endl ;
		}
	}
}
