/* Assignment: 3
Author: Gleb Tcivie*/

#include "Kids.h"
#define LOWEST 10
#define HIGHEST 100
#define PRICEMOD 0.5

Kids::Kids(const int year, const int numPages, const char* name, const int minAge) :
	Book(year, numPages, name, Item::Type::BOOK) {
	this->mMinAge = minAge; // copy min age
	double sum = this->mNumPages * PRICEMOD; // calculate book price
	if (sum > LOWEST && sum < HIGHEST) // if the price in range
		this->mPrice = sum;
	else if (sum <= LOWEST) // if price is smaller than 10
		this->mPrice = LOWEST;
	else if (sum >= HIGHEST) // if price is bigger than 100
		this->mPrice = HIGHEST;
}

Kids* Kids::operator=(const Kids& other) {
	if (this != &other) { // cheks if the address not the same
		this->Book::operator=(other);	// copy the book parameters
		this->mMinAge = other.mMinAge;	// copy the minimum age
	}
	return this;
}

Kids::Kids(const Kids& other) :
	Book(other) {
	this->mMinAge = other.mMinAge; // copy min age
}

void Kids::print() const {
	cout << '<' << this->getID() << '>'		// print serial number
		<< " <" << this->getPrice() << '>'	// print the price
		<< " <Children Book>"		// print the type
		<< " <" << this->getName() << '>'		// print the name
		<< " <" << this->mNumPages << '>'	// print the number of pages
		<< " <" << this->getRelYear() << '>'	// print the release year
		<< " <" << this->mMinAge << '>' << endl;	// print the minimum reading age
}

ostream& operator<<(ostream& os, const Kids& item) {
	os << '<' << item.getID() << '>'		// print serial number
		<< ' <' << item.getPrice() << '>'	// print the price
		<< " <Children Book>"		// print the type
		<< ' <' << item.getName() << '>'		// print the name
		<< ' <' << item.mNumPages << '>'	// print the number of pages
		<< ' <' << item.getRelYear() << '>'	// print the release year
		<< ' <' << item.mMinAge << '>' << endl;	// print the minimum reading age
	return os;
}
