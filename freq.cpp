#include <iostream>
#include <fstream> // ifstream
#include <iomanip> // setprecision()
#include <map> 

#define MAX_ASCII 128 
#define DEC_TO_PERCENT 100

int main(int argc, char **argv) {

	// arg count should be 2 
	if (argc != 2) {
		std::cerr << "usage: " << argv[0] 
				  << " <filename>" << std::endl;
		return 1;
	}
	const char *filename = argv[1];

	int totalChars = 0;
	std::map<char, int> asciiMap;
	std::ifstream file(filename);
	char asciiChar;
	if (file.is_open()) { 
		
		// Go through file character one by one
		while (file.get(asciiChar)) {
			++asciiMap[asciiChar];
			++totalChars;
		}

		file.close();

	} else {
		std::cerr << "Error when trying to open file " 
				  << filename << "." 
				  << std::endl;
		return 1;
	}

	// Print ascii frequencies
	for (int i = 0; i < MAX_ASCII; ++i) {

		// Skip characters that do not appear in file
		if (asciiMap[i] == 0) continue;

		// Print ascii values and frequencies
		std::cerr << i << "\t" 
				  << std::setprecision(2) 
				  << std::fixed 
				  << asciiMap[i] * DEC_TO_PERCENT / (float) totalChars 
				  << std::endl;
	}

	return 0;
}
