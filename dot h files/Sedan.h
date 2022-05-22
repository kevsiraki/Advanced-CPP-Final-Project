#ifndef SEDAN_H 
#define SEDAN_H
//derived class Sedan. Overrides and redefines pure virtual function calculateCost(). The sedan can be either a luxury or non luxury sedan.
#include <iostream>
#include <string>
#include "Car.h"
using namespace std;
class Sedan:public Car {
private:
	bool isLuxury=0; //is it a luxury sedan?
public:
	Sedan(bool = false, string = "Generic", string = "White", string = "FWD", string = "A",
		int = 6, int = 4, int = 2019, int = 4, string = "1A2B3C4D5E6F7G8H9", int = 0, int = 20, bool = false,double=0.0, double = 20000.00);
	double calculateCost() const;
	bool setLuxury(bool);
	bool getLuxury() const;
	
};
#endif