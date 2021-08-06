/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "Book.h"
class Reading :
    public Book {
private:
    char* mGenre;
public:
    /// <summary>
    /// Default Ctor Reading book
    /// </summary>
    /// <param name="id">ID</param>
    /// <param name="year">Release year</param>
    /// <param name="numPages">Number of pages</param>
    /// <param name="name">Book's name</param>
    /// <param name="genre">Book's genre</param>
    Reading(const int year, const int numPages,
        const char* name, const char* genre);
    /// <summary>
    /// Overrides the reading book from other reading book
    /// </summary>
    /// <param name="other">Book to override from</param>
    /// <returns>Overriden book</returns>
    Reading* operator=(const Reading& other);

    /// <summary>
    /// Cctor
    /// </summary>
    /// <param name="other">Object to copy from</param>
    Reading(const Reading& other);
    /// <summary>
    /// Prints the reading book information
    /// </summary>
    void print() const;

    /// <summary>
    /// Os operator reading book
    /// </summary>
    /// <param name="os">os operator</param>
    /// <param name="str">The item to print</param>
    /// <returns>Modified os stream</returns>
    friend ostream& operator << (ostream& os, const Reading& item);

    // default dtor
    ~Reading() {};
};

