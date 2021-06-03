#include "DoubleHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
DoubleHashTable::DoubleHashTable() {
	capacity = 117017;
	doubleHash.resize(capacity);
}

// destructor
DoubleHashTable::~DoubleHashTable() {
	//dont need destructor (using vectors)
}

// inserts the given string key
void DoubleHashTable::insert(std::string key, int val) {
	size = size + 1; //increment the size

	int index = hash(key); //finding the index using the key
	int hash1 = index;
	int hash2 = secondHash(key);
	int i = 1;
	node newNode;
	newNode.key = key;
	newNode.val = val;
	while(doubleHash[index].key!= ""){ //searching for an empty element (key = "" by default)
			index = (hash1 + i*hash2) % capacity;

			i = i + 1;
	}
	doubleHash[index] = newNode;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(std::string key) {
	size = size - 1; //decrement the size

	int index = hash(key); //finding the index using the key
	int hash1 = index;
	int hash2 = secondHash(key);
	int i = 1;

	while(doubleHash[index].key!= key){ //searching for the key
		index = (hash1 + i*hash2) % capacity;

		i = i + 1;
	}
	int frequency = doubleHash[index].val; //saving the val of the node
	//removing the element from the vector
	doubleHash[index].key = "";
	doubleHash[index].val = 0;
	return frequency;
}

// getter to obtain the value associated with the given key
int DoubleHashTable::get(std::string key) {
	int index = hash(key); //finding the index of the key
	int hash1 = index;
	int hash2 = secondHash(key);
	int i = 1;
	while(doubleHash[index].key!= key && doubleHash[index].key != ""){ //searching for the key
		index = (hash1 + i*hash2) % capacity;
		i = i + 1;
	}
	return doubleHash[index].val;
}

// prints number of occurrances for all given strings to a txt file
void DoubleHashTable::printAll(std::string filename) {
	std::string outputFile = filename + ".txt";
	std::ofstream ost{outputFile};
	for(int i = 0; i < capacity; ++i){ //passing thru the hash table
		if(doubleHash.at(i).key != ""){
			ost<< doubleHash.at(i).key << " " << doubleHash.at(i).val << std::endl ;
		}
	}
}

// helper functions 
int DoubleHashTable::secondHash(std::string s) {
	int hash = 0;
	int index = 0;
	for(unsigned int i = 0; i<s.length(); ++i){
		int ascii = int(s[i]);
		int g = 2;
		hash = g*hash + ascii;
	}
	index = 1 + (hash % (capacity-1));
	return index;
	return 0;
}
