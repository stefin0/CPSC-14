/*
Stefin Racho
5/3/23
Ferris Wheel - finding force and centripetal acceleration
*/

#include <iostream>
#include <cmath>
using namespace std;

// declaring header functions
double centripitalAcceleration(double angularVelocity, double radius);
double findForceAtTop(double mass, double gravity, double centripetalAcc);
double findForceAtBottom(double mass, double gravity, double centripetalAcc);

int main() {
    // declaring variables
    double radius;
    double centripetalAcc;

    // table header
    cout << "Radius" << "\t" << "centAcc" << "\t\t" << "F at top" << "\t" << "F at bottom\n";
    for (radius = 10; radius <= 70; radius += 5) { // outputting rows os the table
        centripetalAcc = centripitalAcceleration(0.21, radius);
        double forceAtTop = findForceAtTop(70, 9.8, centripetalAcc);
        double forceAtBottom = findForceAtBottom(70, 9.8, centripetalAcc);
        cout << radius << "\t" << centripetalAcc << "\t\t" << forceAtTop << "\t\t" << forceAtBottom << endl;
    }

    return 0;
}

// function that calculates centripital acceleration given the angular
// velocity and the radius.
double centripitalAcceleration(double angularVelocity, double radius) {
    return pow(angularVelocity, 2) * radius;
}

// function that calculates the force at the top of 
// the Ferris Wheel.
double findForceAtTop(double mass, double gravity, double centripetalAcc) {
    return mass * (gravity - centripetalAcc);
}

// function that calculates the force at the bottom of 
// the Ferris Wheel.
double findForceAtBottom(double mass, double gravity, double centripetalAcc) {
    return mass * (gravity + centripetalAcc);
}