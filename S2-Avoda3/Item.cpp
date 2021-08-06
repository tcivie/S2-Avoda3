/* Assignment: 3
Author: Gleb Tcivie*/

#include "Item.h"

int Item::mID = 1;

Item::Item() :
    mCurID(mID++) , mType() , mName(){
    this->mRelYear = 1900;
    this->mPrice = 0;
}

Item::Item(const char* name, const int year, const Type type) :
    mCurID(mID++), mType(type) {
    this->mName = new char[MAXSTRING];  // allocate mem for name
    this->mName = String::strCpy(this->mName, name);    // copy name
    this->mRelYear = year;  // set year
    this->mPrice = 0;       // set price to default 0
}

Item::Item(const Item& other) :
    mCurID(other.mID) , mType(other.mType) {
    this->mName = new char[MAXSTRING];  // allocate mem for name
    this->mName = String::strCpy(this->mName, other.mName);    // copy name
    this->mPrice = other.mPrice;    // copy price
    this->mRelYear = other.mRelYear;// copy release year
}

Item* Item::operator=(const Item& other) {
    if (this != &other) { // check if not the same
        this->mName = new char[MAXSTRING];  // alocate mem
        this->mName = String::strCpy(this->mName, other.mName);    // copy name
        this->mRelYear = other.mRelYear;    // copy release year
        this->mPrice = other.mPrice;        // copy price
    }
    return this;
}

void Item::print() const {
    cout << '<' << this->getID() << "> " <<        // print id
        '<' << this->getPrice() << "> ";    // print price
    switch (this->mType) {
        case Item::Type::ALBUM:
        cout << "<Album> ";
        break;
        case Item::Type::BOOK:
        cout << "<Book> ";
        break;
        case Item::Type::MOVIE:
        cout << "<Movie> ";
        break;
    }
    cout << '<' << this->getRelYear() << '>' << endl;    // print release year
}

bool Item::operator==(const Item& other) const{
    if (this->mType == other.mType &&   // chekcs same type
        this->mRelYear == other.mRelYear && // checks same release year
        String::strCmp(this->getName(), other.getName())) // checks same name
        return true;
    return false; // not identical
}

Item::~Item() {};

ostream& operator<<(ostream& os, const Item& str) {
    os << '<' << str.getID() << "> " <<        // print id
        '<' << str.getPrice() << "> ";    // print price
    switch (str.mType) {
        case Item::Type::ALBUM :
        os << "<Album> ";
        break;
        case Item::Type::BOOK :
        os << "<Book> ";
        break;
        case Item::Type::MOVIE :
        os << "<Movie> ";
        break;
    }
    os << '<' << str.getRelYear() << '>' << endl;    // print release year
    return os;
}
