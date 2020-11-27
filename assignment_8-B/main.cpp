/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - ASSIGNMENT 8-B
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: Practice vectors and strings by decoding a code.
*/

#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char encoded[] = ":mmZ\\dxZmx]Zpgy";
    string decoded = "";
    char originalChar, minusKey;

    // Loop over each possible key and attempt to decode the message
    for (int key = 1; key < 101; ++key)
    {
        for (char encryptedChar : encoded)
        {
            // Subtract the key we are trying to start with
            minusKey = encryptedChar - key;

            // If the difference falls in the range of valid
            // ASCII codes, accept it. Otherwise, try to add
            // the upper bound and subtract the lower bound, per
            // the information given.
            if (minusKey <= 126 && minusKey >= 32)
                originalChar = minusKey;
            else
                originalChar = (minusKey + 127) - 32;

            // Add the decoded char to the string.
            decoded += originalChar;
        }

        // Display the decoded message at each key.
        cout << "Key: " << key << " Decoded message: " << decoded << endl;

        // Clear the contents of the string for the next try.
        decoded.clear();
    }
    return 0;
}
