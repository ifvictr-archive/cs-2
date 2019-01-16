/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 5: Cipher
 * Due date    : 1/19/19
 */
#include <iostream>
#include <string>

using namespace std;

/*
 * Cipher
 * 
 * This program takes a user-specified string and encrypts/decrypts it using the
 * provided translation map.
 * 
 * INPUT:
 *   method              : Action to perform on input string
 *   translationMapChoice: Translation map to use when translating
 *   str                 : String to be processed
 *
 * OUTPUT:
 *   Outputs an encrypted or decrypted version of the inputted string, depending
 *   on the user's choice
 */
int main() {
    // cout <<
    //     "*****************************************\n"
    //     "  Author    : Victor Truong\n"
    //     "  ID        : 10180511\n"
    //     "  CS 2      : MTWR, 7:30a – 12:30p\n"
    //     "  Assignment: Cipher\n"
    //     "*****************************************\n";


    const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    const string DEFAULT_MAP = "zyxwvutsrqponmlkjihgfedcba";
    string method;
    string translationMapChoice;
    string translationMap;
    string str;
    string processedStr = "";
    bool hasFailed = false;

    // INPUT: Acquire all inputs from user
    cout << "What is the method (encryption or decryption)? ";
    cin >> method;
    if (!(method == "encryption" || method == "decryption")) {
        cout << "Error: invalid method choice.\n";
        return 1;
    }

    cout << "What is the translation map (type 'default' to use default): ";
    cin >> translationMapChoice;
    if (translationMapChoice == "default") {
        translationMap = DEFAULT_MAP;
    }
    else if (translationMapChoice.size() == 26) {
        translationMap = translationMapChoice;
    }
    else {
        cout << "Error: invalid translation map size.\n";
        return 1;
    }

    cout << "What is the single word to translate: ";
    cin >> str;

    // OUTPUT: Process string appropriately action based on method
    if (method == "encryption") {
        for (int i = 0; i < str.size(); i++) {
            char currentChar = str.at(i);
            // Ensure characters are lowercased
            if (currentChar != tolower(currentChar)) {
                hasFailed = true;
                break;
            }
            int alphabetIndex = ALPHABET.find(currentChar);
            if (alphabetIndex == string::npos) {
                hasFailed = true;
                break;
            }
            char encryptedChar = translationMap.at(alphabetIndex);
            processedStr += encryptedChar;
        }
        if (!hasFailed) {
            cout << "Encrypted word: " << processedStr << "\n";
        }
        else {
            cout << "Error: encryption cannot be performed.\n";
        }
    }
    else if (method == "decryption") {
        for (int i = 0; i < str.size(); i++) {
            char currentChar = str.at(i);
            int translationMapIndex = translationMap.find(currentChar);
            if (translationMapIndex == string::npos) {
                hasFailed = true;
                break;
            }
            char decryptedChar = ALPHABET.at(translationMapIndex);
            processedStr += decryptedChar;
        }
        if (!hasFailed) {
            cout << "Decrypted word: " << processedStr << "\n";
        }
        else {
            cout << "Error: decryption cannot be performed.\n";
        }
    }

    return 0;
}