﻿/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Lab 08
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: Optimize code  three cases.
*/

// Program id: CSLab08.txt
// This is our template for CS Lab 08
// Efficiency practice program
// This document has three cases that represent portions of programs
// that need some help; they are inefficient.
// Study the code and rewrite or remove portions of the code
// to make it more efficient. Your goal should be to decrease the number
// of units (operations) by as much as possible.
// We will assume a fictional chip where everything takes one cycle.

// UNITS:

// Mathematics (1 cycle)
// Assignment (1 cycle)
// Logical operations such compare operations, etc… (1 cycle)
// Return (1 cycle)
//  Hint: simply update this code for your answer by removing
//  the operations (code) that you find to be inefficient (unnecessary)...
//
//
// CASE 1
// Assume all variables and constants were defined, etc.
// This should be an easy one (short and sweet too)

const double sqrtHalfPI = sqrt(PI / 2);
for (i = 0; i < max; i++)
   myArray[i] = myArray[i] + sqrtHalfPI;

//
//
// CASE 2
// A function that should make you wince

int findHighest(double s1, double s2, double s3, double s4, double s5)
{
   double score;
   if (s1 >= s2 && s1 >= s3 && s1 >= s4 && s1 >= s5)
      score = s1;
   if (s2 >= s1 && s2 >= s3 && s2 >= s4 && s2 >= s5)
      score = s2;
   if (s3 >= s2 && s3 >= s1 && s3 >= s4 && s3 >= s5)
      score = s3;
   if (s4 >= s2 && s4 >= s3 && s4 >= s1 && s4 >= s5)
      score = s4;
   if (s5 >= s2 && s5 >= s3 && s5 >= s4 && s5 >= s1)
      score = s5;
   return score;
}

int findHighest(double s1, double s2, double s3, double s4, double s5)
{
   double score = s1;
   if (s2 > score)
      score = s2;
   if (s3 > score)
      score = s3;
   if (s4 > score)
      score = s4;
   if (s5 > score)
      return s5;
   return score;
}

//
//
// CASE 3
// A naïve program (hint: is maybe k totally useless?)
//                        if so, all the instructions are too.
//                  look for similar useless code and counters...
do
{
   cout << "Would you like to:" << endl;
   cout << "1. Calculate the Area of a Circle 12 times" << endl;
   cout << "2. Calculate the Area of a Rectangle 10 times" << endl;
   int k = 0;
   cin >> selection;

   if (selection == 1)
      for (int i = 0; (i < 12); i++)
      {
         cout << "Enter another radius" << endl;
         cin >> radius;
         areaCircle = 3.14159 * pow(radius, 2.0);
         cout << "The area of your circle is " << areaCircle << endl;
      }
   else if (selection == 2)
   {
      for (int i = 0; (i < 10); i++)
      {

         cout << "Enter another length and width of your rectangle separated with a space" << endl;
         cin >> length >> width;
         areaRectangle = length * width;
         cout << "The area of your rectangle is " << areaRectangle << endl;
      }
   }
   else if (selection > 2)
   {
      cout << "This was not a valid selection" << endl;
   }

} while ((selection >= 1 && selection <= 2) && (user == "Admin");