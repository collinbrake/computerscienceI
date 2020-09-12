/*
  Pgm: ASSGN2-A  Name: Collin Brake
  Purpose: This program takes as user input any number of assignment
  scores and calculates the combined points out of a total, the percentage
  grade, and the letter grade. It outputs these values at the end.
  Copyright 2020 by Collin Brake.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // Ask for number of exercises.
    int countExercises = 0;
    cout << "How many exercises to input? ";
    cin >> countExercises;

    int pointsRecieved = 0, pointsPossible = 0,
        pointsRecievedTotal = 0, pointsPossibleTotal = 0;

    // Ask for points achieved and total points possible for each assignment
    // and add to respective sums.
    for (uint i = 0; i < countExercises; i++)
    {
        cout << "Score recieved for exercise " << i+1 << ": ";
        cin >> pointsRecieved;
        pointsRecievedTotal += pointsRecieved;

        cout << "Total points possible for exercise " << i+1 << ": ";
        cin >> pointsPossible;
        pointsPossibleTotal += pointsPossible;
    }


    // Calculate the student's grade as a percentage.
    double gradePercent = double(pointsRecievedTotal)/pointsPossibleTotal;


    // Translate into a letter grade.
    string gradeLetter = "";
    if (gradePercent < 0.6)
    {
        gradeLetter = "F";
    }
    else if (gradePercent < 0.63)
    {
        gradeLetter = "D-";
    }
    else if (gradePercent < 0.67)
    {
        gradeLetter = "D";
    }
    else if (gradePercent < 0.7)
    {
        gradeLetter = "D+";
    }
    else if (gradePercent < 0.73)
    {
        gradeLetter = "C-";
    }
    else if (gradePercent < 0.77)
    {
        gradeLetter = "C";
    }
    else if (gradePercent < 0.8)
    {
        gradeLetter = "C+";
    }
    else if (gradePercent < 0.83)
    {
        gradeLetter = "B-";
    }
    else if (gradePercent < 0.87)
    {
        gradeLetter = "B";
    }
    else if (gradePercent < 0.9)
    {
        gradeLetter = "B+";
    }
    else if (gradePercent < 0.93)
    {
        gradeLetter = "A-";
    }
    else
    {
        gradeLetter = "A";
    }

    cout << "Your total is " << pointsRecievedTotal << " out of " <<
        pointsPossibleTotal << ", or " << setprecision(2) << fixed << 100*gradePercent << "%.\n";
    cout << "Your letter grade is "+gradeLetter << ".\n";

    return 0;
}