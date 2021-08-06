/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "Database.h"
class Manager {
private:
	/// <summary>
	/// Adds Children Book to the database
	/// </summary>
	/// <param name="pbuffer">Pointer to the begining of the name</param>
	Kids* addChildrenBook(char* pbuffer) const;
	/// <summary>
	/// Adds Reading Book to the database
	/// </summary>
	/// <param name="pbuffer">Pointer to the begining of the name</param>
	Reading* addReadingBook(char* pbuffer) const;
	/// <summary>
	/// Adds Movie to the database
	/// </summary>
	/// <param name="pbuffer">Pointer to the begining of the name</param>
	Movie* addMovie(char* pbuffer) const;
	/// <summary>
	/// Adds Music Album to the database
	/// </summary>
	/// <param name="pbuffer">Pointer to the begining of the name</param>
	Album* addMusicAlbum(char* pbuffer) const;

	Database* mDB;

public:
	/// <summary>
	/// Ctor
	/// </summary>
	/// <param name="db">Pointer to the database</param>
	Manager(Database* db) { this->mDB = db; };
	/// <summary>
	/// Creates user interface for adding item
	/// </summary>
	void addItem() const;
	/// <summary>
	/// Deletes the item by id
	/// </summary>
	void delItem() const;
	/// <summary>
	/// Prints an item by id
	/// </summary>
	void printItem() const;
	/// <summary>
	/// Prints all items by order
	/// </summary>
	void printAllItems() const;
};

