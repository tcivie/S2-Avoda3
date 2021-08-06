/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "Item.h"
#define MAXSTRING 255
#define SONGPRICE 5
class Album :
	public Item{
public:
	class Song {
	public:
		/// <summary>
		/// Song ctor
		/// </summary>
		/// <param name="name">Name of the song</param>
	/// <param name="length">Length of the song in seconds</param>
		Song(const char* name, const int length);

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="other">Song to copy from</param>
		Song(const Song& other);

		/// <summary>
		/// Appends the object to another
		/// </summary>
		/// <param name="other">The object to append from </param>
		/// <returns>The object to append to</returns>
		Song* operator=(const Song& other);

		/// <summary>
		/// Returns the songs name
		/// </summary>
		/// <returns>Song name</returns>
		char* getName() { return this->mSongName; };

		/// <summary>
		/// Returns the songs length in seconds
		/// </summary>
		/// <returns>Song length in seconds</returns>
		int getLength() { return this->mLength; };

		/// default dtor
		~Song();
	private:
		char* mSongName;
		int mLength;
	};

	/// <summary>
	/// Default Ctor
	/// </summary>
	/// <param name="id">ID</param>
	/// <param name="year">Album's release year</param>
	/// <param name="name">Album's name</param>
	Album(const int year, const char* name);

	/// <summary>
	/// Cctor
	/// </summary>
	/// <param name="other">Album to copy from</param>
	Album(const Album& other);

	/// <summary>
	/// Copies one album to another
	/// </summary>
	/// <param name="other">The playlist to copy from</param>
	/// <returns>Copied playlist</returns>
	Album* operator=(const Album& other);
	/// <summary>
	/// Adds song to the Album
	/// </summary>
	/// <param name="other">Song to add to the playlist</param>
	/// <returns>Modified Album</returns>
	Album* operator+=(const Song& other);

	// default dtor
	~Album();
	/// <summary>
	/// Os operator album
	/// </summary>
	/// <param name="os">os operator</param>
	/// <param name="str">The item to print</param>
	/// <returns>Modified os stream</returns>
	friend ostream& operator << (ostream& os, const Album& str);
	/// <summary>
	/// Prints the Album
	/// </summary>
	virtual void print() const;
	/// <summary>
	/// Sets new price for album
	/// </summary>
	/// <param name="price">The price</param>
	void setPrice(const double price);
	/// <summary>
	/// creates song
	/// </summary>
	/// <param name="name">song name</param>
	/// <param name="length">song length</param>
	/// <returns>song object</returns>
	void addSong(const char* name, const int length);
private:

	//char* mAlbumName;
	int mNumSongs;
	Song** mPlayList;
	/// <summary>
	/// Increases size of the Album by one
	/// </summary>
	void increaseSize();
};

