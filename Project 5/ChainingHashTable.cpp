#include "ChainingHashTable.h"


///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable() {
	capacity = 117017; //updating capacity to be more than double the number of entries and
	chainHash.resize(capacity);

//	for(int i = 0; i<capacity; ++i){
//		std::vector<node> tempColumns;
//		chainHash.push_back(tempColumns);
//	}
}

// destructor
ChainingHashTable::~ChainingHashTable() {
	//dont need destructor (using vectors)
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	size = size + 1; //increment the size
	node newNode;
	newNode.key = key;
	newNode.val = val;

	int index = hash(key); //finding the index using the key
	chainHash[index].push_back(newNode); //push back the newNode from the index of the

}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	size = size - 1; //decrement the size

	int index = hash(key); //finding the index of the key
	int indexSize = chainHash[index].size(); //size of the "chain" (size of the vector at the index)

	for(int i = 0; i < indexSize; ++i){ //passing thru the chain finding the key
		if(chainHash[index].at(i).key == key){
			int frequency = chainHash[index].at(i).val; //saving the val of the node

			//removing the node from the hash table
			//chainHash[index].erase(chainHash[index].begin()+i);
			chainHash[index].at(i).key = "";
			chainHash[index].at(i).val = 0;
			return frequency; //returning the val of the node
		}
	}

	//if the for loop fully passed but didn't return then the key was not in the hash table thus we throw an error
	throw std::runtime_error( "Key not found (not in the hash table" );


}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {
	int index = hash(key); //finding the index of the key
	int indexSize = chainHash[index].size(); //size of the "chain" (size of the vector at the index)
	for(int i = 0; i < indexSize; ++i){ //passing thru the chain finding the key
		if(chainHash[index].at(i).key == key){
			int frequency = chainHash[index].at(i).val; //saving the val of the node
			return frequency; //returning the val of the node
		}
	}
	//if the for loop fully passed but didn't return then the key was not in the hash table thus we return 0, which represent the key not being in the hash table
	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {

	std::string outputFile = filename + ".txt";
	std::ofstream ost{outputFile};

	//writing to the file
	for(int i = 0; i < capacity; ++i){ //passing thru the hash table
		int indexSize = chainHash[i].size(); //size of the "chain" (size of the vector at the index)
		for(int j = 0; j < indexSize; ++j){
			if(chainHash.at(i).at(j).key != ""){
				ost<< chainHash.at(i).at(j).key << " " << chainHash.at(i).at(j).val << std::endl ;
			}
		}
	}
}
