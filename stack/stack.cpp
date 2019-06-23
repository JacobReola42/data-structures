// Copyright 2018 Jacob Reola

#include "stack.h"

/* constructor */
Stack::Stack(const int x):_capacity(x) {
    _stackArray = new DATA* [_capacity];
    //unique_ptr<int[]> _stackArray(new int[_capacity]);
    _count = 0;
    _ids = 1;
}

/* delete memory */
Stack::~Stack() {
    delete _stackArray;
}

/* push values onto the stack */
void Stack::push(DATA* value){
    if (_count < _capacity){
       value->id = _ids;
        _stackArray[_count] = value;
        ++_count;
        ++_ids;
    }

    else {
        std::cout << "Error: stack is full!\n ";
    }
}


/* removes a value from the stack and returns it */
DATA* Stack::pop() {
    if (_count > 0) {
        --_count;
        return _stackArray[_count]; }
    else {
        std::cout << "Error: stack is empty!\n";
    }
    return nullptr;
}

/* finds the top of the stack */
DATA* Stack::peak() {
    if (_count > 0) {
        return _stackArray[_count - 1];
    }
    else {
        std::cout << "Stack is empty.\n";
    return nullptr;
    }
}
