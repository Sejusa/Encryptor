#include <string>
#include "Types.h"

std::string caesarCipher(std::string line, CaesarMode mode) {
	for (short i = startingValue; i < line.length(); i++) {
		if (std::isalpha(line[i])) { //If the actual char on line is a letter.
			char base = std::islower(line[i]) ? 'a' : 'A'; //We store whether the current character is lowercase or uppercase.

			if (mode == ENCRYPT) {
				/*Converts the char to the[0, 25] (a, b...) range to safely apply the modulo operator and get the ascii value.
				This way, if we change the value of key, it will still work.
				Example: 'y' = 121; base = 'a'(97); 121-97 = 24; 24 + key(3) = 27; 27 % 26 = 1 = b.*/
				line[i] = ((line[i] - base + key) % alphabetSize) + base;
			}

			else {
				line[i] = ((line[i] - base - key) % alphabetSize) + base;
			}
		}
	}
	
	return line;
}