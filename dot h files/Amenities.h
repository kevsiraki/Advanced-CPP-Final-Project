#ifndef AMENITIES_H 
#define AMENITIES_H
//regular class Amenities. Every car needs to have a wide variety of options for amenities to suit the needs of the buyer. Pretty straight forward class.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Amenities {
private:
	string amenities[8] = { "0. Heated Seats","1. Backup Cam","2. Bluetooth","3. Bose Sound System", "4. Leather Seats","5. Widened Body","6. Rear TV","7. Sunroof" };
	double amenityPrices[8] = {1000.0,700.0,300.0,1500.0,1200.00,2000.0,400.0,500.0};
	vector<int> previousChoices; //vector that will store the previous user inputs so they cannot select an amenity twice.
	int numAmenities;
public:
	//uses default constructor
	void addToPreviousChoices(int); //used to check if user previously chose an amenity.
	void printAmenitiesList() const; //simply prints the array of amenities and the prices of each amenity.
	double getPriceOfAmenity(int) const; //returns the price of a certain amenity.
	vector<int> getPreviousChoices() const; //returns the users previous choices.
	bool setNumAmenities(int); //sets the number of amenities the user has chosen.
};
#endif