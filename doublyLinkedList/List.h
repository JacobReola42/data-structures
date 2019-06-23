// Copyright 2018 Jacob Reola

#pragma once
#include "Node.h"

class List {

public:

    Node *headptr;
    Node *tailptr;

    // Note: single argument constructors must be marked
    // explicit to avoid unintentional implicit conversions
    explicit List(int);

    bool addNode(Node *, Node *);
    bool deleteHeadNode(Node *);
    bool deleteNode(Node *, int);
    bool deleteMiddleNode(Node *);
    bool deleteTailNode(Node *);
    void printList(Node *);

};
