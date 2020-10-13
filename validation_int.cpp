int fetchInput(string promptMsg, string invalidMsg);
// fetchInput prompts for, recieves from the input stream, and validates int
// type input

bool validateInput(int input, int rangeLow, int rangeHigh,
                   string message);
// This function validates the int type input, and prints out
// the provided message if the input is invalid. It ensures that
// the input is within the provided range and is of the correct
// type

// Precondition: prompt message and message to display when invalid input
// received
// Postcondition: returns valid input of type int
int fetchInput(string promptMsg, string invalidMsg)
{
   double input;         // to hold user input
   bool loopFlag = true; // control for validation
   do
   {
      cout << promptMsg;
      cin >> input;
      loopFlag = validateInput(input, 0.0001, 999999999.99, invalidMsg); // we put an upper limit here of 999M and a small lower limit
   } while (loopFlag);
   return input;
}

// Precondtion: pass the function the user input
//              pass the function a range, rangeLow lowest acceptable
//              pass the function a range, rangeHigh highest acceptable
//              pass the message to display for any user error
// Postcondition: returns false if valid and true if not
bool validateInput(int input, int rangeLow, int rangeHigh, string message)
{
   bool goodOrNot = false;
   if ((cin.fail()) || ((input < rangeLow) || (input > rangeHigh)))
   {
      cout << message << endl;
      goodOrNot = true;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   return goodOrNot;
}
