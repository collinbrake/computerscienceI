/*
   ACADEMIC INTEGRITY PLEDGE

   - I have not used source code obtained from another
     student nor any other unauthorized source, either
     modified or unmodified.

   - All source code and documentation used in my program
     is either my original work or was derived by me from
     the source code published in the textbook for this
     course or presented in class.

   - I have not discussed coding details about this project
     with anyone other than my instructor. I understand
     that I may discuss the concepts of this program with
     other students and that another student may help me
     debug my program so long as neither of us writes
     anything during the discussion or modifies any
     computer file during the discussion.

   - I have violated neither the spirit nor letter of these
     restrictions.


   Signed: Collin Brake     Date: 2020-10-12


   COPYRIGHT (C) 2020 by Collin Brake. All Rights Reserved.

   This program creates a simplistic simulation of the Seven Days Battle
   during the Civil War using coin flips.

   Author: Collin Brake
   Version: 1.03,  2020-10-12
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string getBattleName(int index);
// getBattleName returns the correct
// battle name at each loop index

int main()
{
   // Declare vars to hold scores, coin state, and the
   // player's guess as to heads or tails
   int scorePlayer = 0, scoreComputer = 0, coin = 0;
   string playerGuess = "";

   // Seed the random number generater
   srand(time(0));

   // Display the starting screen of the game
   cout << "               LET THE\n\n"
        << "   FLIP OF THE COIN REWRITE HISTORY\n\n\n"
        << "        /----------------------\\\n"
        << "        | RETURN TO SEVEN DAYS |\n"
        << "        \\----------------------/\n\n"
        << "It is July 1, 1862, the final day\n"
        << "of the Battle of Seven Days...\n\n\n"
        << "In this re-enactment of the second day\n"
        << "of battle, you are George B. McClellan\n"
        << "in charge of the Unionists\n\n\n"
        << "We will flip a coin to determine the\n"
        << "outcome of the small battles for\n"
        << "territories within the Seven Days area\n\n"
        << "You have to predict whether the coin\n"
        << "will come up heads or tails...\n\n";

   for (int i = 0; i < 9; i++)
   {
      // Display battle number and name
      cout << "Battle " << i + 1 << " - " << getBattleName(i) << "\n\n";

      // Prompt the user to input their guess
      cout << "Now General McClellan\n"
           << "Do you predict the coin will come out\n"
           << "heads (H) or tails (T)?\n"
           << "Choose H or T: ";

      // Receive the input from the stream
      cin >> playerGuess;

      // Insert an extra newline after the user hits Return for input
      cout << endl;

      // Validate the user input and force a valid guess if invalid
      // set the echo back variable to heads or tails
      string echoVar = "";
      if (playerGuess == "T" || playerGuess == "t")
      {
         echoVar = "tails";
      }
      else
      {
         playerGuess = "H";
         echoVar = "heads";
      }

      // Echo back the user's guess input and tell
      // them to stand by to fight...
      cout << "You have chosen " << echoVar << endl
           << "Stand by to fight, General\n"
           << "McClellan...\n\n\n";

      // Simulated a coin flip by generating a random integer in range [0, 1]
      // and notify user of result
      coin = rand() % 2;
      cout << coin << "\n\n";
      string echoVarCoin = "";
      if (coin) // Random integer 1
      {
         echoVarCoin = "tails";
      }
      else // Random int 0
      {
         echoVarCoin = "heads";
      }
      cout << "The result of the coin flip was " << echoVarCoin << "\n\n";

      // Use the echo vars to determine who won, and notify user
      if (echoVar == echoVarCoin)
      {
         cout << "Well done, General\n"
              << "McClellan...\n"
              << "You have defeated Lee\n\n";
         ++scorePlayer;
      }
      else
      {
         cout << "I am sorry, General\n"
              << "McClellan...\n"
              << "but the battle goes to Lee\n\n";
         ++scoreComputer;
      }

      // Display a summary of the scores to this point
      cout << "So far: McClellan " << scorePlayer << " victories,\n"
           << "Lee " << scoreComputer << "\n\n\n";
   }

   // Notify the user who won majority of the battles
   string victor = "";
   if (scoreComputer < scorePlayer)
   {
      victor = "George B. McClellan";
   }
   else
   {
      victor = "Robert E. Lee";
   }
   cout << "The results show that\n"
        << victor << " won the\n"
        << "majority of the battles\n"
        << "and is thus declared the victor\n"
        << "on July 2 1863.\n\n";

   // Display the ending screen of the game
   cout << "In the actual Battle at Seven Days,\n"
        << "the Northern troops turned back Lee's\n"
        << "final assaults at Malvern Hill (July 1)....\n\n\n"
        << "The Confederates lost about 16,000\n"
        << "men...\n\n"
        << "The Unionists lost about 20,000 men...\n\n"
        << "McClellan's failure to capture\n"
        << "Richmond, and the subsequent\n"
        << "withdrawal of the Union's Army from\n"
        << "the Yorktown Peninsula, signified the\n"
        << "end of the Peninsular Campaign.\n\n\n";

   return 0;
}

// Precondition: the index of the loop, which will equal
//  one less than the battle number.
// Postcondition: the name of the battle with number
//  index + 1.
string getBattleName(int index)
{
   switch (index)
   {
   case 0:
      return "Little Round Top";
   case 1:
      return "Cemetary Ridge";
   case 2:
      return "Devil's Den";
   case 3:
      return "The Wheatfield";
   case 4:
      return "The Peach Orchard";
   case 5:
      return "Culps Hill";
   case 6:
      return "Zieglers Grove";
   case 7:
      return "Seminary Ridge";
   case 8:
      return "Gettysburg";
   }
   return "";
}