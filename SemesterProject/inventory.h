#ifndef inventory_h
#define inventory_h

#include <string>

#include <iostream>

using namespace std;
typedef int barcodetype;
struct node
{
	float price;
	string name;
	string location;
	barcodetype barcode;
	int quantity;
	node* next;
};

class inventory
{
public:
	inventory();
	~inventory();
	void insert(int Price, string Name, string Location, barcodetype Barcode);
	bool save(int Price, string Name, string Location, barcodetype Barcode);
	bool isFull();
	node* select(float Price, string Name, string Location, barcodetype Barcode, int Quantity);
private:
	node* head;
	int length;
	float price;
	string name;
	string location;
	barcodetype barcode;
	int quantity;
	node* next;
};


#endif