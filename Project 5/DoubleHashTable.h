#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include "HashTable.h"
#include "node.h"
#include <vector>


// Double hashing hash table class
class DoubleHashTable : public HashTable {
    private:
    // helper functions
    public:
    int secondHash(std::string s);

    std::vector<node> doubleHash;
    
    public: 
    DoubleHashTable();
    ~DoubleHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key); 
    void printAll(std::string filename);
};

#endif
