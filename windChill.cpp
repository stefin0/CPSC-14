/*
Stefin Racho
5/3/23
Wind Chill - fahrenheit and celsius
*/

#include <iostream>
#include <cmath>
using namespace std;

// function headers
double windChill(double velocity, double temperature);
double fahrenheitToCelsius(double fahrenheit);

int main() {
    double velocity = 8.5; // m/sec
    double temp = -100; // celsius
    
    // first table - temp is in celsius
    cout << "Celsius" << "\t\t" << "Wind Chill\n";
    for (temp = -100; temp <= 10; temp += 10) {
        cout << temp << "\t\t" << windChill(velocity, temp) << endl; //print a row in our table
    }

    // second table - temp is in fahrenheit
    cout << "\nFahrenheit" << "\t" << "Wind Chill\n";
    for (temp = -30; temp <= 50; temp += 5) {
        double celsius = fahrenheitToCelsius(temp);
        cout << temp << "\t\t" << windChill(velocity, celsius) << endl;
    }

    return 0;
}

// definition of function, function body
double windChill(double velocity, double temperature) {
    return 33 - (((10 * sqrt(velocity) - velocity + 10.5)*(33 - temperature)) / (23.1));
}

// converting from fahrenheit to celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0/9.0;
}