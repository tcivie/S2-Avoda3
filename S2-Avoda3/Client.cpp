/* Assignment: 3
Author: Gleb Tcivie*/

#include "Client.h"

NodeBasket* Client::checkNodeBasket(int id) {
	NodeBasket* pBasket = this->mBas->getHead();	// get the pointer
	while (pBasket != nullptr && pBasket->getNodeId() != id)	// run till not null or same id
		pBasket = pBasket->getNext();	// advance
	return pBasket;
}

bool Client::checkStoreItems() const {
	return Database::checkIfItemExists();
}

void Client::delBasket() const {
	if (this->checkStoreItems()) {
		int basketId;
		cin >> basketId;	// wait for user input	(basket id)
		this->mBas->delBasket(basketId);	// init basket delete method
	} else 
		cout << "Error: There are no items in store." << endl;
}

void Client::printAll() const {
	if (this->checkStoreItems())
		this->mBas->print();
	else
		cout << "Error: There are no items in store." << endl;
}

void Client::printBasket() const {
	if (this->checkStoreItems()) {
		int basketId;
		cin >> basketId;	// wait for use to input (basket id)
		this->mBas->print(basketId);	// print the chosen basket
	} else
		cout << "Error: There are no items in store." << endl;
}

void Client::buildBasketSelect() const {
	if (this->checkStoreItems()) {
		int itemId, ammount;
		int basketId = this->mBas->addBasket();	// add new basket
		cout << "Enter product serial and amount:" << endl;
		do {
			cin >> itemId >> ammount;	// get input from user
			if (itemId != 0 && ammount > 0)	// check if the input is valid
				this->mBas->addItem(basketId, itemId, ammount);	// add the item to the basket
		} while (itemId != 0 && ammount != 0);	// end of input
	} else 
		cout << "Error: There are no items in store." << endl;
}

void Client::buildBasketCopy() {
	if (checkStoreItems()) {
		int basketId;
		cout << "Which product basket to copy?" << endl;
		cin >> basketId;	// get the basket id
		NodeBasket* pBasket, * pLast;	// create pointer to the data

		if (pBasket = this->checkNodeBasket(basketId)) {	// checks if the basket exists and stores it
			pLast = pBasket;	// point to the found basket
			pBasket = new NodeBasket(*pBasket);	// create new basket
			pBasket->setNext(nullptr);	// set next to null
			while (pLast->getNext() != nullptr)	// go till points to nullptr
				pLast = pLast->getNext();	// advance
			pLast->setNext(pBasket);	// modify the last node to point at the created one
		} else {
			cout << "Error: Selected product serial number does not exist." << endl;
		}
	} else
		cout << "Error: There are no items in store." << endl;
}

void Client::buildBasketUnion() {
	if (this->checkStoreItems()) {
		int basket1, basket2;
		cout << "Which product baskets to use?" << endl;
		cin >> basket1 >> basket2;	// copy the input from user
		NodeBasket* pBasket1 = this->mBas->getHead();	// pointer to basket
		NodeBasket* pBasket2 = pBasket1;	// add another copy
		while (pBasket1 != nullptr && pBasket1->getNodeId() != basket1)	// run till got the id
			pBasket1 = pBasket1->getNext();	// advance
		while (pBasket2 != nullptr && pBasket2->getNodeId() != basket2)	// run till got the id
			pBasket2 = pBasket2->getNext();	// advance
		if (pBasket1 == nullptr || pBasket2 == nullptr)	// if one of the baskets are null
			cout << "Error: One of the selected product baskets does not exist." << endl;
		else {	// create union
			NodeBasket* unitedBasket = *pBasket1 + *pBasket2;
			pBasket1 = this->mBas->getHead();	// point to start
			while (pBasket1->getNext() != nullptr)	// run till end
				pBasket1 = pBasket1->getNext();	// advance
			pBasket1->setNext(unitedBasket);	// point the last basket to the created one
			unitedBasket->setNext(nullptr);	// point the created basket to null
		}
	} else 
		cout << "Error: There are no items in store." << endl;
}

void Client::buildBasketIntersect() {
	if (this->checkStoreItems()) {
		int basket1, basket2;
		cout << "Which product baskets to use?" << endl;
		cin >> basket1 >> basket2;	// copy the input from user
		NodeBasket* pBasket1 = this->mBas->getHead();	// pointer to basket
		NodeBasket* pBasket2 = pBasket1;	// add another copy
		while (pBasket1 != nullptr && pBasket1->getNodeId() != basket1)	// run till got the id
			pBasket1 = pBasket1->getNext();	// advance
		while (pBasket2 != nullptr && pBasket2->getNodeId() != basket2)	// run till got the id
			pBasket2 = pBasket2->getNext();	// advance
		if (pBasket1 == nullptr || pBasket2 == nullptr)	// if one of the baskets are null
			cout << "Error: One of the selected product baskets does not exist." << endl;
		else {	// create union
			NodeBasket* unitedBasket = *pBasket1 - *pBasket2;
			BasketDB::setLastItem(unitedBasket);
			//pBasket1 = this->mBas->getHead();	// point to start
			//while (pBasket1->getNext() != nullptr)	// run till end
			//	pBasket1 = pBasket1->getNext();	// advance
			//pBasket1->setNext(unitedBasket);	// point the last basket to the created one
			//unitedBasket->setNext(nullptr);	// point the created basket to null
		}
	} else 
		cout << "Error: There are no items in store." << endl;
}
