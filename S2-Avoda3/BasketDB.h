/* Assignment: 3
Author: Gleb Tcivie*/

#pragma once
#include <iostream>
#include "Database.h"

using namespace std;
/// <summary>
/// NODE ITEM stores the data of the items in the basket
/// </summary>
class NodeItem {
public:
	/// <summary>
	/// Ctor
	/// </summary>
	NodeItem();
	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="id">Item id</param>
	/// <param name="numberItems">Number of copies of the item - defaults to 1</param>
	/// <param name="next">Pointer to the next link - defaults to nulptr</param>
	NodeItem(int id, int numberItems = 1, NodeItem* next = nullptr);
	/// Dtor
	~NodeItem();
	/// <summary>
	/// Cctor - Copies also the pointer to the original destination (needs redifinition)
	/// </summary>
	/// <param name="item">Pointer to item</param>
	NodeItem(const NodeItem& item);
	/// <summary>
	/// Returns the number of copies of the item
	/// </summary>
	/// <returns>Number of copies</returns>
	inline int getNumberOfItems() { return this->mNumberOfItems; };
	/// <summary>
	/// Gets the Item id
	/// </summary>
	/// <returns>Item id</returns>
	inline int getItemId() { return this->mId; };
	/// <summary>
	/// Gets the next item in the basket
	/// </summary>
	/// <returns>Pointer to the next item in the basket</returns>
	inline NodeItem* getNext() { return this->mNext; };
	/// <summary>
	/// Sets the next item in the list
	/// </summary>
	/// <param name="next">Pointer to the next item in the list</param>
	inline void setNext(NodeItem* next) { this->mNext = next; };
	/// <summary>
	/// Increments the number of items stored by given number
	/// </summary>
	/// <param name="number">how much increment by - defaults to 1</param>
	inline void incNumItems(int number = 1) { this->mNumberOfItems += number; };

private:
	int mNumberOfItems;	// Number of items of same kind
	int mId;	// item id
	NodeItem* mNext;	// next item in nodeItem
};

/// <summary>
/// NODE BASKET is the nodes that store the head of each basket
/// </summary>
class NodeBasket {
public:
	/// <summary>
	/// Ctor
	/// </summary>
	NodeBasket();
	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="id">Id of the item</param>
	/// <param name="numberItems">Number of copies of the item - defaults to 1</param>
	/// <param name="next">Next Basket in the lise - defaults to nullptr</param>
	NodeBasket(int id, int numberItems = 1, NodeBasket* next = nullptr);
	/// <summary>
	/// Cctor
	/// </summary>
	/// <param name="basket">Pointer to basket</param>
	NodeBasket(const NodeBasket& basket);
	/// Dtor
	~NodeBasket();
	/// <summary>
	/// Gets the next node in line
	/// </summary>
	/// <returns>Pointer to the next node</returns>
	inline NodeBasket* getNext() const { return this->mNext; };
	/// <summary>
	/// Returns the start of the basket
	/// </summary>
	/// <returns>Pointe to the first item in the basket</returns>
	inline NodeItem* getNodeItem() const { return this->mHeadItem; };
	/// <summary>
	/// Changes the pointer to the head of the items
	/// </summary>
	/// <param name="head">The item to point to </param>
	inline void setNodeItem(NodeItem* head) { this->mHeadItem = head; };
	/// <summary>
	/// Sets the next item in the list
	/// </summary>
	/// <param name="next">Creates the next item in the lise</param>
	inline void setNext(NodeBasket* next) { this->mNext = next; };
	/// <summary>
	/// Gets the basket id
	/// </summary>
	/// <returns></returns>
	inline int getNodeId() const { return this->mCurID; };
	/// <summary>
	/// For given pointer to item the function deletes the entire following list
	/// </summary>
	/// <param name="item">pointer to the item we want to start deleting from</param>
	void delNodeTree(NodeItem* item);
	/// <summary>
	/// Deletes the item from the basket
	/// </summary>
	/// <param name="itemId">The id of the item to delete</param>
	void delItem(int itemId);

	friend ostream& operator << (ostream& os, const NodeBasket& basket);
	/// <summary>
	/// Unions two baskets together and returns a new one
	/// </summary>
	/// <param name="other">The other basket</param>
	/// <returns>New Basket object in the list
	/// </returns>
	NodeBasket* operator+(const NodeBasket& other);
	/// <summary>
	/// Creates new basket from intersection of two other baskets
	/// </summary>
	/// <param name="other">second basket</param>
	/// <returns>New basket pointing to nullptr - Intersected of two</returns>
	NodeBasket* operator-(const NodeBasket& other);
	/// <summary>
	/// Prints all items in the current basket
	/// </summary>
	void print(int itemId = 0);
private:
	NodeItem* mHeadItem;	// Item list head
	NodeBasket* mNext;	// Next basket
	static int mID;	// basket id counter
	int const mCurID;	// cutent node id
};

/// <summary>
/// BASKET the main class that stores the head to the basket list
/// </summary>
class BasketDB {
private:
	static NodeBasket* mHead;	// Basket list head
public:
	/// <summary>
	/// Ctor
	/// </summary>
	BasketDB();
	/// Dtor
	~BasketDB();	// TODO

	/// <summary>
	/// Adds new basket and returns the basket id
	/// </summary>
	/// <returns>Created basket id</returns>
	int addBasket();
	/// <summary>
	/// Deleted the basket by it's id
	/// </summary>
	/// <param name="basketId">Basket id</param>
	void delBasket(int basketId);
	/// <summary>
	/// Adds new item to the basket
	/// If the item is already in the list it increments the number of items by quantity (1)
	/// If the item does not exists and there is an item with higher id then it inserts new item between
	/// If the item not found and there is not item with higher id then it just adds it to the end
	/// </summary>
	/// <param name="basketId">ID of the basket</param>
	/// <param name="itemId">ID of the item</param>
	/// <param name="quantity">Quantity of the item - Defaults to one</param>
	static void addItem(int basketId,int itemId,int quantity = 1);
	/// <summary>
	/// Returns the head of the baskets
	/// </summary>
	/// <returns></returns>
	NodeBasket* getHead() const { return this->mHead; };
	/// <summary>
	/// appends the given basket to the last one
	/// </summary>
	/// <param name="basket">The basket to append to the end</param>
	static void setLastItem(NodeBasket* basket);
	/// <summary>
	/// Deletes all the items with the given id from all baskets
	/// </summary>
	/// <param name="itemId">Item id</param>
	static void delFromAllBaskets(int itemId);

	friend ostream& operator << (ostream& os, const BasketDB& database);
	/// <summary>
	/// Prints by basketId and itemid (default print all)
	/// </summary>
	/// <param name="basketId">Basket to print</param>
	/// <param name="itemId">Item id to print</param>
	void print(int basketId = 0, int itemId = 0) const;
};