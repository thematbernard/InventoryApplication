#include <string>
#include <array>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Product.h"
#include "InventoryItem.h"


   //constructors
	//with paramaters
	InventoryItem::InventoryItem(Product *p, double ret, int quant):prod(p),
	retail(ret), quantity(quant){};
	//without paramters
	InventoryItem::InventoryItem(){};
	//destructor
	InventoryItem::~InventoryItem(){};

       //setter functions
      void InventoryItem::setProduct(Product *p){
			this->prod = p;
		}//end of setProduct
		void InventoryItem::setRetail(double retail){
          this->retail = retail;
       }//end of setRetail

      void InventoryItem::setQuantity(int quantity){
          this->quantity = quantity;
       }//end of setQuantity

		void InventoryItem::setGTIN(string &GTIN){
			prod->setGTIN(GTIN);
		}//end of setGTIN
		void InventoryItem::setName(string &name){
			prod->setName(name);
		}//end of setName
		void InventoryItem::setWholesale(float wholesale){
			prod->setWholesale(wholesale);
		}//end of setWholesale
		void InventoryItem::setDescription(string &desc){
			prod->setDescription(desc);
		}//end of setDescription


       //getter functions
      Product* InventoryItem::getProduct() const{
			return prod;
		}//end get Product

		double InventoryItem::getRetail() const{
          return retail;
       }//end getRetail

       int InventoryItem::getQuantity() const{
          return quantity;
       }//end getQuantity
		
		string InventoryItem::getGTIN() const{
			return prod->getGTIN();
		}
		string InventoryItem::getName() const{
			return prod->getName();
		}
		float InventoryItem::getWholesale() const{
			return prod->getWholesale();
		}
		string InventoryItem::getDescription() const{
			return prod->getDescription();
		}

		//other member functions
		void InventoryItem::showItem() const{
			cout << prod->getGTIN() << " * " << prod->getName() << " * " << left << 
			prod->getDescription() << " * " << setprecision(3) << retail << " * " << 
			prod->getWholesale() << " * " << quantity << " * " <<  endl;
				return;
		}

		bool InventoryItem::loadItem(ifstream &fileName){
			
			string GTIN;
			string name;
			float wholesale;
			double retail;
			string desc;
			double quantity;
			bool isGood = fileName.good();

				if(isGood = true){
				
				fileName >> GTIN >> quoted(name) >> wholesale >> retail >> quoted(desc) >> quantity;

				//Make Product object pointer and allocate memory
				Product *newProd = new Product(GTIN, name, wholesale, desc);
				
				//hook the Product object to InventoryItem with the setProduct function
				setProduct(newProd);
				setRetail(retail);
				setQuantity(quantity);
				}
				else{
					exit(EXIT_FAILURE);
				}
			
			return true;
		
		}//end of loadItem
		
		bool InventoryItem::readItem(){

			string GTIN;
			string name;
			float wholesale;
			double retail;
			string desc;
			double quantity;
			Product *newProd = new Product();

			cout << "Enter GTIN for your item: ";
			cin >> GTIN;
			cout << "Enter the item name: ";
			cin >> quoted(name);
			cout << "Enter the wholesale price of your item: ";
			cin >> wholesale;
			cout << "Enter the retail price of your item: ";
			cin >> retail;
			cout << "Enter a description for your item with: ";
			cin >> quoted(desc);
			cout << "What is the quanitity of your item: ";
			cin >> quantity;

			if(cin.good()){
			setProduct(newProd);
			setGTIN(GTIN);
			setName(name);
			setWholesale(wholesale);
			setRetail(retail);
			setDescription(desc);
			setQuantity(quantity);
			}
			else{
				exit(EXIT_FAILURE);
			}
			return(true);

		}//end readItem


		void InventoryItem::edit(){

			string GTIN;
			string name;
			float wholesale;
			double retail;
			string desc;
			double quantity;
			int fieldIndex;

			cout << "1 - GTIN: " << getGTIN() << endl;
			cout << "2 - Name: " << getName() << endl;
			cout << "3 - Quantity: " << getQuantity() << endl;
			cout << "4 - Wholesale: " << getWholesale() << endl;
			cout << "5 - Retail: " << getRetail() << endl;
			cout << "6 - Description: " << getDescription() << endl;
			cout << "Enter the number for field to update: ";
			cin >> fieldIndex;

			switch(fieldIndex){
				case 1:	cout << "Please enter a new GTIN: " << endl;
							cin >> GTIN;
							setGTIN(GTIN);
							break;
				case 2:	cout << "Please enter a new Name: " << endl;
							cin >> quoted(name);
							setName(name);
							break;
				case 3:	cout << "Please enter a new Quantity: " << endl;
							cin >> quantity;
							setQuantity(quantity);
							break;
				case 4:	cout << "Please enter a new Wholesale Price: " << endl;
							cin >> wholesale;
							setWholesale(wholesale);
							break;
				case 5:	cout << "Please enter a new Retail Price: " << endl;
							cin >> retail;
							setRetail(retail);
							break;
				case 6:	cout << "Please enter a new Description: " << endl;
							cin >> quoted(desc);
							setDescription(desc);
							break;
				default:	cout << "Invlaid choice returned from menu" << endl;
			}//end switch statement

		}//end of edit

		void InventoryItem::saveItem(ofstream &fileName){
			
			fileName << getGTIN() << " " << quoted(getName()) << " " << getWholesale() 
			<< " " << getRetail() << " " << quoted(getDescription()) << " " << 
			getQuantity() << endl;

		}//end of saveItem
