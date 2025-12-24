#include <iostream>
#include <fstream>
#include <string>

void writeOnFile() {
	std::cout << "Write all the messages you want. If you want to stop, please write \"exit\"." << std::endl;

	std::ofstream file; //To write on the archive.
	file.open("chat.txt", std::ios::app);

	if (file.is_open()) {
		std::string line;

		while (line != "exit") {
			std::getline(std::cin, line);

			if (line != "exit") { //To avoid that when the user writes exit to leave the program, "exit" is written on the archive.
				file << line << std::endl; //We write on the archive.
			}
		}
	}

	else {
		std::cerr << "We couldn't open your archive." << std::endl;
	}

	std::cout << "Saving data. Leaving the program..." << std::endl;

	file.close();
}