// Stefin Racho
// 4/25/2023
// Practice Problem 2 - Lift Equation

#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std;

double lift(double liftCoefficient, double airDensity, double velocity, double surfaceArea) {
    return liftCoefficient * (0.5 * airDensity * pow(velocity, 2)) * surfaceArea;
}

double meterPerSec(double feetPerSec) {
    return feetPerSec * 0.3048;
}

int main() {
    // get the correct number of decimal places
    cout << fixed << setprecision(2);

    // variables used in the lift equation
    double airDensity = 0.30267; // kg/m^3
    double velocity = 265.5; // m/s
    double surfaceArea = 510.97; // m^2
    double liftCoefficient;

    // table 1 header
    cout << "lift coeffecient" << "\t" << "lift (Newtons)\n";
    for (liftCoefficient = 0.1; liftCoefficient < 1.7; liftCoefficient += 0.1) {
        double liftOutput = lift(liftCoefficient, airDensity, velocity, surfaceArea);
        cout << liftCoefficient << "\t\t\t" << liftOutput << endl;
    }

    // table 2 header
    cout << "\nVelocity f/s" << "\t" << "Velocity m/s" << "\t" << "lift (Newtons)\n";
    liftCoefficient = 0.52; // constanst for this table
    for (double velocity = 850; velocity < 900; velocity += 5) {
        double mps = meterPerSec(velocity);
        double liftOutput = lift(liftCoefficient, airDensity, mps, surfaceArea);
        cout << velocity << "\t\t" << mps << "\t\t" << liftOutput << endl;
    }

    // we know that weight = lift
    // and the length of the blade is half the rotor surface area (radius)
    // and surfaceArea = pi * rotorRadius^2
    // so we can substitute bladeLength for rotorRadius giving us:
    // surfaceArea = pi * (bladeLength / 2)^2
    surfaceArea; // m^2
    liftCoefficient = 0.52;
    airDensity = 0.305; // kg/m^3
    velocity = 261.0; // m/s
    double weight = 2830500.0; // newtons

    // now if we manipulate our given equations
    // we can calculate the bladeLength by using this new equation:
    double bladeLength = 2 * sqrt((2 * weight) / (M_PI * liftCoefficient * airDensity * pow(velocity, 2)));
 
    cout << endl << "The length of the helicopter blade needs to be " << bladeLength << " meters to lift the helicopter\n";

    return 0;
}