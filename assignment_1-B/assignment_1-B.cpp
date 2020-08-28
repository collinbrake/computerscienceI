/*
  Pgm: ASSGN1-B  Name: Collin Brake
  Purpose: This program will compute the distance an object will fall in time t
  (t is a user input) based on the equation x = x_0 + v_0*t + 1/2*a*t^2 with
  x_0 = 0, v_0 = 0, and a = 32 ft/s^2.
*/

#include <iostream>
#include <math.h>

const int GACCELERATION = 32; // acceleration of gravity in ft/s^2

int main()
{
    using std::cout;
    using std::cin;

    int fallDistance;
    float fallDuration;

    cout << "How long did the object fall?\n";
    cin >> fallDuration;
    fallDistance = pow(fallDuration, 2)*GACCELERATION/2;
    cout << "If an object, starting at rest, is accelerated by\ngravity for "
        << fallDuration << " seconds, it will fall " << fallDistance << " feet.\n";

    return 0;
}
