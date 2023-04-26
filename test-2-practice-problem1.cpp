// Stefin Racho
// 4/24/2023
// Test 2 practice - distance problem

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}

double slope(int x1, int y1, int x2, int y2) {
    return (y2 - y1) * 1.0 / (x2 - x1);
}

int main() {
    // set cout to 1 decimal place
    cout << fixed << setprecision(1);

    // initialize the other vars in the table
    int y1 = 5, x2 = -1, y2 = -1;

    // printing the header of the table
    cout << "x1\ty1\tx2\ty2\tDistance\tSlope\n";

    // x1 is the control var for the loop
    for (int x1 = 1; x1 < 52; x1 += 2) {
        // print the row for the table
        cout << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << "\t";
        cout << setprecision(1) << distance(x1, y1, x2, y2) << "\t        ";
        cout << setprecision(2) << slope(x1, y1, x2, y2) << endl;

        //update action
        y1++;
        x2--;
        y2 -= 3;
    }

    // solution to problem 1
    cout << "\nProblem 1:\n";
    cout << "Quadrilateral MATH is a parralelogram if AT = MH and AM = TH\n";
    cout << "Distance of AT = " << distance(-2, 2, 4, 2) << endl;
    cout << "Distance of MH = " << distance(-4, -2, 2, -2) << endl;
    cout << "Distance of AM = " << distance(-2, 2, -4, -2) << endl;
    cout << "Distance of TH = " << distance(4, 2, 2, -2) << endl;
    cout << "Therefore, quadrilateral MATH is a parallelogram.\n\n";

    // solution to problem 2
    cout << "Problem 2:\n";
    cout << "Triangle DEF is an equilateral triangle if DE = ED = FD\n";
    cout << "Distance of DE = " << distance(-3, 3, 3, 3) << endl;
    cout << "Distance of ED = " << distance(3, 3, 0, -3) << endl;
    cout << "Distance of FD = " << distance(0, -3, -3, 3) << endl;
    cout << "Since DE != ED or FD, this proves that triangle DEF is NOT an equilateral triangle.";

    return 0;
}