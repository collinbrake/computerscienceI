/*
    COPYRIGHT (C) 2020 Collin Brake. All rights reserved.
    CSI Project 2
    Author:  Collin Brake, cmb361@zips.uakron.edu.
    Version: 1.01 11.30.2020.
*/

#include <iostream>
#include <iomanip>
#include <fstream>


using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

const int FLOOR_ARRAY_SIZE = 5;
const int ROOM_ARRAY_SIZE = 8;

//	Transfers are represented by a ‘T’.
//	The Check outs are represented by a ‘C’.
//	Nurse work stations are represented by a ‘W’.
//	Occupied rooms are represented by an asterisk ‘O’.
//	A VACANT_INT room is represented by a blank ‘V’.
//	The utility rooms are represented by an ‘X’.

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
void printGrid(const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

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
Postcondition: every check out status ('C') is changed to the VACANT_INT
    status ('V').
*/
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

/*
transfers() performs the transfers and builds the dynamic array of pointers. It also computes the available number of rooms.
Precondition: pass the 2D character array that holds the codes for
    the status of each room.
Postcondition: returns a 1D array of char pointers TODO!!! finish this comment FIXME
*/
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &);

/*
newPatient() perform the new patient adds passing the new patient input
from the nurse station and passing the dynamic array of vacancies count
for updating
*/
void newPatient(int, int &, char **);

/*
 Pre and Post condition comments go here ... function for the input from the nurse's station. It returns
 the nurse station choice, passes the current vacancies.
*/
int newPatientInput(int);

int main()
{
    char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]
        ;//= {{INVALID}};

    // Populate the grid from the text file and then display
    // the initial room status values to the console
    readGrid(hospitalFloors);
    printGrid(hospitalFloors);
    cout << "\tGrid loaded\n";

    // Perform checkouts and transfers and then display the
    // new grid.
    checkOuts(hospitalFloors);
    /*
    int numVacancies = 0;
    char** vacancies = transfers(hospitalFloors, numVacancies);
    printGrid(hospitalFloors);
    cout << "\tCheck outs and Transfers complete\n";

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
            return 0;
        }

        // numVacancies will be updated with the number of pointers
        // that haven't been used yet.
        newPatient(numNewPatients, numVacancies, vacancies);

        printGrid(hospitalFloors);
        cout << "\tNew patient updates completed\n"
    }

    */

    cout << "\t*** No more rooms available today ***\n";
    return 4;
}

// FUNCTIONS GO HERE TODO remove

void printGrid(
        const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE])
{
    cout << "\t" << std::setw(20) << std::setfill('-') << "\n";
    for (int floor = 0; floor < FLOOR_ARRAY_SIZE; ++floor)
    {
        cout << "\t";
        for (int room = 0; room < ROOM_ARRAY_SIZE; ++room)
        {
            cout << hospitalFloors[floor][room] << " ";
        }
        cout << endl;
    }
    cout << "\t" << std::setw(20) << std::setfill('-') << "\n";
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
    return;
}
