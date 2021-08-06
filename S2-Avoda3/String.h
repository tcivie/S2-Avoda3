/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include <iostream>
#include <istream>
#define MAXSTRING 255

using namespace std;
class String {
private:
	char* mString;

	// PRIVATE METHODS
	
public:
	// CTOR CCTOR AND DTOR
	/// <summary>
	/// Default Ctor - intializes empty Characters to nul pointer
	/// </summary>
	String();
	/// <summary>
	/// Csutom Ctor - builds Characters with the given pointer to array of characters
	/// </summary>
	/// <param name="data">Pointer to array of characters</param>
	String(const char* data);
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="data">String to copy from</param>
	String(const String& data);
	/// <summary>
	/// Default destructor
	/// </summary>
	~String();

	// GET AND SET METHODS
	/// <summary>
	/// Returns the Characters as constant
	/// the first const disables the option to modify the inner values of the Characters
	/// the second one disables canging of the pointer itself
	/// the last one is for letting know that the function dosent change anything
	/// </summary>
	/// <returns>constant array of constant characters (The Characters)</returns>
	inline const char* const getString() const { return this->mString; };
	/// <summary>
	/// Returns the length of the Characters without the null character
	/// </summary>
	/// <returns>Number of characters in the Characters wihtout the null character</returns>
	inline int getStrlen() const;
	/// <summary>
	/// Removes the old Characters and sets the Characters to a new given one
	/// </summary>
	/// <param name="data">Array of characters to set the Characters to</param>
	void setString(const char* data);

	// METHODS
	/// <summary>
	/// Prints the Characters to the screen
	/// </summary>
	void print() const;
	/// <summary>
	/// Cheks if the two given strings are the same
	/// </summary>
	/// <param name="string1">The first string</param>
	/// <param name="string2">The second string</param>
	/// <returns>True if equal , Flase otherwise</returns>
	static bool strCmp(const char* string1, const char* string2);
	/// <summary>
	/// Copies one string to another
	/// </summary>
	/// <param name="string1">String to copy to</param>
	/// <param name="string2">String to copy from</param>
	/// <returns>Pointer to the begining of the copied to string</returns>
	static char* strCpy(char* string1, const char* string2);
	/// <summary>
	/// Concating two strings together
	/// </summary>
	/// <param name="str1">The string to concat to</param>
	/// <param name="str2">The string to concat from</param>
	/// <returns>Pointer to the start of the concated string</returns>
	static char* concatFy(char* str1, const char* str2);
	/// <summary>
	/// Count the length of the Characters and return its number (null character not counted)
	/// </summary>
	/// <param name="Characters">Pointer to Characters</param>
	/// <returns>Number of characters in Characters (Null character not included)</returns>
	static int countStrlen(const char* string);


	// OPERATORS
	/// <summary>
	/// = Operator
	/// </summary>
	/// <param name="other">The other string</param>
	/// <returns>Applies the string from Roperator to the lOperator</returns>
	String operator = (const String& other);
	/// <summary>
	/// Cheks if the strings are equal
	/// </summary>
	/// <param name="other">Rvalue string</param>
	/// <returns>True if the Lvalue and the Rvalue are equal , False otherwise</returns>
	bool operator == (const String& other);
	/// <summary>
	/// Cout helper
	/// </summary>
	/// <param name="os">Ostream object</param>
	/// <param name="str">String to print</param>
	/// <returns>Ostream object</returns>
	friend ostream& operator << (ostream& os, const String& str);
	/// <summary>
	/// Cin helper
	/// </summary>
	/// <param name="is">Input object</param>
	/// <param name="str">String to store the value in</param>
	/// <returns></returns>
	friend istream& operator >> (istream& is, String& str);
};

