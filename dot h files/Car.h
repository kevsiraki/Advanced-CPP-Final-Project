#ifndef CAR_H 
#define CAR_H
//abstract base class Car. Too general to have an instance of just a car...
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "fileParser.h";
#include "Amenities.h"
using namespace std;
class Car {
	friend ostream& operator<<(ostream&, const Car&); //i/o stream overloads
	friend istream& operator>>(istream&, Car&);
private:
	Amenities amenities; //every car HAS 8 amenities
	fileParser fp; //every car HAS A fileparser (for checking valid model and color).

	string model; //from a database of cars
	string color; //from a database of colors
	string platform; //AWD, FWD, RWD
	string transmissionType; //M for manual A for automatic
	int gears; //how many gears
	int cylinders; //how many cylinders
	int year; //year car was MADE
	int numDoor; //we offer 2 and 4 door cars, quite standard.
	string vinNumber; //must be 17 numbers and capital digits
	int mileage; //how many miles does the car have
	int milesPerGallon; //average mpg
	bool isElectric; //is it electric? electric cars will be allowed to have different parameters for their MPG and will not be more expensive for their efficiency.
	double priceOfAmenities=0; //amenities price
	double baseCost; //BASE COST of a car. the final cost will be way different depending on the type of car, how it depreciates and other factors above.
	
public:
	Car(string = "Generic", string = "White", string = "FWD", string = "A",
		int = 6, int = 4, int = 2019, int = 4, string = "1N4AL3AP3EC143447", int = 0, int = 20, bool = false, double=0.0,double = 20000.00);
	//get
	string getModel() const;
	string getColor() const;
	string getPlatform() const;
	char getTransmissionType() const;
	int getGears() const;
	int getCylinders() const;
	int getYear() const;
	int getNumDoor() const;
	string getVinNumber() const;
	int getMileage() const;
	int getMilesPerGallon() const;
	bool checkElectric() const;
	double getPriceAmenities() const;
	double getBaseCost() const;
	//set
	void setModel(const string&); 
	void setColor(const string&); 
	bool setPlatform(string); //"MUST BE AWD, RWD, OR FWD "
	bool setTransmissionType(const string&); //either A for automatic or M for manual
	bool setGears(int); //must be a number less than 10, obviously no negatives.
	bool setCylinders(int); //must be an even number greater than or equal to 12, obviously no negatives.
	bool setYear(int); //must be a 4 digit year, no cars older than 1980, obviously no negatives.
	bool setNumDoor(int); //we only have 2 or 4 door cars, obviously no negatives.
	bool setVinNumber(const string&); //must be 17 numbers and capital digits, will do validity checking on this to ensure authenticity, obviously no negatives.
	bool setMileage(int); // obviously no negatives. we do not sell cars with more than 300,000 miles.
	bool setMilesPerGallon(int); //no negatives or 0, must be a realistic value more than 10 and can go as high as 40 for non electric, 200 for electric.
	bool setElectric(bool); //must be a binary value.
	bool setAmenities(double);
	void setAmenitiesPrice(double);
	bool setBaseCost(double); //must be a double value between 5000 and 100000, obviously no negatives.
	
	double calculateDeprecation() const; //dependent on year made, mileage, returns a percentage to multiply the base cost by to get the calculateCost final cost. same for every car.
	//PURE virtual function that MUST be overriden and will be different for every car!
	virtual double calculateCost() const=0;  //dependent on depreciation, transmission type, gears, cylinders, milesperGallon DIFFERENT WAYS TO CALCULATE DEPENDING ON THE CAR!!!
};
#endif