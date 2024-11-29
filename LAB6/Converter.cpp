#include "Converter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>                                              // For output formatting


using namespace std;

void Converter::processFile(const string& fileName) {           // Processes the input file containing binary numbers
    ifstream inputFile(fileName);                               // Open the file for reading
    if (!inputFile) {
        cout << "Error opening file." << endl;                  // Display error message if file cannot be opened
        return;
    }

    cout << "Binary Number\t\t\tDecimal Equivalent" << endl;    // Print the header for the output table
                                                                // Check if the end of the file is reached
    while (inputFile.peek() != EOF) { 
        processNumber(inputFile);
    }
    
    inputFile.close();                                          // Close the file after processing
}

void Converter::processNumber(istream& input) {                 // Processes a single binary number from the input stream
    int decimalValue = 0;                                       // Store the decimal equivalent of the binary number
    string binaryNumber ;                                       // Store the binary number as a string       
    bool badInput = false;                                      // Flag to indicate if bad input is encountered
    char ch;                                                    // Store each character read from the input
 
	while (input.get(ch)) {                                     // Read characters one at a time
		if (ch == '\n') break;                                  // Stop at the end of the line
        if (isspace(ch)) continue;                              // Skip spaces
        
        if ( isBinary(ch)) {                                    // Check if the character is a valid binary digit (0 or 1)
            binaryNumber += ch;                                 // Append valid binary digit to the string
            decimalValue = decimalValue * 2 + (ch - '0');       // Update the decimal value
        }
        else {
            cout << "Bad digit on input" << endl;               // Handle invalid input (non-binary character)
            badInput = true;
            break;                                              // Stop processing this number
        }
    }

    if (!badInput && !binaryNumber.empty()) {                   // Output the binary and decimal values if the input was valid
        cout << left << setw(32) << binaryNumber << decimalValue << endl;
    }                                                           // Align output using setw for proper formatting
    else {
		input.ignore(100, '\n');                                // Skip the rest of the line
    }
}


bool Converter::isBinary(char ch) {                             // Checks if the character is a valid binary digit (0 or 1)
    return ch == '0' || ch == '1';
}