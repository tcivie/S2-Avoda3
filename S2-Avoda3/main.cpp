/* Assignment: 3
Author: Gleb Tcivie*/

#ifndef IOSTREAM
#include <iostream>
#include "Manager.h"
#include "Client.h"
#endif // !IOSTREAM
using namespace std;
int main() {
	Database* db = new Database();	// create new database for the items (Store)
	BasketDB* basketDb = new BasketDB();	// create new database for the baskets in the store (Cliet)
	Manager* manager = new Manager(db); // create new mamager instance
	Client* client = new Client(basketDb);	// create new instance of client on the same database
	cout << "========== MENU ==========" << endl;
	while (true) { // Loop in the first menu
		int option;
		cout << "1.Add item to store data base" << endl
			<< "2.Handle client" << endl
			<< "3.Exit" << endl
			<< "Chose your option [1-3] : ";
		cin >> option;
		bool flag = true;
		switch (option) {
			case 1: // ADD ITEM
			while (flag) {
				int option2;
				cout << "1.Add new item" << endl // print options
					<< "2.Delete item" << endl
					<< "3.Print item" << endl
					<< "4.Print all items" << endl
					<< "5.Return" << endl;
				cin >> option2; // input option
				switch (option2) {
					case 1: // ADD
					manager->addItem();
					break;
					case 2: // DELETE
					manager->delItem();
					break;
					case 3: // PRINT ITEM
					manager->printItem();
					break;
					case 4: // PRINT ALL
					manager->printAllItems();
					break;
					case 5: // RETURN
					flag = false;	// change flag status (Exititng loop)
					break;
					default: // ERR
					cout << "Error: Wrong input, Try again." << endl;
					break;
				}
			}
			break;
			case 2: // HANDLE CLIENT
			while (flag) {
				int option;
				cout << "1.Build new product basket" << endl
					<< "2.Print product basket" << endl
					<< "3.Print all product baskets" << endl
					<< "4.Delete product basket" << endl
					<< "5.Return" << endl;
				cin >> option;
				switch (option) {
					case 1:	// NEW BASKET FROM PRODUCTS
					while (flag) {
						int option2;
						cout << "1.Select products" << endl
							<< "2.Copy existing product basket" << endl
							<< "3.Union of two product baskets" << endl
							<< "4.Intersection of two product baskets" << endl
							<< "5.Return" << endl;
						cin >> option2;
						switch (option2) {
							case 1:	// SELECT PRODUCTS
							client->buildBasketSelect();
							break;
							case 2:	// COPY BASKET
							client->buildBasketCopy();
							break;
							case 3:	// UNION TWO BASKETS
							client->buildBasketUnion();
							break;
							case 4:	// INTERSECT TWO BASKETS
							client->buildBasketIntersect();
							break;
							case 5:	// RETURN
							flag = false;	// bring back the flag status
							break;
							default:	//  ERR
							cout << "Error: Wrong input, Try again." << endl;
							break;
						}
					}
					flag = true;	// bring back the flag status
					break;
					case 2:	// PRINT BASKET
					client->printBasket();
					break;
					case 3:	// PRINT ALL BASKETS
					client->printAll();
					break;
					case 4:	// DELETE BASKET
					client->delBasket();
					break;
					case 5:	// RETURN
					flag = false;	// change flag status (Exititng loop)
					break;
					default:	// ERR
					cout << "Error: Wrong input, Try again." << endl;
					break;
				}
			}
			break;
			case 3: // EXIT
			return 1; // return 1 and finish the program
			break;
			default: // WRONG INPUT
			cout << "Wrong option please try again" << endl;
			break;
		}
	}
	delete client;	// delete the created client to free memmory
	delete manager;	// delete the manager item
}