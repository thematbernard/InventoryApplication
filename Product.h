#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <array>
#include <iostream>
#include <iomanip>


using namespace std;

class Product{
	public:
		Product(const string&, const string&, float, const string&);
		Product();
		~Product();
		
		//set functions
		void setGTIN(const string&);
		void setName(const string&);
		void setWholesale(float);
		void setDescription(const string&);
		
		//get functions
		string getGTIN() const;
		string getName() const;
		float getWholesale() const;
		string getDescription() const;
		
		//other functions
		void showProduct() const;

	private:
		string GTIN;
		string name;
		float wholesale;
		string description;

};
#endif
