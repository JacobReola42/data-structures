// Copyright 2019 Jacob Reola

#include "cat.h"

cat::cat() {
	setFavFood("");
}

cat::cat(std::string name, int age, std::string favFood) {
	setName(std::move(name));
	setAge(age);
	setFavFood(std::move(favFood));
}

std::string cat::getFavFood() {
	return _favFood;
}

std::string cat::meow(){
	return pet::getName() + " wants " + getFavFood();

}

void cat::setFavFood(std::string favFood) {
	(favFood.empty()) ? (this->_favFood = "food") : (this->_favFood = favFood);
}
