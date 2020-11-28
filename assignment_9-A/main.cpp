/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Assignment 9-A
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: reverse a C-string using two pointers
*/

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

void reverse(char *word);
// reverse uses pointers to reverse the given string of
// characters

int main()
{
    // these are the test cases
    char str1[] = "time";
    char str2[] = "straw";
    char str3[] = "deliver";
    char str4[] = "star";
    char str5[] = "knits";


    cout << "The strings before reversing: " << endl;
    cout << str1 << " " << str2 << " " << str3 << " " << str4
        << " " << str5 << " " << endl;

    reverse(str1);
    reverse(str2);
    reverse(str3);
    reverse(str4);
    reverse(str5);

    cout << "The strings after reversing: " << endl;
    cout << str1 << " " << str2 << " " << str3 << " " << str4
        << " " << str5 << " " << endl;

    return 0;
}

// Precondition: a pointer to a C-string
// Postcondition: the C-string is reversed
void reverse(char *word)
{
    char *s = word, *e = word + (strlen(word)-1);
    while (s < e)
    {
        char tmp = *s;
        *s++ = *e;
        *e-- = tmp;
    }

    return;
}
