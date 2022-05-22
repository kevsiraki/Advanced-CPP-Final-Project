#include <iostream>
#include <fstream>

#include "Car.h"
#include "Sedan.h"
#include "Truck.h"
#include "SUV.h"
#include "SportsCar.h"
#include "CarDealerShip.h"

using namespace std;

int main() {
	Sedan* sedanPtr; //The derived class pointers. We cannot instantiate base class Car because it is Abstract.
	Truck* truckPtr;
	SportsCar* sportsCarPtr;
	SUV* suvPtr;

	CarDealerShip galpin("Galpin Dealership"); //CarDealership instance galpin.

	char choice = '0';
	char remIndex[10];  
	char carType[10]; //Used char arrays so I can use atoi() and atof() to convert to ints/doubles for Input Validation.
	char clearChoice[10];
	char overwriteChoice[10];
	char bedLen[10];
	char hp[10];
	char lux[10];
	char nseat[10];

	ofstream os; //file I/O streams.
	ifstream file; 
	string content;
	
	do { //menu loop.
		cout << "1. Show Current Inventory.\n2. Add a car.\n3. Remove a car.\n4. Add the inventory to a text file.\n";
		cout<<"5. Overwrite text file w/ current inventory.\n6. Clear the text file with the inventory in it.\n7. View the Inventory File.\n8. Quit.\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {

		case '1':
			if (galpin.getInventory().empty()) {
				cout << "No cars in your inventory currently! You may add a car by choosing 2." << endl;
			}
			else {
				cout << galpin;
			}
			break;

		case '2':
			cout << "\n1. Sedan\n2. Truck\n3. SportsCar\n4. SUV\nWhat type of car are you adding? (or enter any character to cancel): ";
			cin >> carType;
			cout << endl;
			if (atoi(carType) == 1) {
				sedanPtr = new Sedan();
				cout << "Is this a luxury sedan or regular (0 for regular or 1 for luxury): ";
				cin >> lux;
				while (!sedanPtr->setLuxury((bool)atoi(lux))) {
					cout << "Try again. Is this a luxury sedan (0 or 1):";
					cin >> lux;
				}
				sedanPtr->setLuxury((bool)atoi(lux));
				cin >> *sedanPtr;
				galpin.addToInventory(sedanPtr);
			}
			else if (atoi(carType) == 2) {
				truckPtr = new Truck();
				cout << "\nEnter the size of the bed BETWEEN 6 FEET AND 8 FEET: ";
				cin >> bedLen;
				while (!truckPtr->setLengthOfBed((double)atof(bedLen))) {
					cout << "\nTry again. Enter the size of the bed BETWEEN 6 FEET AND 8 FEET: ";
					cin >> bedLen;
				}
				truckPtr->setLengthOfBed((double)atof(bedLen));
				cin >> *truckPtr;
				galpin.addToInventory(truckPtr);
			}
			else if (atoi(carType) == 3) {
				sportsCarPtr = new SportsCar();
				cout << "\nEnter the horsepower between 250 and 800 you want: ";
				cin >> hp;
				while (!sportsCarPtr->setHorsepower(atoi(hp))) {
					cout << "\nTry again. Enter the horsepower between 250 and 800 you want: ";
					cin >> hp;
				}
				sportsCarPtr->setHorsepower(atoi(hp));
				cin >> *sportsCarPtr;
				galpin.addToInventory(sportsCarPtr);
			}
			else if (atoi(carType) == 4) {
				suvPtr = new SUV();
				cout << "\nEnter the number of seats between 5 and 7: ";
				cin >> nseat;
				while (!suvPtr->setSeats(atoi(nseat))) {
					cout << "\nTry again. Enter the number of seats between 5 and 7: ";
					cin >> nseat;
				}
				suvPtr->setSeats(atoi(nseat));
				cin >> *suvPtr;
				galpin.addToInventory(suvPtr);
			}
			else {
				cout << "Cancelling Vehicle Addition!\n";
			}
			break;

		case '3':
			
			if (galpin.checkInventory()) {
				cout << "Enter the vehicle number to remove or q to cancel: ";
				cin >> remIndex;
				if (remIndex[0] == 'q'|| remIndex[0] == 'Q') {
					cout << "NO VEHICLES REMOVED.\n";
				}
				else {
					while (!galpin.checkInventory(atoi(remIndex))) {
						cout << "VEHICLE DOES NOT EXIST. Enter a valid vehicle number to remove: ";
						cin >> remIndex;
					}
					galpin.removeFromInventory(atoi(remIndex));
					cout << "Vehicle Number " << atoi(remIndex) << " successfully removed. " << endl;
				}
			}
			else {
				cout << "No cars in your inventory currently! You may add a car by choosing 2." << endl;
			}
			break;

		case '4':
			os.open("inventory.txt", std::ios_base::app);
			if (galpin.getInventory().empty()) {
				cout << "CANNOT ADD TO FILE, EMPTY INVENTORY.\n";
			}
			else {
				os << galpin;
				cout << "Inventory has been appended to the file successfully! " << endl;
			}
			os.close();
			break;
		case '5':
			if (galpin.getInventory().empty()) {
				cout << "CANNOT OVERWRITE FILE, EMPTY INVENTORY.\n";
			}
			else {
				cout << "Are you sure you want to overwrite the inventory file? 1 for YES 2 for NO" << endl;
				cin >> overwriteChoice;
				while (atoi(overwriteChoice) != 1 && atoi(overwriteChoice) != 2) {
					cout << "Try Again. Are you sure you want to overwrite the inventory file? 1 for YES 2 for NO" << endl;
					cin >> overwriteChoice;
				}
				if (atoi(overwriteChoice) == 2) {
					cout << "File remains at its current state." << endl;
				}
				else if (atoi(overwriteChoice) == 1) {
					os.close();
					os.open("inventory.txt");
					os << galpin;
					os.close();
					cout << "FILE OVERWRITTEN WITH CURRENT INVENTORY." << endl;
				}
				else {
					cout << "Invalid Choice. Restarting the menu." << endl;
				}
			}
			os.close();
			break;
		case '6':
			file.open("inventory.txt");
			if (file.peek() == ifstream::traits_type::eof()) {
				cout << "File is empty!" << endl;	
			}
			
			else {
				file.close();
				cout << "Are you sure you want to erase the inventory file? 1 for YES 2 for NO" << endl;
				cin >> clearChoice;
				while (atoi(clearChoice) != 1 && atoi(clearChoice) != 2) {
					cout<<"Try Again. Are you sure you want to erase the inventory file? 1 for YES 2 for NO" << endl;
					cin >> clearChoice;
				}
				if (atoi(clearChoice) == 2) {
					cout << "File remains at its current state." << endl;
				}
				else if (atoi(clearChoice) == 1) {
					os.close();
					os.open("inventory.txt", ofstream::out | ofstream::trunc);
					os.close();
					cout << "FILE CLEARED." << endl;
				}
				else {
					cout << "Invalid Choice. Restarting the menu." << endl;
				}
			}
			break;

		case '7':
			file.open("inventory.txt");
			if (file.peek() == ifstream::traits_type::eof()) {
				cout << "File is empty!" << endl;
			}
			else {
				cout << "Contents of Inventory File: " << endl;
				while (getline(file, content)) {
					cout << content << endl;
				}
			}
			file.close();
			break;

		case '8': 
			cout << "Sorry to see you leave! Goodbye!\n";
			break;

		default:
			cout << "Invalid Selection! Restarting the Menu.\n";
			break;
		}
	 } while (choice != '8');

	 for (Car* x : galpin.getInventory()) { //for each car in the vector 
		 x = nullptr; //deallocate every car in the vector
		 delete x;
	 }
	 sedanPtr = nullptr; //deallocate all derived class pointers used for polymorphism
	 truckPtr = nullptr;
	 sportsCarPtr = nullptr;
	 suvPtr = nullptr;
	 delete sedanPtr;
	 delete truckPtr;
	 delete sportsCarPtr;
	 delete suvPtr;
	return 0;
}

/*
	-A simple car dealership software by Kevin Siraki-

	-Concepts from the class:
	1. Files (both I/O)
	2. Polymorphism
	3. Inheritance
	4. Composition
	5. Operator Overloads
	6. Pointers and Dynamic Memory Allocation (used this in one class as well)
	7. Vectors 
	8. Abstract classes/pure virtual functions

	-Other concepts from out of class:
	1. For-each loops for vectors
	2. File truncation/clearing (done carefully so as to not lose data).
	3. atoi(char) function to prevent any crashes in the program if the user enters strings/chars instead of ints/floats/doubles

	-Other Information:
	1. Total number of classes:  8
	2. Total number of files: 17 .cpp and .h (+3 .txt files, so 20 files in total)
*/