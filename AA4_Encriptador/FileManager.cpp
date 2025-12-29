#include <iostream>
#include <fstream>
#include <string>
#include "InputControl.h"
#include "Types.h"
#include "Encryptor.h"

void writeOnFile(std::vector <std::string> &text) {
	std::vector <std::string> encryptedText;

	std::cout << "\nWrite all the messages you want. If you want to stop, please write \"exit\"." << std::endl;

	std::ofstream file; //To write on the archive.

	file.open("chat.txt", std::ios::trunc); //We overwrite (trunc) because the checksum header changes with every new message, so we need to rewrite the whole file.

	if (file.is_open()) { //I check again to avoid crashes if the user has deleted the archive.
		std::string line;

		while (line != "exit") {
			std::getline(std::cin, line);

			if (line != "exit") { //To avoid that when the user writes exit to leave the program, "exit" is written on the archive.
				text.push_back(line); //We put the line on the vector.
			}
		}

		for (short i = startingValue; i < text.size(); i++) {
			encryptedText.push_back(caesarCipher(text[i], ENCRYPT)); //We add the encrypted line to a vector to later calculate the checksum.
			
		}

		file << checkSum(encryptedText) << std::endl; //We save on the file the checksum of all the characters.

		for (short i = startingValue; i < encryptedText.size(); i++) {
			file << encryptedText[i] << std::endl;
		}
		
		std::cout << "\nSaving data. Leaving the program..." << std::endl;
	}

	else {
		std::cerr << "\nWe couldn't open your archive." << std::endl;
	}

	file.close();
}

void askToRecover() {
	std::vector <std::string> text;
	std::vector <std::string> encryptedText;
	bool firstLine = true;
	int number = startingValue;

	std::ifstream file;
	file.open("chat.txt");

	if (file.is_open()) { //To check if the archive has been created or already exists.
		file.close(); //We close to avoid bugs.

		std::cout << "Old messages saved detected. Do you want to recover them? \"y\" to recover, anything to reject:" << std::endl;

		std::string input;
		inputControl(&input); //It will return a pointer an change the value of input.
		
		if (input == "y") {
			std::string line;
			file.open("chat.txt");

			std::cout << "\nRecovering your messages..." << std::endl;

			while (getline(file, line)) { //We get every line of the archive and put on the vector text.
				if (firstLine == true) {
					number = std::stoi(line); //We know that the first line is a number so we use stoi to convert the string to a number.
					firstLine = false;
				}

				else {
					text.push_back(caesarCipher(line, DECRYPT)); //We save the decrypted line on the vector.
					encryptedText.push_back(line); //We save the line without decrypting so late check if the file has been modified.
				}
			}

			if (checkSum(encryptedText) != number) {
				std::cout << "\nDanger! The file has been modified.\n" << std::endl;
			}

			for (short i = startingValue; i < text.size(); i++) {
				std::cout << text[i] << std::endl;
			}

			file.close();
			writeOnFile(text);
		}

		else {
			std::cout << "Starting new conversation (history deleted)." << std::endl;
			writeOnFile(text);
		}
	}

	else {
		std::cout<< "No previous history found. Starting new conversation..." << std::endl;
		writeOnFile(text); //It doesn't matter if we pass APPEND as a parameter instead of OVERWRITE, because there is no .txt, but APPEND is the default.
	}
}