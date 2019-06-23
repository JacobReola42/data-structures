// Copyright 2018 Jacob Reola

#include "stack.h"

int main(int argc, char** argv)
{

    Stack mystack;

    DATA *newData1 = new DATA;
    DATA *newData2 = new DATA;
    DATA *newData3 = new DATA;
    DATA *newData4 = new DATA;
    DATA *newData5 = new DATA;
    DATA *newData6 = new DATA;
    DATA *newData7 = new DATA;

    DATA *peakData;
    DATA *popData;

    newData1->data = "My Array 1.";
    newData2->data = "My Array 2.";
    newData3->data = "My Array 3.";
    newData4->data = "My Array 4.";
    newData5->data = "My Array 5.";
    newData6->data = "My Array 6.";
    newData7->data = "My Array 7.";


    mystack.push(newData1);
    mystack.push(newData2);
    mystack.push(newData3);
    mystack.push(newData4);
    mystack.push(newData5);
    mystack.push(newData6);

    std::cout <<"\nTesting if stack is full . . . \n";
    
    mystack.push(newData7);

    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();

    std::cout << "\nTesting if stack is empty . . .\n";
    mystack.pop();


    std::cout << "\nTesting Random push and pop . . .\n";
    mystack.push(newData5);
    mystack.push(newData6);

    popData = mystack.pop();

    std::cout << "ID:  " << popData->id << ", Data: " << popData->data << std::endl;

    mystack.push(newData3);
    mystack.push(newData7);

    popData = mystack.pop();

    std::cout << "ID: " << popData->id << ", Data: " << popData->data << std::endl;
    std::cout << "\nTesting peak...\n";

    peakData = mystack.peak();

    std::cout << "ID: " << peakData->id << ", Data: " << peakData->data << std::endl;

    std::cout << "\nClosing Program...\n";

    std::cout << "\a";

    return 0;
}
