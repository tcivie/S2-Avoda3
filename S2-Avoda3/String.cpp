/* Assignment: 3
Author: Gleb Tcivie*/

#include "String.h"

int String::countStrlen(const char* string){
	int counter = 0;
	while (string[counter++] != '\0'); // count till null character
	return counter;
}

bool String::strCmp(const char* string1, const char* string2){
	int i = 0;
	while (string1[i] != '\0') { // run till end of first string
		if (string1[i] != string2[i])
			return false; // found unequality
		i++; // increment index
	}
	if (string2[i] != '\0') // not reached the end of string2
		return false;
	return true; // passed all tests
}

char* String::strCpy(char* string1, const char* string2) {
	char* pstring1 = string1; // create init pointer copy
	while (*string2 != '\0') { // run till end of string 2
		*pstring1++ = *string2++; // copy values
	}
	*pstring1 = *string2; // add null
	return string1; // return so values wont be deleted
}

char* String::concatFy(char* str1, const char* str2) {
	char* pstr1 = str1; // save pointer to the start
	while (*str1++ != '\0');// advance the pointer till null
	do {
		*str1 = *str2; // copy values
	} while (*str2++ != '\0');
	return pstr1;
}

String::String() {
	this->mString = new char; // alocate new memmory to size of one char
	//this->mString[0] = '\0'; // set the delimiter
}

String::String(const char* data) {
	int counter = countStrlen(data); // counting the number of letters in given char array
	this->mString = new char[counter + 1]; // allocating new mem for Characters + 1 for null character
	this->strCpy(this->mString, data);
}

String::String(const String& data) {
	this->mString = new char[data.getStrlen() + 1]; // allocate new memory in size of Strlen + 1 for null character
	int length = data.getStrlen();
	this->strCpy(this->mString, data.mString);
}

String::~String() {
	delete this->mString; // free memmory
}

inline int String::getStrlen() const {
	int counter = 0;
	while (this->mString[counter++] != '\0'); // count till null character
	return counter;
}

void String::setString(const char* data) {
	int length = countStrlen(data); // set new Characters length from the given one
	if (this->mString) delete this->mString; // delete the old Characters
	this->mString = new char[length + 1]; // allocate new memory + 1 for null character
	this->mString = this->strCpy(this->mString,data); // copy values from given Characters to new one
}

void String::print() const {
	for (int i = 0; i < this->getStrlen(); i++) {
		cout << this->mString[i]; // prints each character in the Characters
	}
	cout << endl; // end line
}

String String::operator=(const String& other) {
	if (this != &other) { // check if not equal
		this->setString(other.mString); // Replace the string + Delete the old one
	}
	return *this; // return the string
}

bool String::operator==(const String& other) {
	int length = this->getStrlen();
	if (this == &other) // check if there is any need for test
		return true; // if the checked value is the same as the other one
	if (length == other.getStrlen()) { // check string lengths
		for (int i = 0; i < length; i++) { // run trough all the letters
			if (this->mString[i] != other.mString[i]) // search for non equal value
				return false; // exit and return false if found
		}
		return true; // return if all tests passed
	}
	return false; // if string lengths are unequal
}

ostream& operator<<(ostream& os, const String& str) {
	os << str.mString; // ostream handles strings
	return os; // return ostream object
}

istream& operator>>(istream& is, String& str) {
	is >> str.mString; // get data from buffer to mString
	return is;
}
