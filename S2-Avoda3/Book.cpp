/* Assignment: 3
Author: Gleb Tcivie*/

#include "Book.h"

Book::Book(const int year, const int numPages, const char* name, const Item::Type type) :
    Item(name, year, type) {
    this->mNumPages = numPages;
}

Book::Book() :
    Item() {
    this->mNumPages = 0;
}

Book::Book(const Book& other) :
    Item(other) {
    //this->Item::operator=(other); // copy item properties
    this->mNumPages = other.mNumPages; // copy number of pages
}

Book* Book::operator=(const Book& other) {
    if (this != &other) {               // check if the object is not the same
        this->Item::operator=(other);   // use manually operator = for item copy
        this->mNumPages = other.mNumPages; // copy number of pages
    }
    return this;
}
