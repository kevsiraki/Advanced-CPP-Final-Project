#include "Sedan.h"

Sedan::Sedan(bool isLux, string mod, string col, string plat, string trans,
	int gear, int cylinder, int yearMade, int numDrs, string vin, int milesdriven, int mpg, bool elec, 
	double amens, double bcost):Car(mod,col,plat,trans,gear,cylinder,yearMade,numDrs,vin,milesdriven,mpg,elec,amens,bcost) 
{
	setLuxury(isLux);
}

double Sedan::calculateCost() const {
	double finalcost = getBaseCost();
	if (getTransmissionType() == 'M' || getTransmissionType() == 'm') { //manual cars are generally slightly cheaper, usually by about 1000 dollars
		finalcost -= 1000;
	}
	if (getMilesPerGallon() > 20 && checkElectric() == false) { //charge more for more efficient cars (unless it is electric)
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
	if (getLuxury() == 1) {
		finalcost += 5000;
	}
	return (getPriceAmenities() + (finalcost * calculateDeprecation())); //calculate price based on how many amenities were chosen
}

bool Sedan::setLuxury(bool luxStat) {
	if (luxStat == 1 || luxStat == 0) {
	isLuxury = luxStat;
	return true;
	}
	else {
	luxStat = false;
	return false;
	}
}

bool Sedan::getLuxury() const {
	return isLuxury;
}