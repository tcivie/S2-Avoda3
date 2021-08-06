/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "String.h"
class Item {
protected:
	const enum class Type {BOOK, ALBUM, MOVIE};
	double mPrice;
private:
	static int mID;
	const int mCurID;
	int mRelYear;
	const Type mType;
	char* mName;
public:
	// default ctor
	Item();

	// ctor
	Item(const char* name, const int year, const Type type);
	
	// Default dtor
	virtual ~Item() = 0;

	// Default cctor
	Item(const Item& other);

	// = operator
	virtual Item* operator = (const Item& other);

	// Returns the ID
	virtual inline int getID() const { return this->mCurID; };

	// Returns the Items Price
	virtual inline double getPrice() const { return this->mPrice; };

	// Sets the price for the item
	virtual void setPrice(const double price) = 0;
	
	// returns the Release Year
	virtual inline int getRelYear() const { return this->mRelYear; };

	// gets type of product
	virtual inline const Type getType() const { return this->mType; };

	// gets the name
	virtual inline const char* getName() const { return this->mName; };

	// print item
	friend ostream& operator << (ostream& os, const Item& str);

	/// <summary>
	/// Prints the item
	/// </summary>
	virtual void print() const;

	// checks if the same
	virtual bool operator==(const Item& other) const;

};

//int Item::mID = 1;



