/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	5
** File: 	source.cpp
** Description: C++ program that encrypts or decrypts text from a file using the Caesar cipher, shifting only letters and keeping other characters unchanged.
**
** Author: 	Rahmati Govari, Pejman. Rawat, Upendra. Sun,Sibo. Valenzuela, Vivian.
** Date: 	20NOV2025
** -------------------------------------------------------------------------*/﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Encrypt: shift all characters forward
string encrypt(string text, int shift) {
    string encoded_text;
    for (int i = 0; i < text.size(); i++) {
        encoded_text += text[i] + shift;  // move forward
    }
    return encoded_text;
}

// Decrypt: shift all characters backward
string decrypt(string text, int shift) {
    string decoded_text;
    for (int i = 0; i < text.size(); i++) {
        decoded_text += text[i] - shift;  // move backward
    }
    return decoded_text;
}

int main() {
    int shift;
    char option;

    // 1. Ask the user whether they want to encrypt or decrypt
    cout << "Encrypt (E) or Decrypt (D)? ";
    cin >>option;

    // 2. Ask the user for a shift value (number of positions to shift letters)
    cout << "Enter shift value: ";
    cin >> shift;

    // 3. Read the text from input.txt
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Error: input.txt not found!" << endl;
        return 1;
    }

    // Create output.txt to save results
    ofstream outputFile("output.txt");

    string line;
    while (getline(inputFile, line)) {
        string result;

        // 4. Apply the Caesar cipher
        if (option == 'E' || option == 'e')
            result = encrypt(line, shift);   // Encryption: shift letters forward
        else
            result = decrypt(line, shift);   // Decryption: shift letters backward

        // Print the original and the result
        cout << "Original : " << line << endl;
        cout << "display Result   : " << result << endl;
        cout << "-----------------------------\n";

        // 5. Write the result to output.txt
        outputFile << result << "\n";
    }

    // Close files
    inputFile.close();
    outputFile.close();

    // Notify the user that the results have been saved
    cout << "\nAll results saved into output.txt\n";
    return 0;
}
