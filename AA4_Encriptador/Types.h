#pragma once

enum SaveMode { //I will use it to open the file to write on one mode or the other, depending if the user wants to recover the old messages.
	APPEND,
	OVERWRITE
};

enum CaesarMode {
	ENCRYPT,
	DECRYPT
};

#define startingValue 0
#define key 3
#define alphabetSize 26