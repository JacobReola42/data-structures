// Copyright 2018 Jacob Reola 

#include "hash.h"

/* Public */

HashTable::HashTable(const int x):_size(x){
    _count = 0;
    _listTable = new Node*[_size];

    for (int i = 0; i < _size; ++i){
        _listTable[i] = nullptr;
    }
}

bool HashTable::isEmpty(){
    return _count == 0;
}

int HashTable:: getNumberOfEntries(){
    return _count;
}

bool HashTable::add(int key, std::string data){
    int hashCode;
    Node *temp, *current;

    temp = new Node;
    hashCode = _hashFunction(key);

    temp->data.key = key;
    temp->data.data = data;
    temp->next = nullptr;

    current = _listTable[hashCode];

    if (current == nullptr){
        temp->previous = nullptr;
        _listTable[hashCode] = temp;
    }

    else{

        while(current->next != nullptr)
        {
            current = current->next;

        }
        current -> next = temp;
        temp -> previous = current;
    }

    _count++;
    return true;
}

bool HashTable::remove(int key) {
    int hashCode;
    Node *current=nullptr;
    Node* next=nullptr;
    hashCode = _hashFunction(key);

    current = _listTable[hashCode];


    while (current != nullptr){
        if (current->data.key == key){
            _count--;

            next = current->next;


            if (_listTable[hashCode] == current)
                _listTable[hashCode] = current->next;

            else if (current->next != nullptr)
                current->next->previous = current->previous;

            else if (current->previous != nullptr)
                current->previous->next = current->next;

            free(current);
            break;

        }
        else
            current = current->next;

    }

    return false;
}

void HashTable::clear(){
    Node *current;
    for (int i = 0; i < _size; ++i)
    {
        current = _listTable[i];
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete _listTable;
}

std::string HashTable::getValue(int key) {
    int hashCode;
    Node *current;
    hashCode = _hashFunction(key);

    current = _listTable[hashCode];

    while (current != nullptr) {
        if (current->data.key == key) {
            return current->data.data;
        }
        current = current->next;
    }
    return " ";
}

bool HashTable:: contains(int key){
    int hashCode;
    Node *current;
    hashCode = _hashFunction(key);

    current = _listTable[hashCode];

    while (current != nullptr){
        if (current->data.key == key) {
            return true;}
        current = current -> next;
    }
    return false;
}

void HashTable:: traverse()
{
    for (int i = 0; i < _size; ++i)
    {
        std::cout << "[" << i << "]";
        _visit(_listTable[i]);
        std::cout << std::endl;
    }
}


/* Private */

int HashTable::_hashFunction(int key){
    return (key % _size);
}

void HashTable::_visit(Node* node){

    if (node == nullptr){
        return;
    }

    std::cout << " -> " << "[" << node->data.key << ", " << node->data.data << "]";
    _visit(node->next);
}
