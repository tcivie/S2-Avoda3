/* Assignment: 3
Author: Gleb Tcivie*/

#include "Album.h"

Album::Album(const int year, const char* name) : 
	Item(name,year,Item::Type::ALBUM) {
	this->mPlayList = nullptr;
	this->mNumSongs = 0;
}

Album::Album(const Album& other) :
	Item(other) {
	this->mPlayList = new Song * [other.mNumSongs]; // allocate mem for playlist
	for (int i = 0; i < other.mNumSongs; i++) { // copy each song
		this->mPlayList[i] = new Song(*other.mPlayList[i]);
	}
	this->mNumSongs = other.mNumSongs; // copy number of songs in playlist
}

Album* Album::operator=(const Album& other) {
	if (this != &other) { // cheks if the object is not the same
		for (int i = 0; i < this->mNumSongs; i++) { // clear playlist
			delete this->mPlayList[i]; // delete song from list
		}
		delete this->mPlayList; // deallocate the old playlist
		this->mNumSongs = other.mNumSongs; // copies the number of songs in the album
		this->mPlayList = new Song * [this->mNumSongs]; // allocate new size for the songs
		for (int i = 0; i < this->mNumSongs; i++) { // copy all the songs
			this->mPlayList[i] = new Song(*other.mPlayList[i]); // copy the song
		}
	}
	return this;
}

Album* Album::operator+=(const Song& other) {
	increaseSize(); // add one slot for song in playlist
	this->mPlayList[this->mNumSongs] = new Song(other);	// add song to database
	this->mPrice = this->mNumSongs * SONGPRICE;	// add price
	return this;	// return modified album
}

Album::~Album() {
	for (int i = 0; i < this->mNumSongs; i++) {
		delete this->mPlayList[i]; // delete each song
	}
	delete this->mPlayList; // delete the playlist
}

void Album::print() const {
	cout << '<' << this->getID() << '>'		// print serial number
		<< " <" << this->getPrice() << '>'	// print price
		<< " <" << "Music Album" << '>'		// print type
		<< " <" << this->getName() << '>'	// print album name
		<< " <" << this->getRelYear() << '>' << endl; // print release year
	for (int i = 0; i < this->mNumSongs; i++) { // list all the songs in the playlist
		cout << "\t<song> <" << this->mPlayList[i]->getName() << '>' // prints the song name
			<< " <" << this->mPlayList[i]->getLength() << '>' << endl; // prints the songs length in secods
	}
}

void Album::setPrice(const double price) {
	this->mPrice = price;
}

void Album::increaseSize() {
	if (!this->mNumSongs) {	// if list empty
		this->mPlayList = new Song * [1];	// allocate slot
		this->mNumSongs++;	// increase number of songs
	} else {
		Song** tempPlaylist = new Song * [this->mNumSongs + 1]; // allocate bigger playlist
		for (int i = 0; i < this->mNumSongs; i++) { // copy all songs
			tempPlaylist[i] = this->mPlayList[i]; // point to each value
			this->mPlayList[i] = nullptr; // point to null
			delete this->mPlayList[i]; // delete the pointer
		}
		delete this->mPlayList; // delete old playlist
		// ADD NEW ITEM TO PLAYLIST
		tempPlaylist[this->mNumSongs] = nullptr; // point the last pointer to null
		this->mPlayList = tempPlaylist; // return the pointer to the playlist
		this->mNumSongs++; // increase number of songs
		tempPlaylist = nullptr; // point to null before delete
		delete[] tempPlaylist; // delete allocated mem
	}
}

void Album::addSong(const char* name, const int length) {
	increaseSize(); // add one slot for song in playlist
	this->mPlayList[this->mNumSongs - 1] = new Song(name, length);	// adds the song to the database
	this->mPrice = this->mNumSongs * SONGPRICE;	// add price
}

Album::Song::Song(const char* name, const int length) {
	this->mSongName = new char[MAXSTRING];	// allocate mem
	this->mSongName = String::strCpy(this->mSongName, name); // sets the songs name
	this->mLength = length; // sets the song length
}

Album::Song::Song(const Song& other) {
	this->mSongName = new char[MAXSTRING];	// alocate meme
	this->mSongName = String::strCpy(this->mSongName, other.mSongName); // copy the song name
	this->mLength = other.mLength; // copy the song length
}

Album::Song* Album::Song::operator=(const Song& other) {
	if (this != &other) { // check if the address is not the same
		this->mLength = other.mLength; // copy the song length
		this->mSongName = String::strCpy(this->mSongName, other.mSongName); // copy the song name 
	}
	return this;
}

Album::Song::~Song() {
	delete this->mSongName; // delete the songName
}

ostream& operator<<(ostream& os, const Album& str) {
	os << '<' << str.getID() << '>'		// print serial number
		<< " <" << str.getPrice() << '>'	// print price
		<< " <" << "Music Album" << '>'		// print type
		<< " <" << str.getName() << '>'	// print album name
		<< " <" << str.getRelYear() << '>' << endl; // print release year
	for (int i = 0; i < str.mNumSongs; i++) { // list all the songs in the playlist
		os << "\t<song> <" << str.mPlayList[i]->getName() << '>' // prints the song name
			<< " <" << str.mPlayList[i]->getLength() << '>' << endl; // prints the songs length in secods
	}
	return os;
}
