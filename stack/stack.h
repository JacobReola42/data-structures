// Copyright 2018 Jacob Reola

#include <memory>
#include <string>
#include <iostream>



struct DATA{
    int id; // count id;
    std::string data;
};

class Stack{

public:
    Stack(const int x = 6);
    ~Stack();
    void push (DATA*);
    DATA* pop();
    DATA* peak();

private:
    DATA** _stackArray;
    int _capacity;
    int _count; // top
    int _ids; // use to keep track of ID in struct.
};

