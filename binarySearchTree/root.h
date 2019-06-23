// Copyright 2018 Jacob Reola

#include <string>
#include <iostream>

struct node {

    int id;
    std::string data;
    node *left, *right;

};

class BinarySearchTree{

    
public:
    BinarySearchTree();

    bool isEmpty();

    int getHeight();
    int getNumberOfNodes();
    node* getHead();
    node* getEntry(int);

    bool addNode(int, std::string);
    bool removeNodeFoSho(int);
    bool clear();
    bool contains(int);

    void inOrderTraverse();
    void preOrderTraverse();
    void postOrderTraverse();
    
private:
    struct node* _root;
    struct node* _newNode(int, std::string);
    void _setRootData(struct node*);
    struct node* _getRootData();
    struct node* _insertNode(struct node*, int, std::string);
    struct node* _searchNode(node*, int);
    struct node* _minValueNode(struct node*);
    struct node* _removeNode(node*, int);
    int _maxDepth(struct node*);
    int _totalNodes(const node *);

    void _inOrder(node*);
    void _preOrder(node*);
    void _postOrder(node*);



}; // end class


