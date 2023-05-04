/*
Stefin Racho
5/3/23
Drag Force - Drag force equation problem
*/

#include <iostream>
#include <cmath>
using namespace std;

// Global constants
double DENSITY_OF_FLUID = 1.2; // kg/m^3

// precondition: Height and width are greater than 0, assume
// given arugment are coorect.
// postcondition: Return the frontal area of the dolphin, with 
// the given height and width.
double frontalAreaDolphin(double height, double width) {
    return height * width;
}

// precondition: The drag being calculated is the drag beind a bike.
// postcondition: Return this constant value, that is given to us.
double bikeDraftBehindCyclist() {
    return 3.9; // this is a given constant, and is in feet squared. 
}

// precondition: Assumed that the given equation, that d2 is diameter squared. 
// And that the diameter is not negative.
// postcondition: Returns the frontal area of the solid sphere.
double solidSphereFrontalArea(double diameter) {
    return (M_PI / 4) * pow(diameter, 2);
}

// precondition: Assumed that the given arguments are all positive.
// postcondition: Return the drag force for the given object arguments. 
double dragForce(double dragCoeffecient, double velocity, double area) {
    return dragCoeffecient * (1.0 / 2.0) * DENSITY_OF_FLUID * pow(velocity, 2) * area;
}

int main() {
    // declaring variables
    double velocity;

    //header for table
    cout << "Velocity" << "\t" << "Dolphin" << "\t\t\t" << "Bicycle" << "\t\t" << "Sphere\n";
    for (velocity = 0; velocity < 101; velocity += 5) {
        double dolphinDrag = dragForce(0.0036, velocity, frontalAreaDolphin(1.5, 1.1));
        double bikeDrag = dragForce(0.5, velocity, bikeDraftBehindCyclist());
        double sphereDrag = dragForce(0.42, velocity, solidSphereFrontalArea(1.1));

        cout << velocity << "\t\t" << dolphinDrag << "\t\t\t" << bikeDrag << "\t\t" << sphereDrag << endl;
    }

    return 0;
}