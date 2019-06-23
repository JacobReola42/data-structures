// Copyright 2018 Jacob Reola

#include "main.h"

int main() {

    // Tester variables
    std::string name = "Avocado";
    int age = 3;
    bool isAKC = true;
    std::string catFood = "Lasagne";

    //creates a pet object with no parameters
    pet myPet1;
    //creates a pet object with name and _age
    pet myPet2("Indigo", age);

    //creates a dog object with no parameters
    dog myDog1;
    //creates a dog object with name, _age and AKC registration
    dog myDog2(name, age, isAKC);

    //creates a cat object with no parameters
    cat myCat1;
    //creates a cat object with name, _age, and favorite food
    cat myCat2("Garfield", age, catFood);

    displayPet(myPet1);
    displayPet(myPet2);

    displayDog(&myDog1);
    displayDog(&myDog2);

    displayCat(&myCat1);
    displayCat(&myCat2);

    return 0;
}
