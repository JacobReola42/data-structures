/* ************************************************************************
Name: Jacob Reola
Assignment: 02
Purpose: This functions.cpp contains the definitions of each function to have the main.cpp work.
 ************************************************************************ */

#include "cities.h"


void readFile(ifstream &fin, string fileName, string cities[CITIES], int temps[CITIES][TEMPS])
{
    ifstream inFile;
    string cityName;

    int i = 0;

    inFile.open(fileName);

    cout << endl;  // creates a line

    if (inFile.fail()) {
        cout << "File is not there. " << endl;
    } else {
        cout << "File is present. " << endl;
        cout << endl; // used to create a line space for the next display.
    }


    while(!inFile.eof())
    {
        string cityLine;
        inFile >> cityLine;

        // The cityLine is now in a stream that we can break the cityLine up with now

        stringstream strStream(cityLine);
        getline(strStream, cityName, ',');

        cities[i] = cityName; //assigning cityName from cityLine into array cities

        string highTemp, lowTemp, avgTemp;
        int high, low, avg;

        getline(strStream, highTemp, ',');
        getline(strStream, lowTemp, ',');
        getline(strStream, avgTemp, ',');
//DEBUG
        /*cout << "AFTER getline(...):: "
             << cityName << SPACE << highTemp << SPACE << lowTemp << SPACE << avgTemp << endl;*/

        high = stoi(highTemp);
        low  = stoi(lowTemp);
        avg  = stoi(avgTemp);

        temps[i][0] = high;
        temps[i][1] = low;
        temps[i][2] = avg;

       /* cout << cities[i] << SPACE
        << temps[i][0] << SPACE
        << temps[i][1] << SPACE
        << temps[i][2] << endl; */

        i++;

    }

    // Clear end of file flag to allow additional file operations
    inFile.close();

}


void selectionSortArray(string cities[CITIES], int temps[CITIES][TEMPS]) {

    // cities is 6 goes through 6 rows in the array

    for (int i = 0; i < CITIES - 1; i++){

        for (int row = i + 1; row < CITIES; row++){

            if(temps[i][2] > temps[row][2]){

                //swap begins

                //temporary hold values

                int high = temps[i][0];
                int low = temps[i][1];
                int avg = temps[i][2];
                string sortCity = cities[i];

                // cout << sortCity << "debug1" << endl;

                // current index = smaller index

                temps[i][0] = temps[row][0];
                temps[i][1] = temps[row][1];
                temps[i][2] = temps[row][2];
                cities[i] = cities[row];

                // cout << cities[i] << "debug2" << endl;

                temps[row][0] = high;
                temps[row][1] = low;
                temps[row][2] = avg;
                cities[row] = sortCity;

                // cout << cities[row] << "debug3" << endl;

            }
        }
        // debug here for cities
    }
}

void display(string cities[CITIES], int temps[CITIES][TEMPS]){

    for (int i = 0; i < CITIES; i++){
        cout << cities[i] << ":" << SPACE;
        for (int j = 0; j < 3; j++){
            cout << temps[i][j] << SPACE;
        }
        cout << left << endl;
    }

    cout << endl; // used to create a line to the next display.
}

void transposeArray(string cities[CITIES], int temps[CITIES][TEMPS], int rotatedArray[TEMPS][CITIES]) {
    for (int i = 0; i < TEMPS; i++) {
        for (int j = 0; j < CITIES; j++) {
            rotatedArray[i][j] = temps[j][i];
        }
    }
}

void displayTransposedArray(string cities[CITIES],int rotatedArray[TEMPS][CITIES] ) {

    cout << "This displayes the sorted-transposed array. " << endl;

    for (int i = 0; i < CITIES; i++) {
        cout << cities[i] << SPACE << SPACE << SPACE;
    }

    for (int j = 0; j < TEMPS; j++){
        cout << setw(6) << right <<endl;
        for (int k = 0; k < CITIES; k++)
        cout << rotatedArray[j][k] << SPACE << setw(9) << right;
    }
}

// find the position of the value.
int binarySearch(int rotatedArray[], int value){

    int left = 0;
    int right = CITIES - 1;
    int mid;
    int position = -1;

    bool found = false;

    while (!found && left <= right)
    {
        mid = (right + left) / 2;

        if (rotatedArray[mid] == value){
            position = mid;
            found = 1;
        }

        else if (rotatedArray[mid]> value) {
            right = mid - 1;
        }

        else {
            left = mid + 1;
        }
    }
    cout << endl;
    cout << "Temperature 81 is in position: " << position << "," << SPACE;
    return position;
}


// returnPosition is called to index cities to match cities and value.
void positionToCity(string cities[CITIES], int returnPosition){
        cout << cities[returnPosition] << SPACE << endl;
    }
