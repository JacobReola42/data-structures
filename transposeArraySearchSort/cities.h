/* ************************************************************************
Name: Jacob Reola
Assignment: 02
Purpose: Main program header this header contains the libraries and protoypes for the main.cpp file.
Completed: 13 September 2018
 ************************************************************************ */

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int CITIES = 6;
const int TEMPS = 3;
const string SPACE = " ";


void readFile(ifstream &fin, string filename, string[CITIES], int[CITIES][TEMPS]);

void selectionSortArray(string[CITIES], int[CITIES][TEMPS]);

void display(string[CITIES], int[CITIES][TEMPS]);

void transposeArray(string[CITIES], int[CITIES][TEMPS] ,int [TEMPS][CITIES]);

void displayTransposedArray(string[CITIES],int [TEMPS][CITIES] );

int binarySearch(int[], int);

void positionToCity(string[], int);


