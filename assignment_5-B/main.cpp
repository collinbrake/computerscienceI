/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Assignment 5-B, Greatest Dodgeball Player
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: Practice functions, flow of control, and calculations by
      determining who is the greatest dodgeball player of all time.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

// Constants
const float AARONACCURACY = 1.0 / 3;
const float BOBACCURRACY = 0.5;
const float CHARLIEACCURACY = 1.0;
const int NUMDUELS = 1000;
const int AARONID = 0;
const int BOBID = 1;
const int CHARLIEID = 2;

void shoot(bool &targetAlive, double accuracy);
// shoot simulates one shot by a player of given shooting
// accuracy at the player whose status is held in
// targetAlive.

int startDuel();
// startDuel loops until only one player is left, and then
// indicates which player won. This is a dodgeball duel.
// The players shoot in order of Aaron, Bob, Charlie.
// The players use the strategy of always shooting at the
// player with the highest accuracy, i.e. in order of precedence
// [Charlie, Bob, Aaron], except for the first shot, which Aaron
// misses on purpose.

int main()
{
   int winnerID = 4; // Initialize winnerID to an unused ID
   int aaronScore = 0, bobScore = 0, charlieScore = 0;

   // Seed the random number generation with system time
   // for the shoot function
   srand(time(0));

   for (int i = 0; i < NUMDUELS; i++)
   {
      winnerID = startDuel();
      switch (winnerID)
      {
      case AARONID:
         ++aaronScore;
         continue;
      case BOBID:
         ++bobScore;
         continue;
      case CHARLIEID:
         ++charlieScore;
         continue;
      }
   }

   cout << "Using the strategy of shooting at the best shooter alive,\n"
        << "but Aaron intentionally misses the first shot:\n"
        << "Aaron win %: " << (static_cast<double>(aaronScore) / NUMDUELS)
        << endl
        << "Bob win %: " << (static_cast<double>(bobScore) / NUMDUELS)
        << endl
        << "Charlie win %: " << (static_cast<double>(charlieScore) / NUMDUELS)
        << endl;

   return 0;
}

// Precondition: a reference boolean representing the target player's alive
//   status and a double holding the shooting player's shooting accuracy.
// Postcondition: the new alive status of the target player after the shot
//  is stored in the reference variable
void shoot(bool &targetAlive, double accuracy)
{

   // Generate a random integer between 0 and 100
   // and divide by 100 to get a float between 0 and 1
   double random = (rand() % 101) / 100.0;

   // The probability that the target is alive
   // is the inverse of the shooter's accuracy
   targetAlive = !(random < accuracy);

   return;
}

// Precondition: this function has no parameters, but relys on predefined
//    constants for each player's accuracy
// Postcondition: returns the constant ID of the player that won the duel
int startDuel()
{
   // Player status variables
   bool aaronAlive = true, bobAlive = true, charlieAlive = true;

   int count = 0;

   while (true)
   {
      count++;
      for (int id = 0; id <= CHARLIEID; id++)
      {
         switch (id)
         {
         case AARONID:
            if (count == 1)
            {
               continue; // Aaron misses the first shot
            }
            if (aaronAlive)
            {
               if (charlieAlive)
               {
                  shoot(charlieAlive, AARONACCURACY);
               }
               else if (bobAlive)
               {
                  shoot(bobAlive, AARONACCURACY);
               }
               else
               {
                  return AARONID; // Aaron won
               }
            }
            continue;
         case BOBID:
            if (bobAlive)
            {
               if (charlieAlive)
               {
                  shoot(charlieAlive, BOBACCURRACY);
               }
               else if (aaronAlive)
               {
                  shoot(aaronAlive, BOBACCURRACY);
               }
               else
               {
                  return BOBID; // Bob won
               }
            }
            continue;
         case CHARLIEID:
            if (charlieAlive)
            {
               if (bobAlive)
               {
                  shoot(bobAlive, CHARLIEACCURACY);
               }
               else if (aaronAlive)
               {
                  shoot(aaronAlive, CHARLIEACCURACY);
               }
               else
               {
                  return CHARLIEID; // Charlie won
               }
            }
            continue;
         }
      }
   }
}