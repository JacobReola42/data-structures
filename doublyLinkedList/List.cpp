// Copyright 2018 Jacob Reola

#include "List.h"
#include "main.h"

int Node::count=0;

List::List(int sizeOfList){

    // Seed a random generator from time
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i=0; i<sizeOfList; ++i) {
        int randomInt=rand()%8999+1001;
        Node *temp=new Node(randomInt);
        addNode(headptr,temp);
    }
}

bool List::addNode(Node *head, Node *newNode)
{
    // Declare variables
    Node* current;

    // If list is empty
    if (head == nullptr){
        head = newNode;
        headptr = tailptr = newNode;
    }

    // Insert node at beginning of list if ID is least
    else if (head->getId() >= newNode->getId()) {
        newNode->setForward(head);
        newNode->getForward()->setBackward(newNode);
        head = newNode;
        headptr = newNode;
    }

    // Insert node after first node
    else {
        current = head;

        // Locate the node after which the new node
        // is to be inserted
        while (current->getForward() != nullptr &&
               current->getForward()->getId() < newNode->getId()) {
            current = current->getForward();
        }

        /* Make the appropriate links */
        newNode->setForward(current->getForward());

        // If node inserts between nodes
        if (current->getForward() != nullptr) {
            newNode->getForward()->setBackward(newNode);
        }
        // If insertion is at end of list
        else {
            current->setBackward(tailptr);
            tailptr = newNode;
        }

        // Adjust links
        current->setForward( newNode);
        newNode->setBackward(current);
    }

    headptr->setCount(headptr->getCount()+1);
    headptr = head;

    return true;
}

bool List::deleteHeadNode(Node *current){

    // If List is empty
    if(current == nullptr){
        std::cout<<"list is empty\n";
        return false;
    }

    // If List hold only one Node
    else if (headptr->getCount() == 1) {
        headptr = tailptr = nullptr;
        headptr->setCount(0);
        delete (current);
        return true;
    }

    // If list holds more than one Node
    else {
        headptr=current->getForward();
        headptr->setBackward(nullptr);

        delete (current);
        headptr->setCount(headptr->getCount()-1);

        return true;
    }
}

bool List::deleteMiddleNode(Node* current){

    // Declare variables
    int count = headptr->getCount();

    // If List is empty
    if(current == nullptr){
        std::cout<<"\nlist is empty...\n";
        return false;
    }

    // If List is less than 3 nodes, delete current Node
    if (count < 3){
        deleteHeadNode(current);
        return true;
    }

    // If count is 3, delete second Node
    else if (count == 3) {
        current = current->getForward();
        current->getForward()->setBackward(current->getBackward());
        current->getBackward()->setForward(current->getForward());
        delete (current);
        headptr->setCount(2);
    }

    // If count is greater than 3, binary search
    else {
        int midNode = count/2;

        for (int i = 1; i < midNode; ++i) {
            current = current->getForward();
        }

        // adjust links
        current->getForward()->setBackward(current->getBackward());
        current->getBackward()->setForward(current->getForward());

        delete (current);
        headptr->setCount(headptr->getCount()-1);

        return true;
    }

    // control may reach end of non-void function [-Wreturn-type]
    return false;
}

bool List::deleteNode(Node *current, int key){

    // If list is empty
    if (current == nullptr) {
        return false;
    }

    // If current holds key
    else if (current->getId() == key) {
        deleteHeadNode(current);
        return true;
    }

    // If tail holds key
    else if (tailptr->getId() == key) {
        deleteTailNode(current);
        return true;
    }

    // Search in List
    else {
        // Traverse to find node with key
        while (current->getId() != key &&
               current->getForward() != tailptr->getForward()) {

            current = current->getForward();

            // If current node holds key
            if (current->getId() == key) {
                // Adjust links
                current->getForward()->setBackward(current->getBackward());
                current->getBackward()->setForward(current->getForward());

                delete (current);
                headptr->setCount(headptr->getCount() - 1);
                return true;
            }
        } // END while traverse

        // If key not found
        std::cout<<"Key"<<SPACE<<key<<SPACE<<"not found...\n";
        return false;
    }
}

bool List::deleteTailNode(Node* head){

    // If List is empty
    if (head == nullptr) {
        std::cout<<"\nlist is empty...\n";
        return false;
    }

    // If List holds only one node
    else if (headptr->getCount() == 1) {
          deleteHeadNode(head);
          return true;
    }

    // If List holds more than one Node
    else {
        head = tailptr;
        tailptr = tailptr->getBackward();
        tailptr->setForward(nullptr);

        delete (head);
        headptr->setCount(headptr->getCount()-1);

        return true;
    }
}

void List::printList(Node* head) {

    // If list is empty
    if (head==nullptr) {
        std::cout<<"list is empty...\n";
    } else {
        Node* traverse = head;
        for (int i = 0; i < head->getCount(); ++i) {
            std::cout << traverse->getId() << std::endl;
            traverse = traverse->getForward();
        }
    }
}
