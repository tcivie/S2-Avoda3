/* Assignment: 3
Author: Gleb Tcivie*/

#include "Manager.h"

Kids* Manager::addChildrenBook(char* pbuffer) const {
	char* name = new char[MAXSTRING];
	int pages = 0;
	int year = 0;
	int minimumAge = 0;
	char* pname = name; // pointer to start name

	do { // GET NAME
		*(pname++) = *pbuffer; // copy the name
	} while (*(++pbuffer) != '>'); // run till the end of the part
	*(pname) = '\0';	// add null character
	pbuffer += 3; // go to the next segment

	do { // GET PAGES
		pages *= 10; // move the digits upwards (digits to thens etc...)
		pages += *pbuffer - 48; // extract the digit from the string
	} while (*(++pbuffer) != '>'); // run till the end of the part
	pbuffer += 3; // go to the next segment

	do { // GET YEAR
		year *= 10; // move the digits upwards (digits to thens etc...)
		year += *pbuffer - 48; // extract the digit from the string
	} while (*(++pbuffer) != '>'); // run till the end of the part
	pbuffer += 3; // go to the next segment

	do { // GET MIN AGE
		minimumAge *= 10; // move the digits upwards (digits to thens etc...)
		minimumAge += *pbuffer - 48; // extract the digit from the string
	} while (*(++pbuffer) != '>'); // run till the end of the part

	return new Kids(year, pages, name, minimumAge); // allocate new mem and return item
}

Reading* Manager::addReadingBook(char* pbuffer) const {
	char* name = new char[MAXSTRING];
	int pages = 0;
	int year = 0;
	char* genre = new char[MAXSTRING];
	char* pname = name; // pointer to start name
	char* pgenre = genre; // pointer to start genre

	do { // GET NAME
		*(pname++) = *pbuffer; // copy the name
	} while (*(++pbuffer) != '>'); // run till the end of the part
	*(pname) = '\0';	// add null character
	pbuffer += 3; // go to the next segment

	do { // GET PAGES
		pages *= 10; // move the digits upwards (digits to thens etc...)
		pages += *pbuffer - 48; // extract the digit from the string
	} while (*(++pbuffer) != '>'); // run till the end of the part
	pbuffer += 3; // go to the next segment

	do { // GET YEAR
		year *= 10; // move the digits upwards (digits to thens etc...)
		year += *pbuffer - 48; // extract the digit from the string
	} while (*(++pbuffer) != '>'); // run till the end of the part
	pbuffer += 3; // go to the next segment

	do { // GET Genre
		*(pgenre++) = *pbuffer; // copy the genre
	} while (*(++pbuffer) != '>'); // run till the end of the part
	*(pgenre) = '\0';	// add null

	return new Reading(year, pages, name, genre); // allocate new mem and return item
}

Movie* Manager::addMovie(char* pbuffer) const {
	char* type = new char[MAXSTRING];
	char* name = new char[MAXSTRING];
	int year = 0;
	int rating = 0;

	do { // GET TYPE
		*type = *pbuffer; // copy the type
	} while (*(++pbuffer) != '>'); // run till the end of the part
	pbuffer += 3; // go to the next segment

	do { // GET NAME
		*name = *pbuffer; // copy the name
	} while (*(++pbuffer) != '>'); // run till the end of the part
	pbuffer += 3; // go to the next segment

	do { // GET YEAR
		year *= 10; // move the digits upwards (digits to thens etc...)
		year += *pbuffer - 48; // extract the digit from the string
	} while (*(++pbuffer) != '>'); // run till the end of the part
	pbuffer += 3; // go to the next segment

	do { // GET RATING
		rating = *pbuffer - 48; // copy the rating
	} while (*(++pbuffer) != '>'); // run till the end of the part
	
	return new Movie(year,name,type,rating); // allocate new mem and return item
}

Album* Manager::addMusicAlbum(char* pbuffer) const {
	char* nameAlbum = new char[MAXSTRING];
	char* exBuffer = new char[MAXSTRING];
	int relYear = 0;
	char* pname = nameAlbum;	// pointer to name

	do { // GET NAME
		*(pname++) = *pbuffer;	// copy the name
	} while (*(++pbuffer) != '>');	// run till the end of the part
	*(pname) = '\0';	// add null
	pbuffer += 3;	// go to the next segment

	do { // GET YEAR
		relYear *= 10;	// move the digits upwards (digits to thens etc...)
		relYear += *pbuffer - 48;	// extract the digit from the string
	} while (*(++pbuffer) != '>');	// run till the end of the part

	Album* newAlb = new Album(relYear, nameAlbum);	// create new album
	// EXTRACT SONGS
	cin.getline(exBuffer, MAXSTRING);	// get additional line
	while (String::countStrlen(exBuffer) > 1) {	// count till the line not empty
		char* nameSong = new char[MAXSTRING];	// allocate mem for song name
		char* pnameS = nameSong;	// pointer to song name
		int songLen = 0;	// store song length
		while (*(++exBuffer) != '>');	// skip the first <Song> part
		exBuffer += 3;	// go to the next segment

		do { // GET NAME
			*(pnameS++) = *exBuffer;	// copy the name
		} while (*(++exBuffer) != '>');	// run till the end of the part
		*(pnameS) = '\0';	// null character
		exBuffer += 3;	// go to the next segment

		do { // GET SECONDS
			songLen *= 10;	// move the digits upwards (digits to thens etc...)
			songLen += *exBuffer - 48;	// extract the digit from the string
		} while (*(++exBuffer) != '>');	// run till the end of the part
		
		newAlb->addSong(nameSong,songLen);	// add song to the album
		cin.getline(exBuffer, MAXSTRING);	// get additional line
	}
	return newAlb;
}

void Manager::addItem() const {
	char* buffer = new char[MAXSTRING]; // buffer to store the text
	char* pbuffer = buffer; // pointer to begining of buffer
	char* type = new char[MAXSTRING];
	char* ptype = type; // pointer to begining of type
	//Database db; // create pointer to the database

	getchar(); // remove useless backspace
	cin.getline(buffer, MAXSTRING); // read whole line
	//buffer++; // skip the first <
	while (*(++buffer) != '>') { // GET THE TYPE + skip the first '<'
		*(type++) = *buffer; // copy the type + increment the pointer in type
	}
	*(type++) = '\0'; // add null
	buffer += 3; // jump to name (_<x)
	if (String::strCmp(ptype, "Children Book"))
		*this->mDB += *addChildrenBook(buffer); // adds the book to the databse
	else if (String::strCmp(ptype, "Reading Book"))
		*this->mDB += *addReadingBook(buffer); // add the book to the database
	else if (String::strCmp(ptype, "Movie"))
		*this->mDB += *addMovie(buffer); // add the movie to the database
	else if (String::strCmp(ptype, "Music Album"))
		*this->mDB += *addMusicAlbum(buffer); // add the music album to database
}

void Manager::delItem() const {
	int id = 0;
	cin >> id; // get the ID
	*this->mDB -= id; // remove the database
}

void Manager::printItem() const {
	int id;
	cin >> id;
	this->mDB->printById(id); // print by id
}

void Manager::printAllItems() const {
	cout << *this->mDB; // use method in database
}
