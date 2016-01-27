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
#include <stdlib.h>
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

int main() {
	// WoodItem initilization
	WoodItem Cherry("Cherry",2.5,5.95);
	WoodItem Curly("Curly Maple",1.5,6.00);
	WoodItem Gen("Genuine Mahogany",3,9.60);
	WoodItem Wenge("Wenge",5,22.35);
	WoodItem White("White Oak",2.3,6.70);
	WoodItem Saw("Sawdust",1,1.50);

	// User input
	string fileName;
	cout << "What file would you like to calculate?" << endl;
	cin >> fileName;
	string* order = readInputFile(fileName);
	
	// Input seperation line1
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
	
	// WoodReq parse
	vector<int> amounts;
	vector<string> types;
	for(int i=0; i<woodReqs.size(); i++)
	{
		size_t found = woodReqs[i].find(':');
		string type = woodReqs[i].substr(0,found);
		string amount = woodReqs[i].substr(found+1, woodReqs[i].length()-found);
		int amountInt = atoi(amount.c_str());
		amounts.push_back(amountInt);
		types.push_back(type);
	}

	// Price and delivery time calculation
	vector<double> prices;
	vector<double> dTime;
	for(int i=0; i<types.size(); i++)
	{
		if(types[i] == Cherry.type)
		{
			prices.push_back(Cherry.price * amounts[i]);
				if(amounts[i] <= 100)
					dTime.push_back(Cherry.baseDeliveryTime);
				else if((amounts[i]>=101) && (amounts[i]<=200))
					dTime.push_back(Cherry.baseDeliveryTime * 2);
				else if((amounts[i]>=201) && (amounts[i]<=300))
					dTime.push_back(Cherry.baseDeliveryTime *3);
				else if((amounts[i]>=301) && (amounts[i]<=400))
					dTime.push_back(Cherry.baseDeliveryTime *4);
				else if((amounts[i]>=401) && (amounts[i]<=500))
					dTime.push_back(Cherry.baseDeliveryTime *5);
				else
					dTime.push_back(Cherry.baseDeliveryTime *5.5);
		}
		else if(types[i] == Curly.type)
		{
			prices.push_back(Curly.price * amounts[i]);
				if(amounts[i] <= 100)
                                        dTime.push_back(Curly.baseDeliveryTime);            
                                else if((amounts[i]>=101) && (amounts[i]<=200))              
                                        dTime.push_back(Curly.baseDeliveryTime * 2);        
                                else if((amounts[i]>=201) && (amounts[i]<=300))              
                                        dTime.push_back(Curly.baseDeliveryTime *3);         
                                else if((amounts[i]>=301) && (amounts[i]<=400))              
                                        dTime.push_back(Curly.baseDeliveryTime *4);         
                                else if((amounts[i]>=401) && (amounts[i]<=500))              
                                        dTime.push_back(Curly.baseDeliveryTime *5);         
                                else
                                        dTime.push_back(Curly.baseDeliveryTime *5.5);
		}
		else if(types[i] == Gen.type)
                {
			prices.push_back(Gen.price * amounts[i]);
				if(amounts[i] <= 100)
                                        dTime.push_back(Gen.baseDeliveryTime);            
                                else if((amounts[i]>=101) && (amounts[i]<=200))              
                                        dTime.push_back(Gen.baseDeliveryTime * 2);        
                                else if((amounts[i]>=201) && (amounts[i]<=300))              
                                        dTime.push_back(Gen.baseDeliveryTime *3);         
                                else if((amounts[i]>=301) && (amounts[i]<=400))              
                                        dTime.push_back(Gen.baseDeliveryTime *4);         
                                else if((amounts[i]>=401) && (amounts[i]<=500))              
                                        dTime.push_back(Gen.baseDeliveryTime *5);         
                                else
                                        dTime.push_back(Gen.baseDeliveryTime *5.5);
                }
		else if(types[i] == Wenge.type)
                {
			prices.push_back(Wenge.price * amounts[i]);
				if(amounts[i] <= 100)
                                        dTime.push_back(Wenge.baseDeliveryTime);            
                                else if((amounts[i]>=101) && (amounts[i]<=200))              
                                        dTime.push_back(Wenge.baseDeliveryTime * 2);        
                                else if((amounts[i]>=201) && (amounts[i]<=300))              
                                        dTime.push_back(Wenge.baseDeliveryTime *3);         
                                else if((amounts[i]>=301) && (amounts[i]<=400))              
                                        dTime.push_back(Wenge.baseDeliveryTime *4);         
                                else if((amounts[i]>=401) && (amounts[i]<=500))              
                                        dTime.push_back(Wenge.baseDeliveryTime *5);         
                                else
                                        dTime.push_back(Wenge.baseDeliveryTime *5.5);
                }
		else if(types[i] == White.type)
                {
			prices.push_back(White.price * amounts[i]);
				if(amounts[i] <= 100)
                                        dTime.push_back(White.baseDeliveryTime);            
                                else if((amounts[i]>=101) && (amounts[i]<=200))              
                                        dTime.push_back(White.baseDeliveryTime * 2);        
                                else if((amounts[i]>=201) && (amounts[i]<=300))              
                                        dTime.push_back(White.baseDeliveryTime *3);         
                                else if((amounts[i]>=301) && (amounts[i]<=400))              
                                        dTime.push_back(White.baseDeliveryTime *4);         
                                else if((amounts[i]>=401) && (amounts[i]<=500))              
                                        dTime.push_back(White.baseDeliveryTime *5);         
                                else
                                        dTime.push_back(White.baseDeliveryTime *5.5);
                }
		else
                {
			prices.push_back(Saw.price * amounts[i]);
				if(amounts[i] <= 100)
                                        dTime.push_back(Saw.baseDeliveryTime);            
                                else if((amounts[i]>=101) && (amounts[i]<=200))              
                                        dTime.push_back(Saw.baseDeliveryTime * 2);        
                                else if((amounts[i]>=201) && (amounts[i]<=300))              
                                        dTime.push_back(Saw.baseDeliveryTime *3);         
                                else if((amounts[i]>=301) && (amounts[i]<=400))              
                                        dTime.push_back(Saw.baseDeliveryTime *4);         
                                else if((amounts[i]>=401) && (amounts[i]<=500))              
                                        dTime.push_back(Saw.baseDeliveryTime *5);         
                                else
                                        dTime.push_back(Saw.baseDeliveryTime *5.5);
                }
	}
	double totalPrice = 0;
	for(int i=0; i<prices.size();i++)
		totalPrice = prices[i] + totalPrice;
	
	// Delivery time final calculation
	double topTime = 0; 
	for(int i=0; i<dTime.size();i++)
	{
		if(dTime[i] > topTime)
			topTime = dTime[i];
	}
	
	// Output functionality
	int c = 0;
	cout << info[0] << ", " << info[1] << endl;
	for(vector<string>::iterator it = woodReqs.begin(); it!= woodReqs.end(); ++it)
	{
		cout << " | " << *it << ":$" << prices[c];
		c = c + 1;
	}
	cout << " | " << endl;
	cout << "Total Price: $" << totalPrice << endl;
	cout << "Estimated Delivery Time: " << topTime << "hrs" << endl;
	return 0;
}

