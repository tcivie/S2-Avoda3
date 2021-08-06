/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "Book.h"
class Kids :
    public Book {
private:
    int mMinAge;
public:
    /// <summary>
    /// Default Ctor Kids book
    /// </summary>
    /// <param name="id">ID</param>
    /// <param name="year">Release year</param>
    /// <param name="numPages">Number of pages</param>
    /// <param name="name">Book name</param>
    /// <param name="minAge">Book's minimum age</param>
    Kids(const int year, const int numPages,
        const char* name, const int minAge);
    /// <summary>
    /// Overrides the original kids book with the new one
    /// </summary>
    /// <param name="other">The new book to override from</param>
    /// <returns>The overriden book</returns>
    Kids* operator=(const Kids& other);

    /// <summary>
    /// Cctor
    /// </summary>
    /// <param name="other">Object to copy form</param>
    Kids(const Kids& other);
    
    /// <summary>
    /// Os operator kids book
    /// </summary>
    /// <param name="os">os operator</param>
    /// <param name="str">The item to print</param>
    /// <returns>Modified os stream</returns>
    friend ostream& operator << (ostream& os, const Kids& item);
    /// <summary>
    /// Prints the Book
    /// </summary>
    virtual void print() const;

    // default dtor
    ~Kids() {};
};

