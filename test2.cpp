/*
Stefin Racho
5/11/23
Test 2 - Flight of a Projectile Problem
*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double GRAVITY = 9.81; // m/s^2

// Declaring function headers
double findMaxHeight(double v0, double angle);
double findHorizontalRange(double v0, double angle);
double findTimeOfFlight(double u, double angle);

int main() {
    // Declaring and initializing varables
    double angle;
    double v0 = 10;

    // Header for table
    cout << "Initial Velocity (m/s) | Launch Angle (degrees) | Maximum Height (m) | Horizontal Range (m) | Time of Flight (s)" << endl;

    // Produce long line
    cout << setfill('-') << setw(112) << "" << endl;
    // Reset fill character back to space
    cout << setfill(' ');

    // Printing out table
    for (double angle = 30; v0 < 40; angle += 15) {
        if (angle > 60) {
            v0 += 10;
            angle = 30;
        }
        // Formatting table
        cout << setw(23) << left << fixed << setprecision(0) << v0 << "|";
        cout << setw(24) << left << fixed << setprecision(0) << angle << "|";
        cout << setw(20) << left << fixed << setprecision(2) << findMaxHeight(v0, angle) << "|";
        cout << setw(22) << left << fixed << setprecision(2) << findHorizontalRange(v0, angle) << "|";
        cout << fixed << setprecision(2) << findTimeOfFlight(v0, angle) << endl;
    }

    // Produce long line
    cout << setfill('-') << setw(112) << "" << endl;

    return 0;
}

// Function that calculates the maximum height given the 
// initial velocity and angle
double findMaxHeight(double v0, double angle) {
    // Converting given angle to radians
    double radians = angle * (M_PI / 180);

    return (pow(v0, 2) * pow(sin(radians), 2)) / (2 * GRAVITY);
}

// Function that calculates the maximum range given the 
// initial velocity and angle
double findHorizontalRange(double v0, double angle) {
    // Converting given angle to radians
    double radians = angle * (M_PI / 180);

    return (pow(v0, 2) * sin(2 * radians)) / GRAVITY;
}

// Function that calculates the flight time given the 
// initial velocity and angle
double findTimeOfFlight(double v0, double angle) {
    // Converting given angle to radians
    double radians = angle * (M_PI / 180);

    return (2 * v0 * sin(radians)) / GRAVITY;
}