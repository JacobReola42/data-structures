// Copyright 2018 Jacob Reola

#include "pet.h"

// Dog class inherits pet class
class dog : public pet {

private:

	//private variables that define a dog (from a pet)
	bool _isAKC; // AKC stands for American Kennel Club

public:

	dog();
	dog(std::string, int, bool);
	// ~dog(); // Not used.

	// Methods
	std::string bark(); 		// displays message
	bool getIsAKC();
	void setIsAKC(bool);

};
