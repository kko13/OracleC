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
	string line1 = order[0];
	string line2 = order[1];
	string* info = new string[3];
	int pHolder = 0;
	int sCount = 0;
	for(int i=0; i<line1.length(); ++i)
	{
		if (line1[i] == ';')
		{	
			info[sCount] = line1.substr(pHolder,i-pHolder);
			pHolder = i;
			sCount = sCount + 1;
		}
	}
	info[2] = line1.substr(pHolder, line1.length()-pHolder);
	info[2] = info[2].substr(1, info[2].length()-1);
	info[1] = info[1].substr(1, info[1].length()-1);
	// test3
	cout << info[0] << endl << info[1] << endl << info[2];

	// test2
	//cout << order[0] << endl << order[1] << endl;

	return 0;
}

