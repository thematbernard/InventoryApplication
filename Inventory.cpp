#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Inventory.h"
#include "InventoryItem.h"

using namespace std;

		//constructor / destructor
		Inventory::Inventory(){};
		Inventory::~Inventory(){
			for(int i = 0; i < invItems.size(); i++){
				delete invItems[i];
			}//end for loop
		}//end of destructor

void Inventory::list() const{
			

cout << "---------------------------------------------------------------------------" << endl;
cout << "# -    GTIN   -    Name   - Description   - Wholesale - Retail  - Quantity " << endl; 
cout << "---------------------------------------------------------------------------" << endl;
	
				for(int i = 0; i < invItems.size(); i++){
				cout << i << " ";
				invItems[i]->showItem();
				cout << endl;
				}
			
cout << "---------------------------------------------------------------------------" << endl;

}//end of list()
	
void Inventory::load(const string &inflie_name){

	string test;
	//open up file named inventory.txt
	ifstream inventoryFile("inventory.txt", ios::in);
	
	if (!inventoryFile){
		cerr << "Could not open inventory file" << endl;
		exit(EXIT_FAILURE);
	}//end of if
	
	//create an empty InventoryItem Object and invoke loaditem()
	while(inventoryFile){
	InventoryItem *new_item = new InventoryItem();	
	//new_item->loadItem(inventoryFile);

	//loaditem on new_item if returns true add item, else delete the 
	//object created
	if(new_item->loadItem(inventoryFile)){
			add(new_item);
		}//end if
	else
		delete(new_item);

	}//end while


};//end of load


void Inventory::save(const string &outfile_name){


	ofstream outputFile(outfile_name, ios::out);
	
	if (!outputFile){
		cerr << "Could not open file" << endl;
		exit(EXIT_FAILURE);
	}//end of if

		for(int i = 0; i < invItems.size(); i++){
			invItems[i]->saveItem(outputFile);
			}//end for loop

};//end of save

void Inventory::add(InventoryItem * invItem){
			
	//invItem is the existing object to the vector
	//add new item to the back of it.
	invItems.push_back(invItem);

};//end add

void Inventory::addItem(){

	//create new InventoryItem
	InventoryItem *newInvItem;
	
	//invoke readItem to get fields
	newInvItem->readItem();
	
	//add item to the end of the InventoryItem vector with add func
	add(newInvItem);

};//end of addItem

void Inventory::editItem(){

	int index = 0;
	string searchGTIN;
	
	cout << "Enter the GTIN you wish to edit:";
	cin >> searchGTIN;
	cout << endl;

	index = findByGTIN(searchGTIN);
	
	invItems[index]->edit();
	
};//end of editItem
		
void Inventory::deleteItem(){

	int index = 0;
	string deleteGTIN;

	cout << "Enter the GTIN you wish to delete:";
	cin >> deleteGTIN;
	cout << endl;

	index = findByGTIN(deleteGTIN);

	delete(invItems[index]);
	invItems[index] = nullptr;

};//end of deleteItem

		
int Inventory::findByGTIN(const string &GTIN){

	int index = 0;
	
	for(int i = 0; i < invItems.size(); i++){
		if(invItems[index]->getGTIN() == GTIN){
			return(index);
			break;
		}//end if
		else{
			index++;
		}//end else
	}//end for loop	
	return index;
};//end of findByGTIN


