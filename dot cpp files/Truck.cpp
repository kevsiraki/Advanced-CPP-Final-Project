#include "Truck.h"

Truck::Truck(string mod, string col, string plat, string trans,
	int gear, int cylinder, int yearMade, int numDrs, string vin, int milesdriven, int mpg, bool elec, double amens,double bcost
	, double lenBed) :Car(mod, col, plat, trans, gear, cylinder, yearMade, numDrs, vin, milesdriven, mpg, elec,amens, bcost)
{
	setLengthOfBed(lenBed);
}

double Truck::calculateCost() const {
	double finalcost = getBaseCost();
	
	if (lengthOfBed > 6.0) {
		for (double i = 6.0; i < lengthOfBed; i += 0.083) //for every inch above 6 feet, I want to add 200 dollars to the price of the truck. (1 inch is approx 0.083 ft)
		{
			finalcost += 200;
		}
	}
	if (getTransmissionType() == 'M' || getTransmissionType() == 'm') { //manual cars are generally slightly cheaper, usually by about 1000 dollars trucks can be manual too!
		finalcost -= 1000;
	}
	if (getMilesPerGallon() > 20 && checkElectric() == false) { //charge more for more efficient cars (unless it is electric).. I want to include this here in case a truck is electric for some reason
		finalcost += 3000;
	}
	if (tolower(getPlatform()[0]) == 'a' || tolower(getPlatform()[0]) == 'r')  //generally, rear wheel drive and all wheel drive cars are more expensive because of performance advantages.
	{
		finalcost += 2000;
	}
	if (getGears() > 5) { //add 1500 per gear! 
		for (int i = 5; i < getGears(); i++) {
			finalcost += 1500;
		}
	}
	if (getCylinders() > 4) { //add 2000 per cylinder! 
		for (int i = 4; i < getCylinders(); i += 2) {
			finalcost += 2000;
		}
	}
	return getPriceAmenities()+(finalcost * calculateDeprecation()); //cost of a truck is determined by the size of its bed. The bed size goes from 6 feet all the way to 8 feet.
}

bool Truck::setLengthOfBed(double lb) //number between 6 feet and 8 feet.
{
	if (lb >= 6.0 && lb <= 8.0) {
		lengthOfBed = lb;
		return true;
	}
	else {
		lengthOfBed = 6.0; //set to a standard value if the desired value is not within the parameters
		return false;
	}
}

double Truck::getLengthOfBed() const {
	return lengthOfBed;
}