//============================================================================               
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
//============================================================================               

#include <iostream>
#include <string>
#include <fstream>
#include "WoodItem.h"
using namespace std;

/*
 * Method to read the input file
 */
string* readInputFile(string inputFilePath) {
        string* lines = new string[2];
        ifstream file (inputFilePath.c_str());
        if (file.is_open())
        {
                getline(file, lines[0]);
                getline(file, lines[1]);
                file.close();
        }
        else
                cout << endl << "Error: Unable to open file" << endl;
                
        return lines;
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime() {
        double deliveryETA = 0.0;
        return deliveryETA;
}

int main() {
        // test1
        //WoodItem x;
        //cout << x.price;

        string* order = readInputFile("order.txt");
        
        // test2
        cout << order[0] << endl << order[1] << endl;
        return 0;
}

