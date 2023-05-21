/*
Stefin Racho
5/19/2023
Final Exam Practice Problem - Cars
*/

/*
Thinking Question Answer:
    If we wanted to consider the color of the car sold or the trade-in value
    of an old car, then we would need to create an additional arrays for color and one for 
    trade-in value. This would affect the function "averageSalePrice" because now we would have to
    consider if the sale price is for a new car or for a used car. Perhaps, the user might want to 
    know the average salePrice for a used and/or new car. 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int totalSales(string salespersonName, string* salesperson, int size);
double averageSalePrice(string brandName, string* brand, double* salePrice, int size);
string trim(string str);
const int SIZE = 120;

int main()
{
    string dateSold[SIZE];
    string brand[SIZE];
    string model[SIZE];
    double salePrice[SIZE];
    string salesperson[SIZE];

    // Reading in the file code.
    ifstream inFile;
    string fileName = "CarSales.txt";

    inFile.open(fileName);

    // Check if the file was opened correctly.
    if (!inFile.is_open())
    {
        cout << "Error opening the file for input" << endl;
        return -1;
    }

    // read in header and do nothing with it
    string str = "";
    getline(inFile, str);

    // Readind the rest of the records.
    int index = 0;
    while (inFile >> dateSold[index])
    {
        inFile >> brand[index] >> model[index] >> salePrice[index];
        getline(inFile, salesperson[index]);
        salesperson[index] = trim(salesperson[index]);
        // cout << brand[index] << " " << model[index] << " ";
        // cout << salePrice[index] << " " << salesperson[index] << endl;
        index++;
    }

    inFile.close();

    // Testing the code loaded into array
    for (int i = 0; i < index; i++) {
        cout << brand[i] << " " << model[i] << " ";
        cout << salePrice[i] << " " << salesperson[i] << endl;
    }

    // Header for the table of salespeople 
    cout << "Salesperson" << "\t" << "Total Cars sold" << endl;
    for (int i = 0; i < index; i++) {
        cout << salesperson[i] << "\t" << totalSales(salesperson[i], salesperson, index) << endl;
    }

    // Header for the table of average sale price
    cout << "\nToyota\t" << "Ford\t" << "Tesla\t" << endl; 
    cout << averageSalePrice("Toyota", brand, salePrice, index) << "\t";
    cout << averageSalePrice("Ford", brand, salePrice, index) << "\t";
    cout << averageSalePrice("Tesla", brand, salePrice, index) << "\t";
}
// reusing the trim function we found:
// https://cplusplus.com/forum/beginner/208971/
string trim(string str)
{
    // remove trailing white space
    while (!str.empty() && std::isspace(str.back()))
        str.pop_back();

    // return residue after leading white space
    size_t pos = 0;
    while (pos < str.size() && isspace(str[pos]))
        ++pos;
    return str.substr(pos);
}

// This function should take the name of a salesperson as 
// an argument and return the total number of cars they sold.
int totalSales(string salespersonName, string* salesperson, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (salespersonName == salesperson[i]) {
            count++; 
        }
    }
    return count;
}

// Returns the average sale price of a brand
double averageSalePrice(string brandName, string* brand, double* salePrice, int size) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (brandName == brand[i]) {
            sum += salePrice[i];
            count++;
        }
    }
    return sum / count;
}