// Stefin Racho
// 4/26/2023
// Test 2 Practice - Water Velocity

#include <iostream>
#include <math.h>
using namespace std;

// global variable
double waterFlowRate = 30.562; // m^3/h

double waterVelocity(double diameter) {
    return (waterFlowRate) / (3600 * M_PI * pow((diameter / 2), 2));
}

double volume(double radius, double height) {
    return M_PI * pow(radius, 2) * height;
}

double secToHours(double seconds) {
    return seconds / 3600;
}

int main() {
    // creation of data table
    cout << "Pipe Diameter (m)" << "\t" << "Water Velocity (m/s)\n";
    for (int diameter = 1; diameter < 11; diameter++) {
        cout << diameter << "\t\t\t" << waterVelocity(diameter) << endl;
    }

    // calculating the volume of the cylinder 
    double cylinderVolume = volume(4, 12);
    cout << "\nThe volume of a cylinder with a radius of 4 meters and a height of 12 meters is " << cylinderVolume << " cubic meters." << endl;

    // converting waterFlowRate into seconds
    double secFlowRate = waterFlowRate / 3600;

    // Now that we have all metrics in SI Units, we can calculate
    // the time it takes to fill the tank by dividing the Volume (m^3) with the Flow Rate (m^3/second).
    // As you can see, the cubic meters will cancel, leaving us with just seconds.
    double seconds = cylinderVolume / secFlowRate;

    // Now we convert the seconds into hours using our own function.
    double hours = secToHours(seconds);
    cout << "\nThe time it would take to fill the cylindrical tank with water is " << seconds << " seconds, or " << hours << " hours.\n";

    return 0;
}