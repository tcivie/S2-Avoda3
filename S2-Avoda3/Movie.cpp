/* Assignment: 3
Author: Gleb Tcivie*/

#include "Movie.h"
#define MOVIEPRICE 20

Movie::Movie(const int year, const char* name, const Type& type, const int rate) :
	Item(name,year, Item::Type::MOVIE) {
	this->mRate = rate; // copy the rating
	this->mType = type; // copy the type
	this->mPrice = MOVIEPRICE; // default price
}
Movie::Movie(const int year, const char* name, const char* type, const int rate) :
	Item(name, year, Item::Type::MOVIE) {
	this->mRate = rate; // copy the rating
	if (rate < 1)
		this->mRate = 1; // set lowest rating
	if (String::strCmp(type, "Sci-Fi")) {
		this->mType = Type::SCIFI; // init type
		if (rate > 9)
			this->mRate = 9; // set max rating
	}
	else if (String::strCmp(type, "Action")) {
		this->mType = Type::ACTION; // init type
		if (rate > 5)
			this->mRate = 5; // set max rating
	}
	else {
		this->mType = Type::THRILLER; // default to
		if (rate > 6)
			this->mRate = 6; //set max rating
	}
	this->mPrice = MOVIEPRICE; // default price
}
Movie* Movie::operator=(const Movie& other) {
	if (this != &other) { // checks if the addresses are the same
		this->Item::operator=(other); // copy the item values
		this->mRate = other.mRate; // copy the movie rate
		this->mType = other.mType; // copy the movie type
	}
	return this;
}
Movie::Movie(const Movie& other) :
	Item(other) {
	this->mRate = other.mRate; // copy the rating
	this->mType = other.mType; // copy the type
}

void Movie::print() const {
	cout << '<' << this->getID() << '>' // print serial number
		<< ' <' << this->getPrice() << '>'; // print price
	switch (this->mType) { // print type
		case Movie::Type::ACTION:
		cout << " <Action Movie>";
		break;
		case Movie::Type::SCIFI:
		cout << " <Sci-Fi Movie>";
		break;
		case Movie::Type::THRILLER:
		cout << " <Thriller Movie>";
		break;
	}
	cout << ' <' << this->getName() << '>' // print movie name
		<< ' <' << this->getRelYear() << '>' // print release year
		<< ' <' << this->mRate << '>' << endl; // print rating
}

void Movie::setPrice(const double price) {
	this->mPrice = price;
}

bool Movie::chekSimilar(const Movie& item) const {
	if (this->getPrice() == item.getPrice() && // cheks matching price
		this->getRelYear() == item.getRelYear() && // check matching release year
		this->getName() == item.getName() && // check mathcing name
		this->mRate == item.mRate && // check matching rate
		this->mType == item.mType) // check matching type
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Movie& item) {
	os << '<' << item.getID() << '>' // print serial number
		<< ' <' << item.getPrice() << '>'; // print price
	switch (item.mType) { // print type
		case Movie::Type::ACTION:
		cout << " <Action Movie>";
		break;
		case Movie::Type::SCIFI:
		cout << " <Sci-Fi Movie>";
		break;
		case Movie::Type::THRILLER:
		cout << " <Thriller Movie>";
		break;
	}
	os << ' <' << item.getName() << '>' // print movie name
		<< ' <' << item.getRelYear() << '>' // print release year
		<< ' <' << item.mRate << '>' << endl; // print rating
	return os;
}
