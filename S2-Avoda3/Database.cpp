/* Assignment: 3
Author: Gleb Tcivie*/

#include "Database.h"

Item** Database::mCatalog = nullptr;

int Database::mCatLen = 0;

void Database::increaseSize() {
	if (!this->mCatLen) {	// if database empty
		this->mCatalog = new Item*[1];	// allocate slot
		this->mCatLen++;	// increment size by one
	} else {	// if database has items in it
		Item** updatedDb = new Item * [this->mCatLen + 1]; // allocate more memmory for items
		for (int i = 0; i < this->mCatLen; i++) {
			updatedDb[i] = this->mCatalog[i]; // copy each item
			this->mCatalog[i] = nullptr; // point the old pointer to nullptr
			delete this->mCatalog[i]; // delete the old pointer
		}
		delete[] this->mCatalog; // delete the old catalog
		// ADD NEW ITEM TO CATALOG
		updatedDb[this->mCatLen] = nullptr; // point to null
		this->mCatalog = updatedDb; // store the pointer
		this->mCatLen++; // increase size by one

		updatedDb = nullptr; // point to null
		delete[] updatedDb; // delete the created database
	}
}

bool Database::checkExistance(const Item& item) {
	for (int i = 0; i < this->mCatLen; i++) { // go trough all items in database
		if (*this->mCatalog[i] == item)
			return true;
	}
	return false;
}

Database::Database() {
	//this->mCatLen = 0;
	//this->mCatalog = nullptr;
}

Database::~Database() {
	for (int i = 0; i < this->mCatLen; i++) {
		delete this->mCatalog[i]; // delete each item
	}
	delete this->mCatalog; // delete the pointer
}

Database* Database::operator+=(const Movie& item) {
	if (!this->checkExistance(item)) { // checks if the item exists
		this->increaseSize(); // increases size of the database by one
		this->mCatalog[this->mCatLen - 1] = new Movie(item); // add new item to the end
	} else
		cout << "Error: Item already exists in the system." << endl;
	return this;
}

Database* Database::operator+=(const Album& item) {
	if (!this->checkExistance(item)) {
		this->increaseSize(); // increases size of the database by one
		this->mCatalog[this->mCatLen - 1] = new Album(item); // add new Album to the end
	} else
		cout << "Error: Item already exists in the system." << endl;
	return this;
}

Database* Database::operator+=(const Kids& item) {
	if (!this->checkExistance(item)) {
		this->increaseSize(); // increases size of the database by one
		this->mCatalog[this->mCatLen - 1] = new Kids(item); // add new kids book to the end
	} else
		cout << "Error: Item already exists in the system." << endl;
	return this;
}

Database* Database::operator+=(const Reading& item) {
	if (!this->checkExistance(item)) {
		this->increaseSize(); // increases size of the database by one
		this->mCatalog[this->mCatLen - 1] = new Reading(item); // add new reading book to the end
	} else
		cout << "Error: Item already exists in the system." << endl;
	return this;
}

Database* Database::operator-=(const int id) {
	Item** backup = new Item*[this->mCatLen];	// create backup database
	Item** pbackup = backup;	// pointer to backup
	int backupLen = this->mCatLen;	// copy the database length
	for (int i = 0; i < this->mCatLen; i++) {
		if (this->mCatalog[i]->getID() != id) { // check if that's not the id were looking for
			*(pbackup++) = this->mCatalog[i]; // copy the pointer
			this->mCatalog[i] = nullptr; // point to null
			delete this->mCatalog[i]; // delete the pointer
		}
		else {
			delete this->mCatalog[i]; // delete the found pointer
			backupLen--; // decrease the seize
			BasketDB::delFromAllBaskets(id);	// delete from all baskets
		}
	}
	this->mCatalog = backup;	// copy back the pointer
	if (this->mCatLen == backupLen)	// no item found
		cout << "Error: Item with corresponding serial does not exist." << endl;
	this->mCatLen = backupLen;	// copy the length
	return this;
}

void Database::printById(const int id) {
	for (int i = 0; i < Database::mCatLen; i++) { // go trough all the list
		if (Database::mCatalog[i]->getID() == id) {// find the item
			Database::mCatalog[i]->print(); // print the item
			return; // stop looking 
		}
	}
	cout << "Error: Item with corresponding serial does not exist." << endl;	// if not found
}

bool Database::checkIfItemExists(int itemID) {
	for (int i = 0; i < Database::mCatLen; i++) {	// go trough all the list
		if (Database::mCatalog[i]->getID() == itemID) {	// find the item
			return true;	// stop looking and return true
		}
	}
	return false;	// item not found
}

bool Database::checkIfItemExists() {
	return Database::mCatLen;
}

ostream& operator<<(ostream& os, const Database& item) {
	for (int i = 0; i < item.mCatLen; i++) { //print all the items in the store
		item.mCatalog[i]->print(); // print each item
	}
	return os; // return the os object
}
