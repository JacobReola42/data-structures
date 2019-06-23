// Copyright 2018 Jacob Reola

#include "pet.h"

// Cat inheritance from pet
class cat : public pet {

private:

	std::string _favFood;

public:

	// Constructors & Destructor
	cat();
	cat(std::string, int, std::string);
	//~cat();	// Not used

	// Methods
	std::string getFavFood();
	std::string meow(); 	
	void setFavFood(std::string);

};
