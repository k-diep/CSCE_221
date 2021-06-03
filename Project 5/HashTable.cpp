#include "HashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// default constructor
HashTable::HashTable() {
	capacity = 0; //the implementations will change the capacity
	size = 0;
}

// destructor
HashTable::~HashTable() {
	//dont need a destructor for a hash table
}

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(std::string s) { //hash function
	int hash = 0;
	int index = 0;
	for(int i = 0; i<s.length(); ++i){
		int ascii = int(s[i]);
		int g = 2;
		hash = g*hash + ascii;
	}
	index = hash % capacity;
	return index;
}

// returns a boolean of whether the hash table is empty or not
bool HashTable::isEmpty() const {
	if (size == 0){
		return true;
	}
	
	else{
	return false;
	}
}
