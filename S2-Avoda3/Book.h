/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "Item.h"
#include "String.h"
using namespace std;
class Book :
	public Item {
protected:
	//char* mName;
	int mNumPages;
public:
	/// <summary>
	/// ctor
	/// </summary>
	/// <param name="id">Items ID</param>
	/// <param name="year">Release year</param>
	/// <param name="numPages">Number of pages</param>
	/// <param name="name">Book name</param>
	Book(const int year, const int numPages,
		const char* name, const Item::Type type);

	/// <summary>
	/// default Ctor
	/// </summary>
	Book();

	/// <summary>
	/// Cctor
	/// </summary>
	/// <param name="other">Object to copy from</param>
	Book(const Book& other);

	// default dtor
	virtual ~Book() {};

	/// <summary>
	/// Overrides one book to another
	/// </summary>
	/// <param name="other">Book object to copy</param>
	/// <returns>Updated Book object</returns>
	Book* operator=(const Book& other);

	// Sets the price for the item
	void setPrice(const double price) { this->mPrice = price; };
};

