/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "Item.h"
#include "String.h"
class Movie :
    public Item {
private:
    enum class Type {SCIFI, THRILLER, ACTION};
    
    //char* mName;
    int mRate;
    Type mType;
public:
    // ctor
    Movie(const int year, const char* name, const Type& type, const int rate);
    Movie(const int year, const char* name, const char* type, const int rate);
    
    /// <summary>
    /// Overrides the movie with the other movie
    /// </summary>
    /// <param name="other">the movie to override from</param>
    /// <returns>the overriden movie object</returns>
    Movie* operator=(const Movie& other);

    /// <summary>
    /// Cctor
    /// </summary>
    /// <param name="other">Object to copy from</param>
    Movie(const Movie& other);
    
    /// <summary>
    /// Os operator movie
    /// </summary>
    /// <param name="os">os operator</param>
    /// <param name="str">The item to print</param>
    /// <returns>Modified os stream</returns>
    friend ostream& operator << (ostream& os, const Movie& item);
    
    /// <summary>
    /// Prints the Movie
    /// </summary>
    virtual void print() const;

    /// <summary>
    /// Sets new price for product
    /// </summary>
    /// <param name="price">Price to update</param>
    void setPrice(const double price);
    /// <summary>
    /// Cheks if the given movie is the same as the existing one
    /// </summary>
    /// <param name="item">The item to chek</param>
    /// <returns>True if the same, False otherwise</returns>
    bool chekSimilar(const Movie& item) const;

    // default dtor
    ~Movie() {};
};

