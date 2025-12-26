#include <iostream>
#include <string>
#include <cctype> //Needed for tolower

#define lengthToAccept 1

std::string inputControl(std::string* inputPtr) { //This function will return a string and we use strings to manage the errors if the user writes a line instead of a single letter.
	bool isValid = false;
	std::string line;

	while (!isValid) {
		//*inputPtr = tolower(*inputPtr); //We convert the input to lowercase so later we can check on FileMangaer.cpp if the user wrote 'y' or anything else.
		std::getline(std::cin, line); //We read all the line.

		if (line.length() == lengthToAccept) {
			line[0] = tolower(line[0]); //We convert to lowerCase the only character.
			isValid = true;
		}

		else {
			std::cerr << "Error: Please, write one letter." << std::endl;
			isValid = false;
		}
	}

	*inputPtr = line;

	return *inputPtr;
}