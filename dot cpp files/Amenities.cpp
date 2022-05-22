#include "Amenities.h"

void Amenities::printAmenitiesList() const {
	for (int i = 0; i < 8; i++) {
		cout << amenities[i] << ": $" << amenityPrices[i] << endl;
	}
}
double Amenities::getPriceOfAmenity(int index) const {
	return amenityPrices[index];
}

void Amenities::addToPreviousChoices(int choice) {
	previousChoices.push_back(choice);
}

vector<int> Amenities::getPreviousChoices() const {
	return previousChoices;
}

bool Amenities::setNumAmenities(int num) {
	if (num >= 0 && num <= 8) {
		numAmenities = num;
		return true;
	}
	else {
		numAmenities = 0;
		return false;
	}
}