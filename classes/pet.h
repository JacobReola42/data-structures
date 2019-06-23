// Copyright 2018 Jacob Reola

#pragma once 
#include <string>

class pet {

protected:

    // Private variables that define a pet
    std::string _name;
    int _age;

public:

	pet();
	pet(std::string name, int age);
	// ~pet();	// Not used.

	// Getters & Setters
	int getAge();
	std::string getName();
	void setAge(int);
	void setName(std::string);
};
