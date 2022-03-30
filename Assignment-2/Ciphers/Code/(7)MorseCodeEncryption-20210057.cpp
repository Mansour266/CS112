//FCAI – Programming 1 – 2022 - Assignment 2
//Program Name:Morse Code encryption.cpp
// Program Description: This program should take letters and convert them to morse code and vise versa
//Last Modification Date: 23/03/2022
//Author and ID and Group: Adham Mansour-20210057-Group A


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//defining constants
//this should define the letters and their corresponding morse code in separate variables letters and morse.
char text[36] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                 '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

string morse[36] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",
                    ".----","..---","...--","....-",".....","-....","--....","---..","----.","-----" };

void text_to_morse() {

    string letters;

    cout << "Please enter the letters: ";

    getline(cin, letters); //this should get inputs separated by spaces and store them in "letters" variable
    transform(letters.begin(), letters.end(), letters.begin(), ::toupper); //this should convert all the letters to capital letters
    cout << endl << "Converted morse code: ";

    for (int i = 0; i < letters.length(); i++) {

        for (int k = 0; k < 36;k++) {

            if (letters.at(i) == text[k]) { // this should find the index (k)  of the corresponding letter to find the morse code match

                cout << morse[k] << " ";

            }
        }
        if (isspace(letters.at(i))) { // this should separate the morse code by 3 spaces to indicate a new word.
            cout << "   ";
        }
    }
    cout << endl;
}

void morse_to_text() {
    string morse_code, temp_code;// temp_code will store the morse code letter separately and cleared after each letter
    int spaces{ 0 }; // will be used later to separate words.
    cout << "Please enter the code:";
    getline(cin, morse_code);

    cout << "Converted text: ";

    for (int i = 0; i <= morse_code.length();i++) {
        if (i != morse_code.length() && morse_code[i] != ' ') {

            temp_code += morse_code[i];
            spaces = 0;
        }
        else {

            for (int k = 0;k < 36;k++) {

                if (temp_code == morse[k]) {
                    cout << text[k];
                }
            }
            temp_code = "";
            spaces++;
        }
        if (spaces == 3) {
            cout << " ";
        }

    }
}

int main() {// this should give the user choices and execute according to the choice.
    string choice;
    while (choice != "3") {
        cout << "Enter 1 to encrypt \nEnter 2 to decrypt \nEnter 3 to exit\nchoice: ";
        getline(cin, choice);
        if (choice == "1") {
            text_to_morse();
            cout << endl;
        }
        else if (choice == "2") {
            morse_to_text();
            cout << endl;
        }
    }
}
