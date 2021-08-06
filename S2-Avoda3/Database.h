/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "Item.h"
#include "Album.h"
#include "Kids.h"
#include "Reading.h"
#include "Movie.h"
#include "BasketDB.h"

#define MAXSTRING 255
class Database {
private:
	static Item** mCatalog; // store catalouge
	static int mCatLen; // number of items in the store

	/// <summary>
	/// Increases size of the database by one and puts pointer to null at the end
	/// </summary>
	void increaseSize();
	/// <summary>
	/// Cheks if the item exists in the system
	/// </summary>
	/// <param name="item">Item to loo for in the system</param>
	/// <returns>True if item found, False otherwise</returns>
	bool checkExistance(const Item& item);
	
public:
	/// <summary>
	/// Default dtor
	/// </summary>
	Database();

	/// Default dtor
	~Database();

	/// <summary>
	/// Adds movie to the database
	/// </summary>
	/// <param name="item">The movie to add</param>
	Database* operator+=(const Movie& item);
	/// <summary>
	/// Adds album to the database
	/// </summary>
	/// <param name="item">The album to add</param>
	Database* operator+=(const Album& item);
	/// <summary>
	/// Adds kids book to the database
	/// </summary>
	/// <param name="item">The book to add</param>
	Database* operator+=(const Kids& item);
	/// <summary>
	/// Adds reading book to the database
	/// </summary>
	/// <param name="item">The book to add</param>
	Database* operator+=(const Reading& item);
	/// <summary>
	/// Removes item from the database by id
	/// </summary>
	/// <param name="id">The id if the item to remove</param>
	Database* operator-=(const int id);
	/// <summary>
	/// print all items in the store
	/// </summary>
	/// <param name="os">Outstream object to store</param>
	/// <param name="item">Database to print</param>
	/// <returns>Outstream object with all the items in the store</returns>
	friend ostream& operator << (ostream& os, const Database& item);
	/// <summary>
	/// Prints the item by id
	/// </summary>
	/// <param name="id">Items serial number</param>
	static void printById(const int id);
	/// <summary>
	/// Returns the list of the database
	/// </summary>
	/// <returns>Database pointer</returns>
	static Item** getList() { return Database::mCatalog; };
	/// <summary>
	/// Checks if the item with the corespoinding id exists in the system
	/// </summary>
	/// <param name="itemID">Item ID</param>
	/// <returns>True if item found , Flase otherwise</returns>
	static bool checkIfItemExists(int itemID);
	/// <summary>
	/// Cheks if there are any items in the database
	/// </summary>
	/// <returns></returns>
	static bool checkIfItemExists();

};

