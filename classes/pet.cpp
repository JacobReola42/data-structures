// Copyright 2018 Jacob Reola

#include "pet.h"

pet::pet() {
	setName("");
	setAge(0);
}

pet::pet(std::string name, int a) {
	setName(std::move(name));
	setAge(a);
}

int pet::getAge() {
	return _age;
}

std::string pet::getName() {
	return _name;
}

void pet::setAge(int age) {
	(age > 0) ? (this->_age = age) : (this->_age = 0);
}

void pet::setName(std::string name) {
	(name.empty()) ? (this->_name = "No Name") : (this->_name = name);
}
