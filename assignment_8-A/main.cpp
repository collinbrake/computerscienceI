/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - ASSIGNMENT 8-A, Pig Latin
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: Practice vectors and strings by encoding an input file in Pig
      Latin.
*/

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

string fetchInput(string promptMsg, string invalidMsg);
// fetchInput prompts for, recieves from the input stream, and
// validates string type input.

bool validateInput(string input, string message);
// validateInput validates the string type input, and prints out
// the provided message if the input is invalid. It ensures that
// the input is of the correct type, and that the string input
// is a valid file name.

void split(string &line, vector<string> &words);
// split takes a string and adds each word to the passed by reference
// vector of strings. It splits the string by spaces. Any puncuation
// will be included in the word before it if not completely separated
// by spaces.

string toPigLatin(string word);
// toPigLatin converts a word in the passed by reference vector of
// strings to pig latin, i.e., it removes moves the first letter to the
// end of the string and then appends "ay" to the word.

void concatenate(vector<string> &words, string &line);
// concatenate makes the given string into a sentence of
// the provided words, separated by spaces.

int main()
{
    string line;
    vector<string> words;
    ifstream inFile;

    string fileName = "DATA.txt"; /*fetchInput("Please give the name of the file to be processed, including extention: ",
            "Invalid file name.");*/
    inFile.open(fileName);

    while(getline(inFile, line))
    {
        // Split at spaces
        split(line, words);

        // Translate each word to Pig Latin
        for (string &word : words)
        {
            word = toPigLatin(word);
        }

        // Concatenate all the words to form the original
        concatenate(words, line);
        cout << line << endl;
        words.clear();
        line.clear();
    }
    return 0;
}

// Precondition: prompt message and message to display when invalid input
// received
// Postcondition: returns valid input of type string
string fetchInput(string promptMsg, string invalidMsg)
{
    string input;         // to hold user input
    bool loopFlag = true; // control for validation
    do
    {
        cout << promptMsg;
        cin >> input;
        loopFlag = validateInput(input, invalidMsg);
    } while (loopFlag);
    return input;
}

// Precondtion: pass the function the user input
//              pass the message to display for any user error
// Postcondition: returns false if valid and true if not
bool validateInput(string input, string message)
{
    bool goodOrNot = false;
    if (cin.fail())
    {
        cout << message << endl;
        goodOrNot = true;
    }
    else
    {
        ifstream test;
        test.open(input);
        if (test.fail())
        {
         cout << message << endl;
         goodOrNot = true;
        }
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return goodOrNot;
}

// Precondition: pass by reference a string of words or groups of
//      characters separated by spaces, as well as a vector of strings
//      to hold the words once split.
// Postcondition: The string will be unchanged, and the vector will
// be filled with the words in the string.
void split(string &line, vector<string> &words)
{
    words.clear();
    string word = "";

    // Loop through line char by char, throwing
    // out spaces and adding words to the vector
    for (char c : line)
    {
        if (!isspace(c))
        {
            word += c;
        }
        else if (word != "")
        {
            words.push_back(word);
            word = "";
        }
    }

    // If the variable word isn't empty (the last char
    // was not a space), add it to the vector.
    if (word != "")
    {
        words.push_back(word);
    }

    return;
}

// Precondition: a word or character group as a string
// Postcondition: another string holding the translation
//      to pig latin.
string toPigLatin(string word)
{
    string translated;
    translated = word.substr(1, word.size()-1);
    translated.push_back(word[0]);
    translated.push_back('a');
    translated += ('y');

    return translated;
}

// Precondition: a vector of words, and a string, passed by
//      reference.
// Postcondition: the string is filled with the words, separated
//      by spaces.
void concatenate(vector<string> &words, string &line)
{
    line.clear();
    for (string word : words)
    {
        line += word+" ";
    }

    // Delete extra space at end
    line.erase(line.size()-1, 1);


    return;
}
