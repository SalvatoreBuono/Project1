#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	int numberBirths = 0;
	const int arraySize = 200000;
	string *Lines = new string[arraySize];
	string *Names = new string[arraySize];
	string *Weights = new string[arraySize];
	// default constructor
	MedicalRecord() {
		// TO BE COMPLETED
	}

	// destructor
	~MedicalRecord() {
		delete[]Lines;
		delete[]Names;
		delete[]Weights;
		// TO BE COMPLETED
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		int i = 0;
		if (myfile.is_open()) { // Begin if 
			cout << "Successfully opened file " << filename << endl;
			// string name;
			//int weight;
			//while (myfile >> name >> weight) {
			// cout << name << " " << weight << endl;
			// Baby b(name, weight);
			// addEntry(b); 

			while (!myfile.eof() && i < arraySize) { // begin while

				getline(myfile, Lines[i]);
				istringstream iss(Lines[i]);
				iss >> Names[i];
				iss >> Weights[i];
				if (Names[i] != "") i++;
			} // end while
			numberBirths = i;
			myfile.close();
		} // end if 
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {

		//const int size = numberBirths;
		int countNames[200000] = { 0 };
		int Max = 0;
		string nameIn;
		string nameOut;

		for (int i = 0; i < numberBirths; i++) { // begin for i
			nameIn = Names[i];

			for (int j = 0; j < numberBirths; j++) { // begin for j 
				if (nameIn == Names[j]) { countNames[i]++; }
			} // end for j 

			if (Max < countNames[i]) { // begin if
				Max = countNames[i];
				nameOut = Names[i];
			} // end if 

		} // for i 

		return nameOut;
	} // end function 


	  // return the number of baby records loaded from the text file
	int numberOfBirths() {
		return numberBirths; // TO BE COMPLETED
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		int countWeights = 0;
		for (int i = 0; i < numberBirths; i++) { // begin for
			const char *cstr = Weights[i].c_str();


			if ('0' == cstr[0] || '1' == cstr[0]) { // begin if
				countWeights++;
			} // end if
			else if ('2' == cstr[0] && ('0' == cstr[1] || '1' == cstr[1] || '2' == cstr[1] || '3' == cstr[1] || '4' == cstr[1])) { // begin else if
				countWeights++;
			} // end else if
			else if (cstr[3] == NULL) {
				countWeights++;
			}
		} // end for
		return countWeights; // TO BE COMPLETED
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		int countNames = 0;
		for (int i = 0; i < numberBirths; i++) {
			if (s == Names[i]) { countNames++; }
		}
		return countNames; // TO BE COMPLETED
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {

		// TO BE COMPLETED
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions

};
