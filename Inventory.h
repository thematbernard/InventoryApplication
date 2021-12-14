#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <vector>
#include <string>
#include "InventoryItem.h"

class Inventory{

	public:
		//constructor / destructor
		Inventory();
		~Inventory();

		void list() const;
		void load(const string &);
		void save(const string &);
		void add(InventoryItem * invItem);
		void addItem();
		void editItem();
		void deleteItem();

		int findByGTIN(const string &GTIN);


	private:
		vector<InventoryItem *> invItems;
		string infile_name;


};
#endif
