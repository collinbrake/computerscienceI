/* 
    COPYRIGHT (C) 2020 Collin Brake (cmb361), All rights reserved.
    Computer Science I - Lab 2, Coding Standards
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: This program is intended as practice writing code that follows consistent
        standards that are generally accepted in industry.
*/

#include <iostream> // to handle input and output
#include <iomanip>  // to format decimal output
#include <string>   // to access the string type
#include <limits>   // for providing elements with the characteristics of arithmetic types

using std::cout;
using std::cin;
using std::string;

// The following constant and variable declarations were prescribed in
// the lab instructions and do not apply to the main program following.
const double STATE_TAX_RATE = 0.25,
    COUNTY_TAX_RATE = 0.75,
    FEDERAL_TAX_RATE = 1.25;
int statePopulationTotal = 0,
    countyPopulationTotal = 0,
    federalPopulationTotal = 0;

int main()
{
    // Prompt the user for the necessary inputs such as
    // name, number of likes, and number of tweets, and
    // fetch the values provided from the input stream.
    string twittererName = "";
    int tweets = 0, likes = 0;
    cout << "Who is the twitterer? ";
    cin >> twittererName;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Number of tweets: ";
    cin >> tweets;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Number of likes: ";
    cin >> likes;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Calculate the ratio of likes to tweets and display as a percentage.
    double percentage = likes / static_cast<float>(tweets) * 100;
    cout << "Your total is " << likes << " out of " << tweets << ", or "
        << percentage << "%.\n";

    // Assign a twitter rating based on the above ratio.
    string twitterRating = "";
    if (percentage < 60)
    {
        twitterRating = "Oh, bad news";
    }
    else if (percentage < 63)
    {
        twitterRating = "Dislikes rule";
    }
    else if (percentage < 67)
    {
        twitterRating = "More dislikes than not";
    }
    else if (percentage < 70)
    {
        twitterRating = "Some dislikes";
    }
    else if (percentage < 73)
    {
        twitterRating = "Okay, I guess";
    }
    else if (percentage < 77)
    {
        twitterRating = "Good";
    }
    else if (percentage < 80)
    {
        twitterRating = "Pretty good";
    }
    else if (percentage < 83)
    {
        twitterRating = "Semi-well liked";
    }
    else if (percentage < 87)
    {
        twitterRating = "Well liked";
    }
    else if (percentage < 90)
    {
        twitterRating = "Better than most";
    }
    else if (percentage < 93)
    {
        twitterRating = "Semi-awsome";
    }
    else
    {
        twitterRating = "Awsome";
    }

    // Display the twitter rating.
    cout << "Your twitter rating is " << twitterRating << ".\n";

    return 0;
}

