// Copyright 2018 Jacob Reola


#include "dict.h"
#include <fstream>

struct Node {
    Dict data;
    Node *next, *previous;
};

class HashTable {

public:
    HashTable(const int x = 19);
    bool isEmpty();
    int getNumberOfEntries();
    bool add(int, std::string);
    bool remove(int);
    void clear();
    std::string getValue(int);
    bool contains (int);
    void traverse();


private:
    Node **_listTable;
    void _visit (Node*);
    int _hashFunction(int);
    int _size;
    int _count;
};
