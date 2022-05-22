#ifndef SPORTSCAR_H 
#define SPORTSCAR_H
//derived class SportsCar. Overrides and redefines pure virtual function calculateCost() the price of the sports car also takes horsepower into account.
#include <iostream>
#include <string>
#include "Car.h"
using namespace std;
class SportsCar:public Car {
private:
	int horsepower; //desired horsepower
public:
	SportsCar(string = "Generic", string = "White", string = "FWD", string = "A",
		int = 6, int = 4, int = 2019, int = 4, string = "3GSCV53718S596951", int = 0, int = 20, bool = false,double=0.0, double = 20000.00, int = 0);
	double calculateCost() const;
	bool setHorsepower(int);
	int getHorsepower() const;
};
#endif