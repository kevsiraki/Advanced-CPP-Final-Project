#ifndef CARDEALERSHIP_H 
#define CARDEALERSHIP_H
//class CarDealership. Basically a vector of Car pointers to store an inventory of cars.
#include <string>
#include <iostream>
#include <fstream>
#include "Car.h"
#include <vector>
using namespace std;
class CarDealerShip {
	friend ostream& operator<<(ostream&, const CarDealerShip&); //output stream overload 
private:
	vector<Car*> inventory; //CarDealerShip HAS A vector of Car*
	string name; //name of dealership
public:
	CarDealerShip(string);
	vector<Car*> getInventory() const;		//see the inventory
	void addToInventory(Car*); 				//add a car to the inventory
	bool removeFromInventory(int); 			//remove/sell a car in the inventory.
	void setName(const string&); 			//set the dealership name
	string getName() const; 				//get the dealership name
	double getTotalInventoryPrice() const; //get the total final price of all the cars in the inventoy.
	bool checkInventory(int); 				//see if a car exists in the inventory.
	bool checkInventory(); 					//overloaded so we can check if its empty without passing an index parameter
};
#endif