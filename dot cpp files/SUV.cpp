#include "SUV.h"

SUV::SUV(string mod, string col, string plat, string trans,
	int gear, int cylinder, int yearMade, int numDrs, string vin, int milesdriven, int mpg, bool elec, double amens, double bcost
	, int seats) :Car(mod, col, plat, trans, gear, cylinder, yearMade, numDrs, vin, milesdriven, mpg, elec, amens, bcost)
{
	setSeats(seats);
}
double SUV::calculateCost() const {
	double finalcost = getBaseCost();
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

	return getPriceAmenities() + (1000 * (double)numSeats) + (finalcost * calculateDeprecation()); //cost of a sportscar is determined by the horsepower (which is a value between 250 and 800 (realistic values))
}

bool SUV::setSeats(int seats) {
	if (seats>=5&&seats<=7) {  //SUV must have between 5 and 7 seats on top of the other amenities the user choses for the seats.
		numSeats = seats;
		return true;
	}
	else {
		seats = 5;
		return false;
	}
}

int SUV::getSeats() const {
	return numSeats;
}