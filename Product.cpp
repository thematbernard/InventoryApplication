//implementation of methods here
#include <iostream>
#include <iomanip>
#include "Product.h"

using namespace std;

Product::Product(const string &upc, const string &nm, float wsale, const string
		&desc):GTIN(upc), name(nm), wholesale(wsale), description(desc){
	cout << "\t \t --> Product constructor with " << GTIN << endl;
}//end of constructor with paramaters

Product::Product(){
	cout << "\t \t --> product constructor with no paramters" << endl;
}

Product::~Product(){
	cout << "\t \t --> Deleteing product " << GTIN << endl;
}//destructor


void Product::setGTIN(const string& GTIN){
	this->GTIN = GTIN;
}//end setGTIN

void Product::setName(const string &name){
	this->name = name;
};//end setName

void Product:: setWholesale(float wholesale){
	this->wholesale = wholesale;
}//end setWholesale

void Product::setDescription(const string &description){
	this->description = description;
}//end setDescription


//get functions
string Product::getGTIN() const{
	return GTIN;
}//end of getGTIN

string Product::getName() const{
	return name;
}//end of getName

float Product::getWholesale() const{
	return wholesale;
}//end of getWholesale

string Product::getDescription() const{
	return description;
}//end getDescription


//not set/get functions
void Product::showProduct() const{
	cout << setw(13) << GTIN << " * " << left << setw(20) << name << " * ";
	cout << setprecision(2) << wholesale << " * " << description << endl;
	return;
}//end of showProduct

