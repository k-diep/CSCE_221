#ifndef NODE_H
#define NODE_H
#include <iostream>

template<typename T>

struct Node {
	Node() : data(0), next(nullptr), prev(nullptr) {}
	Node(T data) : data(data), next(nullptr), prev(nullptr) {}
	T data;
    Node<T>* next;
    Node<T>* prev;
};


#endif
