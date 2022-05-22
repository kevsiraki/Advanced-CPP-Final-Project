#include "CarDealerShip.h"

CarDealerShip::CarDealerShip(string n) {
	name = n;
}

vector<Car*> CarDealerShip::getInventory() const {
	return inventory;
}

void CarDealerShip::addToInventory(Car* toAdd) {
	inventory.push_back(toAdd);
}

bool CarDealerShip::checkInventory(int ind) {
	if (inventory.empty()) //check for empty vector
	{
		return false;
	}
	else if (ind >= inventory.size() || ind < 0) { //check for nonexistent indices
		return false;
	}
	else return true;
}

bool CarDealerShip::checkInventory() { //function overload to check the inventory without an index parameter
	if (inventory.empty()) //check for empty vector
	{
		return false;
	}
	else return true;
}

bool CarDealerShip::removeFromInventory(int index) {
		inventory.erase(inventory.begin() + index);
		return true;
}

void CarDealerShip::setName(const string& n) {
	this->name = n;	//included "this" pointer here
}

string CarDealerShip::getName() const {
	return name;
}

double CarDealerShip::getTotalInventoryPrice() const {
	double tot=0;
	for (Car* x : getInventory()) { //for each car in the vector inventory
		tot += x->calculateCost();
	}
	return tot;
}

ostream& operator<<(ostream& output, const CarDealerShip& cds) {
	int ind;
	ind = 0;
	output << cds.getName() << endl;
	for (Car* x : cds.getInventory()) { //for each car in the vector inventory
		output << "Vehicle Number: " << ind << endl;
		output << *x << endl; //general information of the car
		output << "Final Cost of the Vehicle: $" << x->calculateCost() << endl; //polymorphically calculating cost of the car during runtime.
		output << endl;
		ind++;
	}
	output << "TOTAL PRICE OF INVENTORY: $" << cds.getTotalInventoryPrice() << endl;
	return output;
}