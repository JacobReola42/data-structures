// Copyright 2018 Jacob Reola


#include <cstdlib>
#include <unistd.h>

#include "root.h"

int main(int argc, char **argv)
{

    // treat as a struct since BinarySearchTree is a class and we're calling public variables. DERP structs.
    BinarySearchTree accessorVariable;

    if (argc < 2)
    {
        std::cout<<"Send Number of nodes to create in Arguments"<<std::endl;
        exit(1);
    }

    srand(time(0));

    int n = atoi(argv[1]);

    if(n<0 || n>20){
        std::cout << "0-20 are the valid arguments \n";
        exit(1);
    }


    std::cout << "\nChecking to see if tree is empty" << std::endl;
    std::cout << "\nIs it empty?: " << (accessorVariable.isEmpty() ? "yes" : "no") << std::endl;
    std::cout << "\nThis is the tree height: " << accessorVariable.getHeight() << std::endl;
    std::cout << "\nThis is the total nodes in the tree: " << accessorVariable.getNumberOfNodes() << std::endl;
    int count = 2;
    std::cout << "\nThis tree contains " << count << " : " << (accessorVariable.contains(count) ? "yes" : "no") << std::endl;
    std::cout << "\nThis tree contains " << count+1 << " : " << (accessorVariable.contains(count+1) ? "yes" : "no") << std::endl;

    for (int i = 0; i < n; ++i)
    {
        int r = 100 + rand() % (( 999 + 1 ) - 100); // generate random number

        count = r; // random number

        std::string tmp = "Data" + std::to_string(i);

        if(accessorVariable.addNode(r,tmp) == false){  // if the number is already in the tree, it'll say so.
            std::cout << "\n" << r << " Already exist on Tree " << std::endl;
            --i;
        }
    }

    std::cout << "\n\nChecking to see if tree if filled \n" << std::endl;
    std::cout << "\nIs it Empty?:" << (accessorVariable.isEmpty() ? "yes" : "no") << std::endl;
    std::cout << "\nThis is the tree height: " << accessorVariable.getHeight() << std::endl;
    std::cout << "\nThis is the total nodes in the tree: " << accessorVariable.getNumberOfNodes() << std::endl;
    std::cout << "\nContains "<< count <<": "<< (accessorVariable.contains(count) ? "yes" : "not found") << std::endl;
    std::cout << "\nContains "<< count+1 <<": "<< (accessorVariable.contains(count+1) ? "yes" : "no") << std::endl;
    std::cout << "\nRemove "<< count << ": " <<(accessorVariable.removeNodeFoSho(count) ? "removed" : "not found") << std::endl;
    std::cout << "\nIs it empty?: " << (accessorVariable.isEmpty() ? "yes" : "no") << std::endl;
    std::cout << "\nTree Height: " << accessorVariable.getHeight() << std::endl;
    std::cout << "\nTotal Nodes: " << accessorVariable.getNumberOfNodes() << std::endl;
    std::cout << "\nThis tree contains " << count << ": "<< (accessorVariable.contains(count) ? "yes" : "not found") << std::endl;

    std::cout << "\nInorder Traversal: \n";
    accessorVariable.inOrderTraverse();

    std::cout << "\n\nPreorder Traversal: \n";
    accessorVariable.preOrderTraverse();


    std::cout << "\n\nPostorder Traversal: \n";
    accessorVariable.postOrderTraverse();
    std::cout << std::endl;

    accessorVariable.clear();
    std::cout << "\n\nThe list is cleared \n" << std::endl;

    std::cout << "\nIs it empty?: " <<  (accessorVariable.isEmpty() ? "yes" : "no") << std::endl;
    std::cout << "\nThis is the tree height: " << accessorVariable.getHeight() << std::endl;
    std::cout << "\nThis is the total nodes in the tree: " << accessorVariable.getNumberOfNodes() << std::endl;
    std::cout << "\nThis tree contains " << count << ": " << (accessorVariable.contains(count) ? "yes" : "no") << std::endl;
    std::cout << "\nThis tree contains " << count+1 << ": " << (accessorVariable.contains(count+1) ? "yes" : "no") << std::endl;

    std::cout << "\nInorder Traversal: \n";
    accessorVariable.inOrderTraverse();

    return 0;
}
