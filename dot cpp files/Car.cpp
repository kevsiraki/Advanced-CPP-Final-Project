#include "Car.h"


Car::Car(string mod, string col, string plat, string trans,
	int gear, int cylinder, int yearMade, int numDrs, string vin, int milesdriven, int mpg, bool elec,double amens, double bcost)
{
	setModel(mod);
	setColor(col);
	setPlatform(plat);
	setTransmissionType(trans);
	setGears(gear);
	setCylinders(cylinder);
	setYear(yearMade);
	setNumDoor(numDrs);
	setVinNumber(vin);
	setMileage(milesdriven);
	setMilesPerGallon(mpg);
	setAmenitiesPrice(amens);
	setBaseCost(bcost);
}

//get
string Car::getModel() const {
	return model;
}
string Car::getColor() const {
	return color;
}
string Car::getPlatform() const {
	return platform;
}
char Car::getTransmissionType() const {
	return transmissionType[0];
}
int Car::getGears() const {
	return gears;
}
int Car::getCylinders() const {
	return cylinders;
}
int Car::getYear() const {
	return year;
}
int Car::getNumDoor() const {
	return numDoor;
}
string Car::getVinNumber() const {
	return vinNumber;
}
int Car::getMileage() const {
	return mileage;
}
int Car::getMilesPerGallon() const {
	return milesPerGallon;
}
bool Car::checkElectric() const {
	return isElectric;

}
double Car::getPriceAmenities() const {
	return priceOfAmenities;
}
double Car::getBaseCost() const {
	return baseCost;
}

//set
void Car::setModel(const string& mod) {
	model = mod;
}
void Car::setColor(const string& col) 
{
	color = col;
}
bool Car::setPlatform(string plat)
{
	if ((tolower(plat[1]) == 'w' && tolower(plat[2]) == 'd')&& (tolower(plat[0])=='a'|| tolower(plat[0]) == 'r'|| tolower(plat[0])=='f' ) ) {
		platform = plat;
		return true;
	}
	else {
		platform = "FWD";
		return false;
	}
}
bool Car::setTransmissionType(const string& tt) //either A for automatic or M for manual
{
	if (tt[0] == 'A' || tt[0] == 'M' || tt[0] == 'a' || tt[0] == 'm') {
		transmissionType = tt[0];
		return true;
	}
	else {
		transmissionType = 'A';
		return false;
	}
}
bool Car::setGears(int ngears) //must be a number less than 10 and more than/equal 5, obviously no negatives.
{
	if (ngears <= 10 && ngears >= 5) {
		gears = ngears;
		return true;
	}
	else {
		gears = 6;
		return false;
	}
}
bool Car::setCylinders(int ncylinder) //must be an even number less than or equal to 12, greater than or equal to 4 (realistically), obviously no negatives.
{
	if (ncylinder <= 12 && ncylinder >=4 &&ncylinder%2==0) {
		cylinders = ncylinder;
		return true;
	}
	else {
		cylinders = 4;
		return false;
	}
}
bool Car::setYear(int yr) //must be a 4 digit year, no cars older than 1980, obviously no negatives.
{
	if (yr >= 1980 && yr <= 2020) {
		year = yr;
		return true;
	}
	else {
		year = 2019;
		return false;
	}
}
bool Car::setNumDoor(int ndoors) //we only have 2 or 4 door cars, obviously no negatives.
{
	if (ndoors == 4 || ndoors == 2) {
		numDoor = ndoors;
		return true;
	}
	else {
		numDoor = 4;
		return false;
	}
}
bool Car::setVinNumber(const string& vi) //must be 17  digits, will do validity checking on this to ensure authenticity, obviously no negatives.
{
	int i = 0;
	for (i = 0; vi[i] != '\0'&&vi[i]>=0; i++);
	if (i == 17) {
		vinNumber = vi;
		return true;
	}
	else {
		vinNumber = "1A2B3C4D5E6F7G8H9";
		return false;
	}
}
bool Car::setMileage(int mi) // obviously no negatives. we do not sell cars with more than 300,000 miles.
{
	if (mi >= 0 && mi <= 300000) {
		mileage = mi;
		return true;
	}
	else {
		mileage = 0;
		return false;
	}
}
bool Car::setMilesPerGallon(int mg) //no negatives or 0, must be a realistic value more than 10 and can go as high as 200 (anything above 40 must be electric).
{
	if (mg > 40 && mg <= 200) {
		setElectric(1);
		milesPerGallon = mg;
		return true;
	}
	else if(mg >= 10 && mg <= 40) {
		milesPerGallon = mg;
		return true;
	}
	else {
		milesPerGallon = 20;
		return false;
	}
}
bool Car::setElectric(bool el) //must be a binary value.
{
	if (getMilesPerGallon() > 40) {
		isElectric = 1;
		return true;
	}
	else if (el == 1 || el == 0) {
		isElectric = el;
		return true;
	}
	else {
		isElectric = false;
		return false;
	}
}
bool Car::setBaseCost(double bc) //must be a double value between 5000 and 100000, obviously no negatives. (note, the BASE price must be 100000 max. after calculations it is allowed to be higher).
{
	if (bc >= 5000 && bc <= 100000) {
		baseCost = bc;
		return true;
	}
	else {
		baseCost = 20000;
		return false;
	}
}

bool Car::setAmenities(double am) {
	if (am >= 0 && am <= 7) {
		priceOfAmenities = amenities.getPriceOfAmenity(am);
		return true;
	}
	else {
		priceOfAmenities = 0;
		return false;
	}
}

void Car::setAmenitiesPrice(double totalPrice) {
	priceOfAmenities = totalPrice;
}

double Car::calculateDeprecation() const//car loses 20 percent of value every 10,000 miles. 
{
	double averageVal=1;
	if (mileage >= 10000) {
		for (int i = 10000; i < mileage;i += 10000) {
				if(averageVal>=.30) //car value cannot be less than 30 percent of its original cost.
					averageVal -= 0.05;
		}
	}
	
	return averageVal;
}
double Car::calculateCost() const//dependent on depreciation, transmission type, gears, cylinders, milesperGallon
{
	double finalcost = baseCost;
	if (transmissionType[0] == 'M'|| transmissionType[0] == 'm') { //manual cars are generally slightly cheaper, usually by about 1000 dollars
		finalcost -= 1000;
	}
	else if (milesPerGallon > 20 && isElectric==0) { //charge more for more efficient cars (unless it is electric)
		finalcost += 3000;
	}

	return finalcost* calculateDeprecation()+ getPriceAmenities();
}


ostream& operator<<(ostream& outputFile, const Car& car) {

	outputFile << "Model: "<<car.getModel()<<'\n';
	outputFile << "Color: "<< car.getColor() << '\n';
	outputFile << "Platform: "<< car.getPlatform() << '\n';
	outputFile << "Manual or Automatic: "<< car.getTransmissionType() << '\n';
	outputFile << "Number of Gears: "<< car.getGears() << '\n';
	outputFile << "Number of Cylinders: "<< car.getCylinders() << '\n';
	outputFile << "Year of Manufacture: "<<car.getYear() << '\n';
	outputFile << "Number of Doors: " << car.getNumDoor() << '\n';
	outputFile << "17 Digit VIN Number: "<< car.getVinNumber() << '\n';
	outputFile << "Mileage: "<<car.getMileage() << '\n';
	outputFile << "Average MPG: "<<car.getMilesPerGallon() << '\n';
	if (car.checkElectric() == 1) {
		outputFile << "Electric\n";
	}
	else {
		outputFile << "Non-Electric\n";
	}
	outputFile << "Total Price of Amenities: $" << car.getPriceAmenities() << '\n';
	outputFile << "Inital Price of Vehicle: $" << car.getBaseCost() << '\n';
	//none for cost, will be calculated polymorphically via dynamic binding during runtime.
	return outputFile;
}

istream& operator>>(istream& input, Car& car) {
	char amenityIndex[10];
	string mod;
	string colr;
	string pltf;
	string transt;
	char grs[10];	//will make it so the program wont crash if the user enters a string or character. We either prompt another input or set a default value in bad input cases.
	char cyls[10];
	char yr[10];
	char nmdr[10];
	string vinnmbr;
	char mlg[10];
	char mpg[10];
	char iselec[10];
	char numAmens[10];
	double subTotalAmens=0; 
	char bp[10]; 
	input.ignore();
	cout << "Enter the car's model: ";
	getline(input,mod);
	//transform(mod.begin(), mod.end(), mod.begin(), ::tolower);
	while (!car.fp.CheckWord("cars.txt", mod)) {
		cout << "Please enter a valid car model: ";
		getline(input, mod);
		//transform(mod.begin(), mod.end(), mod.begin(), ::tolower);
	}
	//input.ignore();
	cout << "Enter the car's color: ";
	getline(input, colr);
	//transform(colr.begin(), colr.end(), colr.begin(), ::tolower);
	while (!car.fp.CheckWord("colors.txt", colr)) {
		cout << "Please enter a valid color: ";
		getline(input, colr);
		//transform(colr.begin(), colr.end(), colr.begin(), ::tolower);
	}
	cout << "Is the car AWD, RWD, or FWD: ";
	getline(input, pltf);
	while (!car.setPlatform(pltf)) {
		cout << "Try again. Is the car AWD, RWD, or FWD: ";
		getline(input, pltf);
	}
	cout << "Is the car Manual or Automatic? (enter either the word or A or M): ";
	getline(input, transt);
	while (!car.setTransmissionType(transt)) {
		cout << "Try again. Is the car Manual or Automatic? (enter either the word or A or M): ";
		getline(input, transt);
	}
	cout << "Enter the amount of gears the car has (5-10): ";
	input >> grs;
	while (!car.setGears(atoi(grs))) {
		cout << "Try again. Enter the amount of gears the car has (5-10): ";
		input >> grs;
	}
	cout << "Enter the amount of cylinders the car has (even number, 4-12): ";
	input >> cyls;
	while (!car.setCylinders(atoi(cyls))) {
		cout << "Try again. Enter the amount of cylinders the car has (even number, 4-12): ";
		input >> cyls;
	}
	cout << "Enter the year the car was manufactured (between 1980-2020): ";
	input >> yr;
	while (!car.setYear(atoi(yr))) {
		cout << "Try again. Enter the year the car was manufactured (between 1980-2020): ";
		input >> yr;
	}
	cout << "How many doors does the car have (2 or 4): ";
	input >> nmdr;
	while (!car.setNumDoor(atoi(nmdr))) {
		cout << "Try again. How many doors does the car have (2 or 4): ";
		input >> nmdr;
	}

	/*input.ignore();																			//COMMENTED OUT FOR EASIER TESTING. CAN UNCOMMENT IF YOU WISH PROFESSOR
	cout << "Enter the 17 digit vin number of the vehicle (MUST BE 17 DIGITS): ";
	getline(input, vinnmbr);
	while (!car.setVinNumber(vinnmbr)) {
		cout << "Try again. Enter the 17 digit vin number of the vehicle (MUST BE 17 DIGITS): ";
		getline(input, vinnmbr);
	}*/
	
	cout << "Enter the car mileage to calculate how it has depreciated (0-300000): ";
	input >> mlg;
	while (!car.setMileage(atoi(mlg))) {
		cout << "Try again. Enter the car mileage to calculate how it has depreciated (0-300000): ";
		input >> mlg;
	}
	cout << "Enter the MPG. Any values higher than 40 indicate the car is electric (10-40 for non electric, 41-200 electic): ";
	input >> mpg;
	while (!car.setMilesPerGallon(atoi(mpg))) {
		cout << "Try again. Enter the MPG. Any values higher than 40 indicate the car is electric (10-40 for non electric, 41-200 electic): ";
		input >> mpg;
	}
	cout << "Is the vehicle electric (0 for non-electric or 1 for electric) (automatically 1 if MPG>40): ";
	input >> iselec;
	while (!car.setElectric((bool)atoi(iselec))) {
		cout << "Try again. Is the vehicle electric (0 for non-electric or 1 for electric): ";
		input >> iselec;
	}
	car.amenities.printAmenitiesList();
	cout << "How many of the above amenities do you want: ";
	input >> numAmens;
	while (!car.amenities.setNumAmenities(atoi(numAmens))) {
		cout << "Try again. How many of the above amenities do you want: ";
		input >> numAmens;
	}
	cout << endl;
	for (int i = 0; i < atoi(numAmens); i++) {
		cout << "Enter amenity "<<i<<" (for instance, 0 for heated seats)" << ": ";
		input >> amenityIndex;
		while (!car.setAmenities(atoi(amenityIndex))) {
			cout << "Try again. Enter amenity (for instance, 0 for heated seats)" << i << ": ";
			input >> amenityIndex;
		}
		for (int x : car.amenities.getPreviousChoices()) { //check for the current choice in the previous amenities choices.
			while (x == atoi(amenityIndex)) {
				cout << "You have already picked this amenity. Try again: ";
				input >> amenityIndex;
				while (!car.setAmenities(atoi(amenityIndex))) {
					cout << "Try again. Enter amenity (for instance, 0 for heated seats)" << i << ": ";
					input >> amenityIndex;
				}
			}
		}
		car.amenities.addToPreviousChoices(atoi(amenityIndex));

		subTotalAmens += car.amenities.getPriceOfAmenity(atoi(amenityIndex));
	}
	cout << "What is the base asking price of the vehicle (5000 - 100000): ";
	input >> bp;
	while (!car.setBaseCost((double)atof(bp))) {
		cout << "Try again. What is the base price of the vehicle (5000 - 100000): ";
		input >> bp;
	}

	transform(mod.begin(), mod.end(), mod.begin(), ::tolower);
	car.setModel(mod);
	transform(colr.begin(), colr.end(), colr.begin(), ::tolower);
	car.setColor(colr);
	car.setPlatform(pltf);
	car.setTransmissionType(transt);
	car.setGears(atoi(grs));
	car.setCylinders(atoi(cyls));
	car.setYear(atoi(yr));
	car.setNumDoor(atoi(nmdr));
	car.setVinNumber(vinnmbr);
	car.setMileage(atoi(mlg));
	car.setMilesPerGallon(atoi(mpg));
	car.setElectric((bool)atoi(iselec));
	car.setAmenitiesPrice(subTotalAmens);
	car.setBaseCost((double)atof(bp));
	
	return input;
}