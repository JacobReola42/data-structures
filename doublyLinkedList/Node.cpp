// Copyright 2018 Jacob Reola

#include "Node.h"

Node::Node(int randomInt){
    setId(randomInt);
    setForward(0); // could not use nullptr because of version control
    setBackward(0);
}

Node* Node::getBackward()       { return _backward;}
int   Node::getCount()          { return count;   }
Node* Node::getForward()        { return _forward; }
int   Node::getId()             { return _id;      }

void  Node::setBackward(Node* b){ _backward = b;   }
void  Node::setCount(int cnt)   { count=cnt;      }
void  Node::setForward(Node* f) { _forward = f;    }
void  Node::setId(int randomInt){ _id = randomInt; }
