/* Assignment: 3
Author: Gleb Tcivie*/

#include "BasketDB.h"

int NodeBasket::mID = 0;
NodeBasket* BasketDB::mHead = new NodeBasket();

NodeBasket::NodeBasket() :
	mCurID(this->mID) {
	this->mHeadItem = nullptr;	// create new nodeItem
	this->mNext = nullptr;	// set the next to null
	this->mID++;	// increment the id by one
}

NodeBasket::NodeBasket(int id, int numberItems, NodeBasket* next) :
	mCurID(this->mID++){
	NodeItem* Item = new NodeItem(id, numberItems);	// create new item
	this->mNext = next;	// set the next basket
	this->mHeadItem = Item;	// set the item
}

NodeBasket::NodeBasket(const NodeBasket& basket) :
	mCurID(this->mID++) {
	this->mNext = basket.mNext;	// copy the next basket
	NodeItem* pItem = basket.mHeadItem;	// point to the first item
	NodeItem* FollowPItem = pItem;	// follower to pitem
	if (pItem != nullptr) {
		this->mHeadItem = new NodeItem(*pItem);	// copy the item to the head
		pItem = pItem->getNext();	// advance
		while (pItem != nullptr) {	// run till the end
			pItem = new NodeItem(*pItem);	// create copy of the item
			FollowPItem->setNext(pItem);	// set the next to the copied item
			FollowPItem = pItem;	// advance the follow by one
			pItem = pItem->getNext();	// go to next item
		}
		FollowPItem->setNext(pItem);	// set to latest (nullptr)
	} else
		this->mHeadItem = nullptr;
}

NodeBasket::~NodeBasket() {
	this->delNodeTree(this->getNodeItem());	// delete the node tree
	this->mNext = nullptr;	// set the next node to null
	mHeadItem->~NodeItem();	// delete the item pointer
	delete mNext;	// delete the next pointer
}

void NodeBasket::delNodeTree(NodeItem* item) {
	if (item->getNext() != nullptr) {	// check if the given node is null
		NodeBasket::delNodeTree(item->getNext());	// go into recursion to next object till the end
		delete item;	// delete the current item
	}
}

void NodeBasket::delItem(int itemId) {
	NodeItem* pItem = this->getNodeItem();	// gets the first item in the node
	if (pItem->getItemId() == itemId) {	// the first item is the right one
		this->setNodeItem(pItem->getNext());	// point to the next item
		pItem = nullptr;	// point to null
		delete pItem;	// deletes the item
	} else {
		while (pItem->getNext() != nullptr) {
			if (pItem->getNext()->getItemId() == itemId) {	// if the item is the one
				NodeItem* pItem2 = pItem->getNext();	// mark the found item
				pItem->setNext(pItem2->getNext());	// points to the following item
				pItem2->setNext(nullptr);	// point to null
				delete pItem2;	// delete the item from list
				return;	// no need for continue
			}
			pItem = pItem->getNext();	// advance
		}
	}
}

NodeBasket* NodeBasket::operator+(const NodeBasket& other) {
	NodeBasket* pNodeBasket1 = new NodeBasket(*this);	// creates copy of this object
	//pNodeBasket1->setNext(nullptr);	// point the next to null
	BasketDB::setLastItem(pNodeBasket1);	// sets the created basket to the end
	NodeItem* pNodeItem1 = pNodeBasket1->getNodeItem();	// get the first item in the list
	NodeItem* pNodeItem2 = other.getNodeItem();	// get the first item in the list of the second basket
	if (pNodeItem1 != nullptr && pNodeItem2 != nullptr) {	// if the baskets are not empty
		while (pNodeItem1 != nullptr && pNodeItem2 != nullptr) {	// run till end of both
			if (pNodeItem1->getItemId() == pNodeItem2->getItemId()) {// check if it's the same item
				if (pNodeItem1->getNumberOfItems() < pNodeItem2->getNumberOfItems()) {
					int inc = pNodeItem2->getNumberOfItems() - pNodeItem1->getNumberOfItems();	// gets the diference of item 1 from item 2
					inc = inc < 0 ? 0 : inc;	// if inc is smaller than 0 the return 0 otherwise use inc
					BasketDB::addItem(pNodeBasket1->mCurID, pNodeItem2->getItemId(),inc);	// ads the missing number
				}
				pNodeItem1 = pNodeItem1->getNext();	// advance
				pNodeItem2 = pNodeItem2->getNext();	// advance
			} else if (pNodeItem1->getItemId() < pNodeItem2->getItemId()){	// if id of the first is smaller
				pNodeItem1 = pNodeItem1->getNext();	// advance
			} else {
				BasketDB::addItem(pNodeBasket1->mCurID, pNodeItem2->getItemId(), pNodeItem2->getNumberOfItems());	// adds the item with the lower id
				pNodeItem2 = pNodeItem2->getNext();	// advance
			}
		}	// Runs till the end of the first item list and adds all the matching items
		while (pNodeItem2 != nullptr) {	// add the rest to the list
			BasketDB::addItem(pNodeBasket1->mCurID, pNodeItem2->getItemId(), pNodeItem2->getNumberOfItems());	// adds the missing items
			pNodeItem2 = pNodeItem2->getNext();	// advance
		}
	}
	return pNodeBasket1;	// return basket
}

NodeBasket* NodeBasket::operator-(const NodeBasket& other) {
	NodeBasket* pNodeBasket1 = new NodeBasket();	// creates copy of this object
	//pNodeBasket1->setNext(nullptr);	// point the next to null
	BasketDB::setLastItem(pNodeBasket1);	// sets the created basket to the end
	NodeItem* pNodeItem1 = this->getNodeItem();	// get the first item in the list
	NodeItem* pNodeItem2 = other.getNodeItem();	// get the first item in the list of the second basket
	if (pNodeItem1 != nullptr && pNodeItem2 != nullptr) {	// if the baskets are not empty
		while (pNodeItem1 != nullptr && pNodeItem2 != nullptr) {	// run till end of both
			if (pNodeItem1->getItemId() == pNodeItem2->getItemId()) {// check if it's the same item
				//if (pNodeItem1->getNumberOfItems() < pNodeItem2->getNumberOfItems()) {
					int smallest = pNodeItem1->getNumberOfItems() < pNodeItem2->getNumberOfItems() ? pNodeItem1->getNumberOfItems() : pNodeItem2->getNumberOfItems();	// return the smallest of the both
					//smallest = smallest > 0 ? -smallest : 0;	// if number is negative then save , otherwise store 0

					/// Add method adds (+) the quantity to the item, so we stored in the smallest param
					/// negative value if the number of the second item is smaller than the first one
					/// and we "add" the negative value +(-)
					/// EX: p1q = 10 , p2q = 8
					/// min = 10 - 8 = (-)2
					/// 
					/// EX2: p1q = 8, p2q = 10
					/// min = 8 - 10 = 0
					

					BasketDB::addItem(pNodeBasket1->mCurID, pNodeItem2->getItemId(),	// adds the item to the list
						smallest);	// choses the smallest number of the both
				//}
				pNodeItem1 = pNodeItem1->getNext();	// advance
				pNodeItem2 = pNodeItem2->getNext();	// advance
			} else if (pNodeItem1->getItemId() < pNodeItem2->getItemId()) {	// if id of the first is smaller
				pNodeItem1 = pNodeItem1->getNext();	// advance
			} else {
				pNodeItem2 = pNodeItem2->getNext();	// advance
			}
		}	// Runs till the end of the first item list and adds all the matching items
	}
	return pNodeBasket1;	// return basket
}

void NodeBasket::print(int itemId) {
	NodeItem* pitem = this->mHeadItem;	// point to the head of the items in the basket
	while (pitem != nullptr) {	// run till the end of the items
		if (itemId == 0 || (itemId == pitem->getItemId())) {	// print either itemID is 0 (none given) or matches the given id
			Database::printById(pitem->getItemId());	// prints the item
			cout << "<Ammount> " << '<' << pitem->getNumberOfItems() << '>' << endl;	// print item quantity
		}
		pitem = pitem->getNext();	// go to next item
	}
}

NodeItem::NodeItem() {
	this->mNumberOfItems = 0;	// number of items 0
	this->mId = 0;	// item id
	this->mNext = nullptr;	// next null
}

NodeItem::NodeItem(int id, int numberItems, NodeItem* next) {
	this->mId = id;
	this->mNumberOfItems = numberItems;
	this->mNext = next;
}

NodeItem::~NodeItem() {
	this->mNext = nullptr;
	delete this->mNext;
}

NodeItem::NodeItem(const NodeItem& item) {
	this->mId = item.mId;
	this->mNext = item.mNext;
	this->mNumberOfItems = item.mNumberOfItems;
}

BasketDB::BasketDB() {
	this->mHead = nullptr;
}

BasketDB::~BasketDB() {
	delete mHead;
}

int BasketDB::addBasket() {
	if (this->mHead != nullptr) {	// check if there are any nodes
		NodeBasket* pNextNode = this->mHead;	// pointer to the next node
		while (pNextNode->getNext() != nullptr)	// run til the end
			pNextNode = pNextNode->getNext();	// advance by one
		pNextNode->setNext(new NodeBasket());	// allocate new memmory for the basket
		return pNextNode->getNext()->getNodeId();	// return the created node id
	} else {
		this->mHead = new NodeBasket();	// create new one
		return this->mHead->getNodeId();	// return the id
	}

}

void BasketDB::delBasket(int basketId) {
	NodeBasket* pbasket = this->mHead;	// point to the first basket
	if (pbasket->getNodeId() == basketId) {	// if the first basket is the one
		this->mHead = pbasket->getNext();	// link the head to the next item in the list
		delete pbasket;	// delete the node
	} else {	// its not the first item
		while (pbasket->getNext() != nullptr && pbasket->getNext()->getNodeId() != basketId) {
			pbasket = pbasket->getNext();	// advance to the next one
		}

		/// At this point we're pointing either at the end of the list or
		/// at the selected node

		if (pbasket->getNext() != nullptr) {	// if we found the basket
			NodeBasket* helper = pbasket->getNext();	// pointer to the item
			pbasket->setNext(helper->getNext());	// set the next one one jump over
			helper->setNext(nullptr);	// set the next to null
			delete  helper;	// delete the node
		} else {	// no basket with the id is found
			cout << "Error: Product basket with corresponding serial does not exist" << endl;
		}
	}

}

void BasketDB::addItem(int basketId, int itemId, int quantity) {
	NodeBasket* pNodeBasket = BasketDB::mHead;	// get the first basket
	while (pNodeBasket != nullptr && pNodeBasket->getNodeId() != basketId)	// check if that's the id one
		pNodeBasket = pNodeBasket->getNext();	// advance by one
	if (pNodeBasket == nullptr) {	// not found the basket
		cout << "Error: Selected product serial number does not exist." << endl;
		return;	// stop the operation
	}	// else we found the right basket

	if (Database::checkIfItemExists(itemId)) {	// check if the item is in the database
		NodeItem* pNodeItem = pNodeBasket->getNodeItem();
		if (pNodeItem == nullptr) { // first item is null
			pNodeBasket->setNodeItem(new NodeItem(itemId, quantity));	// set the pointer to the item
		} else if (pNodeItem->getItemId() > itemId) { // if the first item has bigger id
			pNodeBasket->setNodeItem(new NodeItem(itemId, quantity, pNodeItem));	// set the pointer to the item
		} else if (pNodeItem->getItemId() == itemId) {	// if the first item is the one we need
			pNodeItem->incNumItems(quantity);	// increments the found item
		} else {	// rest of the cases (the first item has smaller id)
			while (pNodeItem->getNext() != nullptr && pNodeItem->getNext()->getItemId() < itemId) {
				pNodeItem = pNodeItem->getNext();	// advancing till null or item with higher id
			}
			if (pNodeItem->getNext() == nullptr) {	// the next one is null
				pNodeItem->setNext(new NodeItem(itemId, quantity));	// set the last item 
			} else if (pNodeItem->getNext()->getItemId() == itemId) {	// we found the same item
				pNodeItem->getNext()->incNumItems(quantity);	// increments the found item
			} else {	// else the next item has bigger id
				pNodeItem->setNext(new NodeItem(itemId, quantity, pNodeItem->getNext()));	// create in between
			}
		}
	//	NodeItem* pNodeItem = pNodeBasket->getNodeItem();	// gets the head for the item
	//	if (pNodeItem != nullptr) {	// if the basket is not empty
	//		while (pNodeItem->getNext() != nullptr && pNodeItem->getItemId() < itemId)	// runn till the id is not lower or got to the end
	//			pNodeItem = pNodeItem->getNext();	// advance to next node

	//		/// At this poin we got pointer to object that is either pointing at the same object as the id
	//		/// Or pointing at object with id that is higher
	//		/// p->[_|_|_]->[_|_|_]
	//		/// Or the pointer pointing at object that's pointing to null (Were at the end)
	//		/// p->[_|_|_]->nullptr

	//		if (pNodeItem == pNodeBasket->getNodeItem()) {	// if we didn't moved at all
	//			if (pNodeItem->getItemId() == itemId)	// if the first object is the one we need
	//				pNodeItem->incNumItems(quantity);	// increment quantity
	//			else if (pNodeItem->getItemId() > itemId) {	// the item has higher id
	//				NodeItem* Item = new NodeItem(itemId, quantity, pNodeItem);	// create item and point next to the currently pointed head
	//				pNodeBasket->setNodeItem(Item);	// update the head of the list to the made item
	//			} else {	// the item has higher id and we didn't moved (only one item in list ?)
	//				NodeItem* Item = new NodeItem(itemId, quantity);	// create item and point to null
	//				pNodeItem->setNext(Item);	// set the pointer of the first item to next
	//			}
	//		} else if (pNodeItem->getItemId() == itemId) {	// pointing at item with the same id
	//			pNodeItem->incNumItems(quantity);	// increments the number of stored items
	//		} else if (pNodeItem->getNext()->getItemId() > itemId) {	// next item got higher id
	//			NodeItem* Item = new NodeItem(itemId, quantity, pNodeItem->getNext());	// create node with pointer to the next item
	//			pNodeItem->setNext(Item);	// point to the created item
	//		} else {	// next is nullptr
	//			NodeItem* Item = new NodeItem(itemId, quantity);	// create item with pointer to null
	//			pNodeItem->setNext(Item);	// point to the new created item
	//		}
	//	} else {
	//		NodeItem* Item = new NodeItem(itemId, quantity);	// create item with pointer to null
	//		pNodeBasket->setNodeItem(Item);	// point the start to the first item
	//	}
	} else {	// item with the id does not exists in the database
		cout << "Error: Item with corresponding serial does not exist." << endl;
	}
}

void BasketDB::setLastItem(NodeBasket* basket) {
	NodeBasket* pItem = BasketDB::mHead;	// get the head
	if (BasketDB::mHead == nullptr)
		BasketDB::mHead = basket;	// set the first item as pointer to basket
	else while (pItem->getNext() != nullptr)
		pItem = pItem->getNext();	// advance
	pItem->setNext(basket);	// set the last to the given basket
	basket->setNext(nullptr);	// set pointer to null
}

void BasketDB::delFromAllBaskets(int itemId) {
	NodeBasket* pBasket = BasketDB::mHead;	// gets the head of the baskets
	while (pBasket != nullptr) {	// till the end
		pBasket->delItem(itemId);	// delete the found id
		pBasket = pBasket->getNext();	// advance
	}
}

void BasketDB::print(int basketId, int itemId) const {
	NodeBasket* pBasket = this->mHead;	// pointer to the start of the basket
	while (pBasket != nullptr) {
		if (basketId == 0 || pBasket->getNodeId() == basketId) {
			cout << "\033[1;32m<Product Basket> \033[0m" << '<' << pBasket->getNodeId() << '>' << endl;	// print the basket id
			pBasket->print(itemId);
		}
		pBasket = pBasket->getNext();
	}
}

ostream& operator<<(ostream& os, const NodeBasket& basket) {
	NodeItem* pitem = basket.mHeadItem;	// point to the head of the items in the basket
	while (pitem != nullptr) {	// run till the end of the items
		os << pitem;
		pitem = pitem->getNext();
	}
	return os;
}

ostream& operator<<(ostream& os, const BasketDB& database) {
	NodeBasket* pBasket = database.mHead;	// pointer to the list of the baskets
	while (pBasket != nullptr) {	// run till basket is not null
		os << "<Product Basket> " << '<' << pBasket->getNodeId() << '>' << endl;	// print the basket id
		os << pBasket;
		pBasket = pBasket->getNext();
	}
	return os;
}
