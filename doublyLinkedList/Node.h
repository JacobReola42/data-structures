// Copyright 2018 Jacob Reola

#pragma once

class Node {

private:

    int _id;         // value
    Node *_forward;  // _forward pointer
    Node *_backward; // _backward pointer

public:

    static int count;   // running count of Nodes

    explicit Node(int);

    int getCount();
    int getId();
    Node *getForward();
    Node *getBackward();

    void setCount(int);
    void setId(int);
    void setForward(Node *);
    void setBackward(Node *);

};
