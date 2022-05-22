#ifndef TRUCK_H 
#define TRUCK_H
//derived class Truck. Overrides and redefines pure virtual function calculateCost() which uses the length of truck bed to calculate the cost of the truck.
#include <iostream>
#include <string>
#include "Car.h"
using namespace std;
class Truck:public Car {
private:
	double lengthOfBed; //length of truck bed
public:
	Truck(string = "Generic", string = "White", string = "FWD", string = "A",
		int = 6, int = 4, int = 2019, int = 4, string = "2T2BK1BA5FC260340", int = 0, int = 20, bool = false, double=0.0,double = 20000.00, double = 6.0);
	double calculateCost() const;
	bool setLengthOfBed(double); 
	double getLengthOfBed() const;
};
#endif