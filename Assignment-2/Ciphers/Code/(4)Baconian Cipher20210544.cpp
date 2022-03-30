// FCAI - Programming 1 - 2022 - Assignment 2
// Program Name: Baconian Cipher.cpp
// Program Description: Program for encrypting and decrypting text using Baconian Cipher.
// Last Modification Date: 03/23/2022
// Author: Yousef Kilany , ID: 20210544 , S25
// T.A.: N/A	
// Purpose: For Assignment 2 - Programming 1 

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// Function prototypes.
void encrypt();
char reduce(char);
void cipherChar(char);
int decrypt();
char restore(char);
string filterChars(string);


string secretText = "";
string decryptedText = "";

int main()
{	
	char userInput;
	while (true) { // Main menu.
		cout << "Welcome my Habibi User to Baconian Cipher!\n";
		cout << "What do you want to do?\n";
		cout << "1. Decrypt Text.\n2. Encrypt Text.\n3. Exit.\n";
		cin >> userInput;
		if (userInput == '1') {
			decrypt();
		}
		if (userInput == '2') {
			encrypt();
		}
		if (userInput == '3')
			break;
	}
	cout << "Thank You for using KILANY Apps.";
}


// Main function for decryption.
void encrypt()
{
	secretText = ""; // This should keep secretText empty each time the function is called.
	cout << "Enter a message to encrypt: ";
	string userMessage;
	cin.ignore(); // for getline() to work properly.
	getline(cin, userMessage);

	// Upper case all chars in userMessage.
	for (int i = 0; i < userMessage.length(); i++) {
		userMessage[i] = toupper(userMessage[i]);
	}

	userMessage = filterChars(userMessage); // Filter any non charcter from userMessage.

	// This loop turns spaces into "bbbbb " and cipheres charcters.
	for (int i = 0; i < userMessage.length(); i++) {
		if (userMessage[i] == ' ') {
			secretText += "bbbbb ";
			continue;
		}

		cipherChar(reduce(userMessage[i]));
	}

	cout << "Encrypted message: " << secretText << endl << endl;
}


// sub Function to cipher each charcter individualy.
void cipherChar(char chr)
{
	int ascii = (int)chr;
	int binary[] = { 0, 0, 0, 0, 0 };

	for (int i = 4; i >= 0; i--) { // Turn charcter into a binary array.
		if (ascii == 0) {
			break;
		}
		if (ascii % 2 == 1) {
			binary[i] = 1;
		}
		ascii = ascii / 2;
	}

	for (int i = 0; i < 5; i++) { // Turn that binary array into 'a's and 'b's 
		if (binary[i] == 0) {	  // and append them to secretText.
			secretText += 'a';
		}
		else {
			secretText += 'b';
		}
	}

	secretText += ' '; // Adding spaces between ciphered charcters
}


char reduce(char chr)
{
	// Turns charcters to start from 'A' = 0, 'B' =	1, 'C' = 2,... and so on.
	chr -= 65;
	return chr;
}


int decrypt()
{
	decryptedText = ""; // This should keep decryptedText empty each time the function is called.
	cout << "Enter a message to decrypt (aabba aabaa abbbb ....., otherwise unpredicted output!) : ";
	string userMessage;
	cin.ignore(); // for getline() to work properly.
	getline(cin, userMessage);
	
	// Remove spaces from userMessage.
	userMessage.erase(remove(userMessage.begin(), userMessage.end(), ' '), userMessage.end());

	for (int i = 0; i < userMessage.length(); i += 5) { // Take groups of 5 from userMessage
		char chr = 0;									// and decrypt them each iteration.
		int k = 0;
		int binary[] = { 0, 0, 0, 0, 0 };
		bool isSpace = true;

		for (int j = i; j < i + 5; j++) { // Build a binary array for each group of 5.
			if (userMessage[j] == 'a') {
				binary[k] = 0;
			}
			if (userMessage[j] == 'b') {
				binary[k] = 1;
			}
			k++;
		}

		for (int i = 0; i < 5; i++) { // Check if the given array represent a space.
			if (binary[i] == 0) {
				isSpace = false;
				break;
			}
		}

		if (isSpace) { // if so, append a space to decryptedText and start a new iteration.
			decryptedText += ' ';
			continue;
		}

		for (int i = 0; i < 5; i++) { // Turn the binary array into an ascii.
			chr += (pow(2, i) * binary[4 - i]);
		}
		decryptedText += restore(chr); // Append the charcter with the restored ascii.
	}

	cout << "Original text: " << decryptedText << endl << endl;
	return 0;
}



char restore(char chr)
{
	// Turns charcters to their original ascii.
	chr += 65;
	return chr;
}


string filterChars(string str)
{
	// This Function filters any non-capital-charcter from a string.
	char toRemove[100];
	int j = 0;

	for (int i = 0; i < str.length(); i++) { // Collect all non-charcters in an array.
		if ((str[i] < 'A' || str[i] > 'Z') && str[i] != ' ') {
			toRemove[j] = str[i];
			j++;
		}
	}

	for (int i = 0; i < 100; i++) { // Erase each non-charcter seperatly to avoid unpredicted results.
		str.erase(remove(str.begin(), str.end(), toRemove[i]), str.end());
	}

	return str;
}

