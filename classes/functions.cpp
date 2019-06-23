// Copyright 2018 Jacob Reola

#include "main.h"

void displayPet(pet &myPet) {

	std::cout << "Pet Name: " << myPet.getName() << std::endl;
	std::cout << "Pet Age : " << myPet.getAge() << std::endl;
	std::cout << std::endl;
}

void displayDog(dog *myDog) {

	std::cout << "Dog Name: " << myDog->getName() << std::endl;
	std::cout << "Dog Age : " << myDog->getAge() << std::endl;
	std::cout << "AKC Reg : " <<
						 ( (myDog->getIsAKC()) ? ("Yes"):("No") )
						 << std::endl;
	std::cout << "Dog Bark: " << myDog->bark() << std::endl;
	std::cout << std::endl;
}

void displayCat(cat *myCat) {

	std::cout << "Cat Name: " << myCat->getName() << std::endl;
	std::cout << "Cat Age : " << myCat->getAge() << std::endl;
	std::cout << "Fav Food: " << myCat->meow() << std::endl;
	std::cout << std::endl;
}
