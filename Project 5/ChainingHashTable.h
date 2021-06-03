#ifndef CHAINING_H
#define CHAINING_H

#include <vector>
#include <string>
#include <exception>
#include <iostream>
#include "node.h"
#include "HashTable.h"


// Chaining hash table class
class ChainingHashTable: public HashTable {
    private:
    // TODO: insert additional variables needed here
	std::vector< std::vector<node> > chainHash; //2d vector

    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key);
    void printAll(std::string filename);
};

#endif
