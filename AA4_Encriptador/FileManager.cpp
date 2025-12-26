#include <iostream>
#include <fstream>
#include <string>
#include "InputControl.h"

void writeOnFile() {
	std::cout << "Write all the messages you want. If you want to stop, please write \"exit\"." << std::endl;

	std::ofstream file; //To write on the archive.
	file.open("chat.txt", std::ios::app);

	if (file.is_open()) { //I check again to avoid crashes if the user has deleted the archive.
		std::string line;

		while (line != "exit") {
			std::getline(std::cin, line);

			if (line != "exit") { //To avoid that when the user writes exit to leave the program, "exit" is written on the archive.
				file << line << std::endl; //We write on the archive.
			}
		}

		std::cout << "Saving data. Leaving the program..." << std::endl;
	}

	else {
		std::cerr << "We couldn't open your archive." << std::endl;
	}

	file.close();
}

void askToRecover() {
	std::ifstream file;
	file.open("chat.txt");

	if (file.is_open()) { //To check if the archive has been created or already exists.
		file.close();

		std::cout << "Old messages saved detected. Do you want to recover them? \"y\" to recover, anything to reject:" << std::endl;

		std::string input;
		inputControl(&input); //It will return a pointer an change the value of input.
		
		if (input == "y") {
			
		}

		else {
			
		}
	}

	else {
		std::cout << "There are no saved messages, starting a new conversation." << std::endl;
		writeOnFile();
	}
}