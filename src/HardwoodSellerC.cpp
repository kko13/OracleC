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
#include <vector>
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
	// WoodItem initilization
	WoodItem Cherry("Cherry",2.5,5.95);
	WoodItem Curly("Curly Maple",1.5,6.00);
	WoodItem Gen("Genuine Mahogany",3,9.60);
	WoodItem Wenge("Wenge",5,22.35);
	WoodItem White("White Oak",2.3,6.70);
	WoodItem Saw("Sawdust",1,1.50);

	// Input seperation line1
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
	
	// Input seperation line2
	vector<string> woodReqs;
	pHolder = 0;
	for(int i=0; i<line2.length(); ++i)
	{
		if(line2[i] == ';')
		{
			woodReqs.push_back(line2.substr(pHolder,i-pHolder));
			pHolder = i;
		}
	}
	woodReqs.push_back(line2.substr(pHolder, line2.length()-pHolder));
	woodReqs[1] = woodReqs[1].substr(1, woodReqs[1].length()-1);
	woodReqs[2] = woodReqs[2].substr(1, woodReqs[2].length()-1);
	woodReqs[3] = woodReqs[3].substr(1, woodReqs[3].length()-1);

	// Output functionality
	cout << info[0] << ", " << info[1] << endl;
	for(vector<string>::iterator it = woodReqs.begin(); it!= woodReqs.end(); ++it)
		cout << " | " << *it;
	cout << endl;
	return 0;
}

