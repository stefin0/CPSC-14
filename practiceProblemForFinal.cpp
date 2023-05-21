/*
Stefin Racho
5/16/23
Final Practice - Housing and rent prices.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

double getHousingPE(double homePrice, double currentRent);

int main() {
    // Declaring and initializing variable names.
    ifstream inputStream;
    ofstream outputStream;
    vector<int> homePrice(100);
    vector<int> currentRent(100);
    string fileName = "housingPriceAndRent.txt";

    inputStream.open(fileName);

    // Checking if file was opened.
    if (!inputStream.is_open()) {
        cout << "Could not open input file " << fileName << endl;
    }

    // Inputting data into the 2 vectors.
    int i = 0;
    while (!inputStream.fail()) {
        inputStream >> homePrice.at(i) >> currentRent.at(i); 
        i++;
        if (i == 100)
            break;
    }

    // Checking for errors.
    if (!inputStream.eof()) {
        cout << "Input failure before reaching end of file" << endl;
    }

    // Closing input, then opening output.
    inputStream.close();
    outputStream.open("results.txt");

    // Checking if ouput was successfully opened. 
    if (!outputStream.is_open()) {
        cout << "Could not open file" << endl;
    }

    // Using input to output to results.txt file.
    for (i = 0; i < 100; i++) {
        double housingPE = getHousingPE(homePrice.at(i), currentRent.at(i));

        if (housingPE > 19) {
            outputStream << "House #" << i+1 << " is way overpriced" << endl;
        } else if (housingPE > 16) {
            outputStream << "House #" << i+1 << " is somewhat overpriced" << endl;
        } else if (housingPE < 9) {
            outputStream << "Buy house #" << i+1 << ", it is a deal" << endl;
        } else if (housingPE < 12) {
            outputStream << "House #" << i+1 << " might be a good deal" << endl;
        } else if (housingPE > 12 && housingPE < 16) {
            outputStream << "House #" << i+1 << " is average" << endl;
        }
    }

    return 0;
}

// Function that returns the PE given the price of
// the home and the current rent price.
double getHousingPE(double homePrice, double currentRent) {
    return homePrice / (currentRent * 12);
}