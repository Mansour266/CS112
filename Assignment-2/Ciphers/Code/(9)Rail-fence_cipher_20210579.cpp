// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Rail-fence_cipher.cpp
// Program Description: program to encrypt a text
// Last Modification Date: 23/3/2022
// Author: Mohamed Essam El-Din Hassan
// ID: 20210579
// Group: A
#include <bits/stdc++.h>
using namespace std;
string ciphered_text ;

// the function used to encrypt
string encryptRailFence(string text, int key)
{

	// create the matrix of the cipher
	// key = rows , length(text) = columns
	char rail[key][(text.length())];

	// make spaces for the blank areas
	for (int i=0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			rail[i][j] = '\n';

	// variable for detecting the direction
	bool dir_down = false;
	int row = 0, col = 0;

	for (int i=0; i < text.length(); i++)
	{
		// check the direction of flow
		// reverse the direction if we've just
		// filled the top or bottom rail
		if (row == 0 || row == key-1)
			dir_down = !dir_down;

		// fill the matrix with the text
		rail[row][col++] = text[i];

		// find the next row using direction variable
		dir_down?row++ : row--;
	}

	// now we can construct the cipher using the rail matrix
	string result;
	for (int i=0; i < key; i++)
		for (int j=0; j < text.length(); j++)
			if (rail[i][j]!='\n')
				result.push_back(rail[i][j]);
    ciphered_text = result ;
    // print the encrypted text
    cout << "Encrypted text is: " << result <<"\n" ;
	return result;
}

// This function receives encrypted-text
// and returns the original text after decryption

string decryptRailFence(string cipher, int key)
{
    // create the matrix to cipher-text
    // key = rows , length(text) = columns
    char rail[key][cipher.length()];

    // filling the rail matrix
    // make spaces for blank areas
    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = '\n';

    // variable for detecting the direction
    bool dir_down;

    int row = 0, col = 0;

    // mark the places with '*'
    for (int i=0; i < cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        // place the marker
        rail[row][col++] = '*';

        // find the next row using direction variable
        dir_down?row++ : row--;
    }

    // now we construct the rail matrix
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];


    // now read the matrix in zig-zag manner to construct
    // the resultant text
    string result;

    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        // place the marker
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);

        // find the next row using direction flag
        dir_down?row++: row--;
    }
    // print the decrypted text
    cout << "Decrypted Text Is: " << result << "\n" ;
    return result;
}

// in main we will ask the user for the string and the key
// then we will encrypt it and print the encrypted
// then we will decrypt the encrypted message and print it
int main()
{
    string text ;
	int key ;
    cout <<"Enter the text to encrypt: ";
    cin >> text ;
    cout << "Enter the key: " ;
    cin >> key ;
    encryptRailFence(text , key);
    decryptRailFence(ciphered_text , key);


	return 0;
}