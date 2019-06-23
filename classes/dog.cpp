// Copyright 2019 Jacob Reola

#include "dog.h"

dog::dog() {
	setIsAKC(false);
}

dog::dog(std::string name, int age, bool akc) {
	setName(std::move(name));
	setAge(age);
	setIsAKC(akc);
}

std::string dog::bark() {
	return (pet::getName() + " has barked.");
}

bool dog::getIsAKC() {
	return (_isAKC);
}

void dog::setIsAKC(bool akc) {
	this->_isAKC = akc;
}
