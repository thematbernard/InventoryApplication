#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>
#include <array>
#include <iostream>
#include <iomanip>
#include "Product.h"

class InventoryItem{

	public:
		//constructors
		InventoryItem(Product* p, double retail, int quantity);
		InventoryItem();
		~InventoryItem();

		//setter functions
		void setProduct(Product* p);
		void setRetail(double retail);
		void setQuantity(int quantity);

		void setName(string &name);
		void setGTIN(string &GTIN);
		void setWholesale(float wholesale);
		void setDescription(string &desc);

		//getter functions
		Product* getProduct() const;
		double getRetail() const;
		int getQuantity() const;

		string getName() const;
		string getGTIN() const;
		string getDescription() const;
		float getWholesale() const;


		//other member functions
		void showItem() const;
		bool loadItem(ifstream &fileName);
		bool readItem();
		void edit();
		void saveItem(ofstream &fileName);

	private:
		Product *prod;
		double retail;
		unsigned int quantity;

};//end class
#endif
