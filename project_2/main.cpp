/*
    COPYRIGHT (C) 2020 Collin Brake. All rights reserved.
    CSI Project 2
    Author:  Collin Brake, cmb361@zips.uakron.edu.
    Version: 1.01 11.30.2020.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;

const int FLOOR_ARRAY_SIZE = 5;
const int ROOM_ARRAY_SIZE = 8;

//	Transfers are represented by a 'T'
//	The Check outs are represented by a 'C'
//	Nurse work stations are represented by a 'W'
//	Occupied rooms are represented by an asterisk 'O'
//	A vacant room is represented by a 'V'
//	The utility rooms are represented by an 'X'

const char VACANT = 'V';
const char CHECKOUT = 'C';
const char OCCUPIED = 'O';
const char NURSE_STATION = 'W';
const char TRANSFER = 'T';
const char UTILITY = 'X';
const char INVALID = '@';

//Function prototypes

/*
printGrid() prints the grid to the screen.
Precondition: pass the 2D array holding the numeric code for the rooms
    on each floor.
Postcondition: the status of each room in the hospital is displayed as
    a matrix with single character codes as defined by the constants
    above.
*/
void printGrid(
        const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

/*
readGrid() reads in the initial grid from Beds.txt file.
Precondition: pass a 2D array to hold the character codes for the
    status of each room.
Postcondition: the 2D character array is populated based on the mapping
    between the integer status codes stored in the text file and
    the character status codes in this program. The mapping is contained
    in the function definition.
*/
void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);


/*
checkOuts() performs the checkouts
Precondition: pass the 2D character array that holds the codes for
    the status of each room.
Postcondition: every check out status ('C') is changed to the vacant
    status ('V').
*/
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

/*
transfers() performs the transfers and builds the dynamic array of
pointers. It also computes the available number of rooms.
Precondition: pass the 2D character array that holds the codes for
    the status of each room.
Postcondition: returns a 1D array of char pointers, and updates
    the reference variable holding the number of vacant rooms
*/
char** transfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE],
    int &);

/*
newPatient() perform the new patient adds passing the new patient input
from the nurse station and passing the dynamic array of vacancies count
for updating
Precondition: pass the number of new patients requested, the number
    of vacancies, and the vacancies array of char pointers.
Postcondition: a valid number <= number of vacancies is requested,
    and this number of rooms is filled in the hospital. The number
    of vacancies is updated.
*/
void newPatient(int, int &, char**);

/*
newPatientInput() gets the input from the nurse's station. It returns
the nurse station choice, passes the current vacancies.
Precondition: pass the number of vacancies.
Postcondition: return the requested number of rooms to fill. It will
    return a negative number if the user entered one as the quit
    signal.
*/
int newPatientInput(int);

/*
fetchInput prompts for, recieves from the input stream, and
validates int type input.
Precondition: prompt message and message to display when
    invalid input received. Upper and lower limits for
    validation of input.
Postcondition: returns valid input of type int
*/
int fetchInput(string promptMsg, string invalidMsg,
        int upperLimit, int lowerLimit);

/*
validateInput() validates the int type input, and prints out
the provided message if the input is invalid. It ensures that
the input is within the provided range and is of the correct
type
Precondtion: pass the function the user input
    pass the function a range, rangeLow lowest acceptable
    pass the function a range, rangeHigh highest acceptable
    pass the message to display for any user error
Postcondition: returns false if valid and true if not
*/
bool validateInput(int input, int rangeLow, int rangeHigh,
                   string message);

int main()
{
    char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE];

    cout << std::setw(40) << std::setfill('-') << "\n"
        << "Welcome to the CS1 Hospital Management Platform! "
        << "Enter -1 at any point to quit. Press Return to "
        << "start!\n\n";
    string holder;
    getline(cin, holder);

    // Populate the grid from the text file and then display
    // the initial room status values to the console
    readGrid(hospitalFloors);
    printGrid(hospitalFloors);
    cout << "\tGrid loaded\n";

    // Perform checkouts and transfers and then display the
    // new grid.
    checkOuts(hospitalFloors);
    int numVacancies = 0;
    char** vacancies = transfers(hospitalFloors, numVacancies);
    printGrid(hospitalFloors);
    cout << "\tCheck outs and Transfers completed\n";

    // Accept input from the nurses station until numVacancies == 0
    // or quit signal is recieved.
    int numNewPatients = 0;
    while (numVacancies > 0)
    {
        // Get input from nurse's station
        numNewPatients = newPatientInput(numVacancies);

        // If quit signal has been passed upstream by the function
        if (numNewPatients < 0)
        {
            cout << "\t*** More rooms available today ***\n";

            delete vacancies;
            vacancies = nullptr;

            return 0;
        }

        // numVacancies will be updated with the number of pointers
        // that haven't been used yet.
        newPatient(numNewPatients, numVacancies, vacancies);

        printGrid(hospitalFloors);
        cout << "\tNew patient updates completed\n";
    }

    cout << "\t*** No more rooms available today ***\n";

    delete vacancies;
    vacancies = nullptr;

    return 4;
}

void printGrid(
        const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE])
{
    cout << "\t" << std::setw(17) << std::setfill('-') << "\n";
    for (int floor = 0; floor < FLOOR_ARRAY_SIZE; ++floor)
    {
        cout << "\t";
        for (int room = 0; room < ROOM_ARRAY_SIZE; ++room)
        {
            cout << hospitalFloors[floor][room] << " ";
        }
        cout << endl;
    }
    cout << "\t" << std::setw(17) << std::setfill('-') << "\n";
    return;
}


void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE])
{
    // Define the mapping from integers stored in the file to
    // status
    const int VACANT_INT            = 0,
                CHECKOUT_INT        = 1,
                OCCUPIED_INT        = 2,
                NURSE_STATION_INT   = 3,
                TRANSFER_INT        = 4,
                UTILITY_ROOM_INT    = 5;

    // Open the input file
    ifstream layoutFile;
    layoutFile.open("Beds.txt");

    int layoutVal = 6;
    // Loop through the array and initialize each value based on the
    // status integer from the file
    for (int floor = 0; floor < FLOOR_ARRAY_SIZE; ++floor)
    {
        for (int room = 0; room < ROOM_ARRAY_SIZE; ++room)
        {
            // Read in value
            layoutFile >> layoutVal;

            // Check for EOF
            if (layoutFile.eof())
            {
                hospitalFloors[floor][room] = INVALID;
                break;
            }

            // Map layout integer to char in floors array
            switch (layoutVal)
            {
                case VACANT_INT:
                    hospitalFloors[floor][room] = VACANT;
                    break;
                case CHECKOUT_INT:
                    hospitalFloors[floor][room] = CHECKOUT;
                    break;
                case OCCUPIED_INT:
                    hospitalFloors[floor][room] = OCCUPIED;
                    break;
                case NURSE_STATION_INT:
                    hospitalFloors[floor][room] = NURSE_STATION;
                    break;
                case TRANSFER_INT:
                    hospitalFloors[floor][room] = TRANSFER;
                    break;
                case UTILITY_ROOM_INT:
                    hospitalFloors[floor][room] = UTILITY;
                    break;
                default:
                    hospitalFloors[floor][room] = INVALID;
            }
        }
    }
    return;
}

void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE])
{
    for (int floor = 0; floor < FLOOR_ARRAY_SIZE; ++floor)
    {
        for (int room = 0; room < ROOM_ARRAY_SIZE; ++room)
        {
            if (hospitalFloors[floor][room]
                    == 'C')
            {
                hospitalFloors[floor][room]
                    = 'V';
            }
        }
    }
    return;
}


char** transfers(
        char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE],
        int &numVacancies)
{

    numVacancies = 0;

    // Count the number of vacancies. This ref integer is used
    // outside of the function, and is also used to allocate
    // the dynamic array of vacancy addresses.
    for (int floor = 0; floor < FLOOR_ARRAY_SIZE; ++floor)
    {
        for (int room = 0; room < ROOM_ARRAY_SIZE; ++room)
        {
            if (hospitalFloors[floor][room]
                    == VACANT)
            {
                ++numVacancies;
            }
        }
    }

    // Allocate the vacancies array at the right size
    char** vacancies = new char*[numVacancies];

    // Fill the vacancies array
    int i = 0;
    for (int floor = 0; floor < FLOOR_ARRAY_SIZE; ++floor)
    {
        for (int room = 0; room < ROOM_ARRAY_SIZE; ++room)
        {
            if (hospitalFloors[floor][room]
                    == 'V')
            {
                vacancies[i] = &hospitalFloors[floor][room];
                ++i;
                if (i >= numVacancies)
                    break;
            }
        }
    }

    // Swap pointers to perform the transfers
    i = numVacancies-1;
    for (int floor = 0; floor < FLOOR_ARRAY_SIZE; ++floor)
    {
        for (int room = 0; room < ROOM_ARRAY_SIZE; ++room)
        {
            if (hospitalFloors[floor][room]
                    == TRANSFER)
            {
                char* temp = *(vacancies+i);
                char* roomTemp = &hospitalFloors[floor][room];
                *(roomTemp) = VACANT;
                **(vacancies+i) = OCCUPIED;
                *(vacancies+i) = roomTemp;
                roomTemp = temp;

                --i;
                if (i <= 0)
                    break;
            }
        }
    }

    return vacancies;
}

void newPatient(int numNewPatients, int &numVacancies, char **vacancies)
{
    if (numVacancies <= 0)
    {
        return;
    }

    for (int i = 0; i < numNewPatients; ++i)
    {
        // Pop vacancies off the end in LIFO order,
        // decrementing numVacancies.
        **(vacancies + --numVacancies) = OCCUPIED;
    }

    return;
}

int newPatientInput(int numVacancies)
{
    return fetchInput(
        "Please enter the number of new patients, from one up to "
        + std::to_string(numVacancies) + ": ",
        "Invalid entry.",
        numVacancies,
        -1);
}

int fetchInput(string promptMsg, string invalidMsg, int upperLimit,
        int lowerLimit)
{
   double input;         // to hold user input
   bool loopFlag = true; // control for validation
   do
   {
      cout << promptMsg;
      cin >> input;
      loopFlag = validateInput(input, lowerLimit, upperLimit,
              invalidMsg);
   } while (loopFlag);
   return input;
}


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
