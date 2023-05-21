/*
Stefin Racho
5/19/2023
Final Exam Practice - Speed of light
*/

/*
Thinking Question:
    If the spaceship going 85% the speed of light, carrying the 35-year-old astronaut that left her 10-year-old daughter on Earth, 
    the time at which they become the same age, according to her own time in the spaceship, the daughter will be 35-years-old. 
    If we set both equations equal to each other:
    (t - 35) * sqrt(1 - pow(SPEED_OF_LIGHT * 0.85, 2) / pow(SPEED_OF_LIGHT, 2)) = (t - 10) * sqrt(1 - pow(SPEED_OF_LIGHT, 2) / pow(SPEED_OF_LIGHT, 2))
    then, solving for t, we get t = 35.
    This indicated that the daughter will be 35-years-old when the mother and daughter are the "same" age, according to the mothers time in the spaceship.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

double timeDilation(double V, double t);
double convertToKmPerSec(double mph);
void percentVelocity(double V);

const int SIZE = 120;
const int SPEED_OF_LIGHT = 300000; // m/s^2

int main()
{
    string rocketName[SIZE];
    double velocity[SIZE];
    double yearsOfTravel[SIZE];

    ifstream inFile;
    string fileName = "RocketData.txt";

    inFile.open(fileName);

    if (!inFile.is_open())
    {
        cout << "Error opening the file for input" << endl;
        return -1;
    }

    // read in header and do nothing with it
    string str = "";
    getline(inFile, str);

    int index = 0;
    while (inFile >> rocketName[index])
    {
        inFile >> velocity[index] >> yearsOfTravel[index];
        // cout << rocketName[index] << " " << velocity[index] << endl;
        index++;
    }

    inFile.close();

    // Header for table
    cout << "Rocket Name | Velocity (as % of light speed) | Earth Time (years) | Rocket Time (years)" << endl;
    // Produce long line
    cout << setfill('-') << setw(87) << "" << endl;
    // Reset fill character back to space
    cout << setfill(' ');

    // Printing out table
    for (int i = 0; i < index; i++)
    {
        // Formatting table
        cout << setw(12) << left << rocketName[i] << "| ";
        percentVelocity(velocity[i]);
        cout << setw(25) << left << " " << "| ";
        cout << setw(19) << left << fixed << setprecision(0) << yearsOfTravel[i] << "| ";
        cout << fixed << setprecision(2) << timeDilation(velocity[i], yearsOfTravel[i]) << endl;
    }
}

double timeDilation(double V, double t)
{
    return t * sqrt(1 - pow(V, 2) / pow(SPEED_OF_LIGHT, 2));
}

double convertToKmPerSec(double mph)
{
    return mph / 2237;
}

void percentVelocity(double V)
{
    cout << fixed << setprecision(2) << (V / SPEED_OF_LIGHT) * 100 << "%";
}