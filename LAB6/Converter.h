#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
using namespace std;

class Converter {
    public:
        
		// Processes the input file containing binary numbers
        void processFile(const std::string& fileName);

    private:
        
        // Processes one binary number from the input
        void processNumber(istream& input);
		
		// checks if the character is a binary digit
        bool isBinary(char ch);
};

#endif  // CONVERTER_H
