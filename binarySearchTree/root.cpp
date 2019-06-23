// Copyright 2018 Jacob Reola

#include "root.h"

/* Public */

BinarySearchTree::BinarySearchTree(){
    _setRootData(nullptr);
}

bool BinarySearchTree::isEmpty(){
    return _getRootData()==nullptr;
}

int BinarySearchTree::getHeight(){
    return _maxDepth(_getRootData());
}

int BinarySearchTree::getNumberOfNodes(){
    return _totalNodes(_getRootData());
}

struct node* BinarySearchTree::getHead(){
    return _getRootData();
}

struct node* BinarySearchTree:: getEntry(int id){
    return _searchNode(_getRootData(),id);
}

bool BinarySearchTree::addNode(int id, std::string data){
    if (_getRootData() == nullptr){
        _setRootData(_insertNode(_getRootData(),id, data));
        return true;
    }

    else if (_insertNode(_getRootData(),id,data) == nullptr)
        return false;

    return true;
}

bool BinarySearchTree::removeNodeFoSho(int id){
    if (contains(id) != false){
        _removeNode(_getRootData(),id);
        return true;
    }
    return false;
}

bool BinarySearchTree::clear(){
    if (_getRootData() == nullptr)
        return false;

    delete (_getRootData());
    _setRootData(nullptr);
    return true;
}

bool BinarySearchTree::contains(int id){
    if(getEntry(id)==nullptr){
        return false;
    }
    return true;

}

void BinarySearchTree::inOrderTraverse(){
    _inOrder(_getRootData());
}

void BinarySearchTree::preOrderTraverse(){
    _preOrder(_getRootData());

}

void BinarySearchTree::postOrderTraverse() {
    _postOrder(_getRootData());
}

/* Private */

struct node* BinarySearchTree::_newNode(int item, std::string data){
    node* temp = new node;
    temp -> id = item;
    temp -> data = data;
    temp -> left = nullptr;
    temp -> right = nullptr;
    return temp;
}

void BinarySearchTree::_setRootData(struct node* node){
    _root = node;
}

struct node* BinarySearchTree::_getRootData(){
    return _root;
}

struct node* BinarySearchTree :: _insertNode(struct node* current, int id, std::string data) {

    if (current == nullptr) {
        return _newNode(id, data);
    }

    while (current != nullptr) {
        if (id < current->id) {
            if (current->left != nullptr)
                current = current->left;
            else {
                current->left = _newNode(id,data);
                break;
            }
        }
        else if (id > current->id) {
            if (current->right != nullptr)
                current = current->right;
            else {
                current->right = _newNode(id,data);
                break;
            }
        }
        else {
            return nullptr;
        }
    }
    return current;
}

struct node* BinarySearchTree::_searchNode(struct node* current, int id){

    if (current == nullptr || current->id == id)
        return current;

    else if (current->id < id)
        return _searchNode(current->right, id);

    else
        return _searchNode(current->left, id);
}

struct node* BinarySearchTree::_minValueNode(struct node* node){
    struct node* current = node;

    while (current->left !=nullptr){
        current = current -> left;
    }
    return current;
}

struct node* BinarySearchTree::_removeNode(struct node* current, int id) {

    if (current == nullptr)
        return current;

    else if (id < current->id)
        current->left = _removeNode(current->left, id);

    else if (id > current->id)
        current->right = _removeNode(current->right, id);

    else {
        if (current->left == nullptr && current->right == nullptr) { // 2 children
            delete current;
            current = nullptr;

        } else if (current->left == nullptr) {
            struct node *temp = current;
            current = current->right;
            delete temp;

        } else if (current->right == nullptr) {
            struct node *temp = current;
            current = current->left;
            delete temp;

        } else {
            struct node *temp = _minValueNode(current->right);
            current->id = temp->id;
            current->right = _removeNode(current->right, temp->id);
        }
    }
    return current;
}

int BinarySearchTree::_maxDepth(struct node* node){
    if (node == nullptr)
        return 0;

    else {
        int leftDepth = _maxDepth(node->left);
        int rightDepth = _maxDepth(node->right);

        if (leftDepth > rightDepth)
            return (leftDepth + 1);

        else
            return (rightDepth + 1);
    }
}

int BinarySearchTree::_totalNodes(const node *node){

    int count = 1;

    if (node == nullptr)
        return 0;

    if (node->left != nullptr) {
        count += _totalNodes(node->left);
    }
    if (node->right != nullptr) {
        count += _totalNodes(node->right);
    }
    return count;
}

void BinarySearchTree::_inOrder(struct node *current)
{
    if (current != nullptr)
    {
        _inOrder(current->left);
        std::cout<<current->id<<" ";
        _inOrder(current->right);
    }
}

void BinarySearchTree::_preOrder(struct node *current)
{
    if (current != nullptr)
    {
        std::cout<<current->id<<" ";
        _preOrder(current->left);
        _preOrder(current->right);
    }
}


void BinarySearchTree::_postOrder(struct node *current)
{
    if (current != nullptr)
    {
        _postOrder(current->left);
        _postOrder(current->right);
        std::cout<<current->id<<" ";
    }
}
