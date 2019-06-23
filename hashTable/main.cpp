// Copyright 2018 Jacob Reola

#include <fstream>
#include "hash.h"

int main(int argc, char **argv)
{

    std::cout << "\a";

    std::string fileName = argv[1];
    std::ifstream inputFile;

    std::ifstream fin;
    fin.open(argv[1]);

    char comma;
    int key;
    std::string data;

    inputFile.open(fileName);
    if (!inputFile.is_open())
    {
        std::cout << "file not found\n";
        return 1;
    }

    HashTable hashTable(19);

    std::cout<<"checking hashtable is empty or not :";

    if (hashTable.isEmpty())
    {
        std::cout<<" it is empty"<<std::endl;
    }
    std::cout<<"getNumberOfEntries: "<<hashTable.getNumberOfEntries() << std::endl;

    while ((inputFile >> key >> comma >> data))
    {
        std::cout<<"inserting . . . key: "<< key <<", data:"<<data<<std::endl;
        hashTable.add(key, data);
    }

    inputFile.close();


    std::cout<<"checking hashtable if it is empty or not:";
    if (!hashTable.isEmpty())
    {
        std::cout<<" . . . it is not empty"<< std::endl;
    }
    std::cout<<"getNumberOfEntries : "<<hashTable.getNumberOfEntries()<<std::endl;


    hashTable.traverse();
    std::cout << std::endl;
    std::cout << "Removing: 208\n";
    hashTable.remove(208);
    std::cout<<"getNumberOfEntries: "<<hashTable.getNumberOfEntries()<<std::endl;
    hashTable.traverse();
    std::cout << std::endl;
    std::cout << "Removing: 132\n";
    hashTable.remove(132);
    std::cout<<"getNumberOfEntries: "<<hashTable.getNumberOfEntries()<<std::endl;

    hashTable.traverse();

    std::cout << "Clearing Table\n";
    hashTable.clear();



    return 0;
}
