/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include "basketDB.h"
class Client {
private:
	BasketDB* mBas;
	/// <summary>
	/// Checks if the node basket exists in the system - Returns the found basket
	/// </summary>
	/// <param name="id">Basket id</param>
	/// <returns>Pointer to basket if found, nullptr if Not</returns>
	NodeBasket* checkNodeBasket(int id);
	/// <summary>
	/// Checks if there are any items in the store
	/// </summary>
	/// <returns>True if there are , False otherwise</returns>
	bool checkStoreItems() const;

	void deleteNonExistingItems();
public:
	/// <summary>
	/// Ctor
	/// </summary>
	/// <param name="db">Pointer to the baskets database</param>
	Client(BasketDB* db) { this->mBas = db; };

	~Client() {};
	/// <summary>
	/// Prompts the user for input and deletes the basket
	/// </summary>
	/// <param name="bas">Pointer to basket database</param>
	void delBasket() const;
	/// <summary>
	/// Prints all the data in the baskets
	/// </summary>
	/// <param name="bas">Pointer to basket database</param>
	void printAll() const;
	/// <summary>
	/// Prompts the user to choose what basket to print
	/// </summary>
	void printBasket() const;
	/// <summary>
	/// Build products with selection of them
	/// </summary>
	void buildBasketSelect() const;
	/// <summary>
	/// Prompts the user with the option to chose which basket to copy (by id) 
	/// and then creates new copy and puts it at the end of the list
	/// </summary>
	void buildBasketCopy();
	/// <summary>
	/// Creates new basket from union of two baskets
	/// </summary>
	void buildBasketUnion();
	/// <summary>
	/// Intersects two baskets and creates new one
	/// </summary>
	void buildBasketIntersect();
};

