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


   Signed: Collin Brake     Date: 2020-09-24


   COPYRIGHT (C) 2020 by Collin Brake. All Rights Reserved.

   This program creates a simplistic simulation of the Seven Days Battle
   during the Civil War using coin flips.

   author: Collin Brake
   version: 1.01,  2020-09-24
*/

#include <iostream>

using namespace std;

int main()
{
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

    // Display the ending screen of the game
    cout << "In the actual Battle at Seven Days,\n"
        << "the Northern troops turned back Lee's\n"
        << "final assaults at Malvern Hill (July 1)....\n\n\n"
        << "The Confederates lost about 16,000\n";

    return 0;
}