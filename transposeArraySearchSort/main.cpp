/* ************************************************************************
Name: Jacob Reola
Assignment: 02
Purpose: Main program this contains the functions.
Completed: 13 September 2018
 ************************************************************************ */

#include "cities.h"



int main(int argc, char **argv)
{
    string fileName = argv[1];
    string cities[CITIES];
    int temps[CITIES][TEMPS];
    int rotatedArray[TEMPS][CITIES];
    int value = 81;
    int returnPosition;

    ifstream fin;
    fin.open(argv[1]);

    readFile(fin, fileName,cities, temps);
    display(cities, temps);

    selectionSortArray(cities, temps);
    display(cities, temps);

    transposeArray(cities,temps,rotatedArray);
    displayTransposedArray(cities, rotatedArray);

    // binary search is now an integer of the value being found and is being assigned to returnPosition
    returnPosition = binarySearch(rotatedArray[TEMPS - 1], value);
    positionToCity(cities, returnPosition);

    return 0;

}