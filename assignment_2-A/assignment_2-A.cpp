#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int countExercises = 0;
    cout << "How many exercises to input? ";
    cin >> countExercises;

    int pointsRecieved = 0, pointsPossible = 0,
        pointsRecievedTotal = 0, pointsPossibleTotal = 0;

    for (uint i = 0; i < countExercises; i++)
    {
        cout << "Score recieved for exercise " << i+1 << ": ";
        cin >> pointsRecieved;
        pointsRecievedTotal += pointsRecieved;

        cout << "Total points possible for exercise " << i+1 << ": ";
        cin >> pointsPossible;
        pointsPossibleTotal += pointsPossible;
    }

    double gradePercent = double(pointsRecievedTotal)/pointsPossibleTotal;
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