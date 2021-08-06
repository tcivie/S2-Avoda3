/* Assignment: 3
Author: Gleb Tcivie*/

#include "Reading.h"
#define LOWEST 10
#define HIGHEST 100
#define PRICEMOD 2

Reading::Reading(const int year, const int numPages, const char* name, const char* genre) :
	Book(year, numPages, name, Item::Type::BOOK) {
	this->mGenre = new char[MAXSTRING];	// allocate mem
	this->mGenre = String::strCpy(this->mGenre, genre);	// copy the string by value
	int sum = this->mNumPages * PRICEMOD; // calculate book price
	if (sum > LOWEST && sum < HIGHEST) // if the price in range
		this->mPrice = sum;
	else if (sum <= LOWEST) // if price is smaller than 10
		this->mPrice = LOWEST;
	else if (sum >= HIGHEST) // if price is bigger than 100
		this->mPrice = HIGHEST;
}

Reading* Reading::operator=(const Reading& other) {
	if (this != &other) { // checks if the addresses are the same
		this->Book::operator=(other); // copies the book parameters
		this->mGenre = new char[MAXSTRING];	// allocate mem
		this->mGenre = String::strCpy(this->mGenre, other.mGenre); // copies the genre
	}
	return this;
}

Reading::Reading(const Reading& other) :
	Book(other) {
	this->mGenre = new char[MAXSTRING]; // allocate new memmory
	this->mGenre = String::strCpy(this->mGenre, other.mGenre); // copy the string
}

void Reading::print() const {
	cout << '<' << this->getID() << "> "		// print serial number
		<< '<' << this->getPrice() << "> "	// print the price
		<< "<Reading Book> "		// print the type
		<< '<' << this->getName() << "> "		// print the name
		<< '<' << this->mNumPages << "> "	// print the number of pages
		<< '<' << this->getRelYear() << "> "	// print the release year
		<< '<' << this->mGenre << '>' << endl;	// print the genre
}

ostream& operator<<(ostream& os, const Reading& item) {
	os << '<' << item.getID() << '>'		// print serial number
		<< ' <' << item.getPrice() << '>'	// print the price
		<< " <Reading Book>"		// print the type
		<< ' <' << item.getName() << '>'		// print the name
		<< ' <' << item.mNumPages << '>'	// print the number of pages
		<< ' <' << item.getRelYear() << '>'	// print the release year
		<< ' <' << item.mGenre << '>' << endl;	// print the genre
	return os;
}
