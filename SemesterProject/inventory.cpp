#include "inventory.h"

inventory::inventory() {
	head = nullptr;
}

inventory::~inventory() {

}

void inventory::insert(int Price, string Name, string Location, barcodetype Barcode) {
	if (head == nullptr) {
		node* newNode = new node; //creates new node called newnode
		newNode->next = head; //sets the newnode next pointer to the top item
		head = newNode; //sets head to the newest created node
		newNode->name = Name; //populates newest node with inserted information
		newNode->price = Price;
		newNode->name = Name;
		newNode->location = Location,
		newNode->barcode = Barcode;
		length++;
	}
}

bool inventory::save(int price, string name, string location, barcodetype barcode)
{
	return false;
}

node* inventory::select(float Price, string Name, string Location, barcodetype Barcode, int Quantity)
{
	node* newNode = new node;
	node* localHead = new node;
	newNode = localHead = head;
	int matchedItems = 0;
	while (newNode->next != nullptr) {
		if (Price == newNode->price || Name == newNode->name || Location == newNode->location || Barcode == newNode->barcode || Quantity == newNode->quantity) {
			newNode->name = Name; //populates newest node with inserted information
			newNode->price = Price;
			newNode->name = Name;
			newNode->location = Location,
			newNode->barcode = Barcode;
			matchedItems++;
		}
		newNode = newNode->next;
	}
	
	return newNode;
}
