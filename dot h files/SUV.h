#ifndef SUV_H 
#define SUV_H
//derived class SUV. Overrides and redefines pure virtual function calculateCost() which also uses the number of seats to calculate the cost of the car
#include <iostream>
#include <string>
#include "Car.h"
using namespace std;
class SUV :public Car {
private:
	int numSeats; //suvs have a MINIMUM of 5 seats and a maximum of 7.
public:
	SUV(string = "Generic", string = "White", string = "FWD", string = "A",
		int = 6, int = 4, int = 2019, int = 4, string = "3GSCL53718S596951", int = 0, int = 20, bool = false, double = 0.0, double = 20000.00, int = 0);
	double calculateCost() const;
	bool setSeats(int);
	int getSeats() const;
};
#endif