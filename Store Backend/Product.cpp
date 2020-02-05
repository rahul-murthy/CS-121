#include <iostream>
#include <string>
#include <stdexcept>
#include "Product.h"

using namespace std;

Product::Product(int id, string name) : id(id), name(name), inventory(0), numSold(0), totalPaid(0.0) {
    if (name.length()==0) 
        throw runtime_error("Product name cannot be empty.");
}

int Product::getID() const{ 
    return id; 
}

string Product::getName() const{ 
    return name; 
}

void Product::setName(string name) {
	if (name.length()==0) {
		throw runtime_error("Product name cannot be empty.");
    }
	this->name = name; // could use an else, but it will only get here
					   //   if there was not an exception!
}

string Product::getDescription() const { 
    return description;
}

void Product::setDescription(string description){
	this->description = description;
}

int Product::getNumberSold() const { return numSold; }

double Product::getTotalPaid() const { return totalPaid; }

int Product::getInventoryCount() const { return inventory; }

void Product::addShipment(int shipmentquantity, double shipmentCost) {
	if (shipmentquantity < 0)
		throw runtime_error("Shipment quantity must be positive.");
	if (shipmentCost < 0)
		throw runtime_error("Shipment cost must be positive.");
	//cout << "quantity: " << quantity << endl;
	//cout << "inventory: " << inventory << endl;
	inventory += shipmentquantity;
	totalPaid += shipmentCost;
}

void Product::reduceInventory(int purchaseQuantity) {
    if (purchaseQuantity < 0) {
        throw runtime_error("purchaseQuantity is negative");
    }
    if (purchaseQuantity > inventory) {
        throw runtime_error("Not enough inventory");
    }
    inventory -= purchaseQuantity;
    numSold += purchaseQuantity;

}

double Product::getPrice() const {
    if ((static_cast<double>(inventory + numSold)) == 0) {
        throw runtime_error("Shipment quantity must be positive.");
    }
    double price = (totalPaid / (static_cast<double>(inventory + numSold))) * 1.25;
    if (price < 0) {
		throw runtime_error("Shipment quantity must be positive.");
    }
	return price;
}

ostream& operator<<(std::ostream& ss, const Product& c){
    ss << "Product Name: " << c.getName() << endl;
    ss << "Product ID: " << c.getID() << endl;
    ss << "Description: " << c.getDescription() << endl;
    ss << "Inventory: " << c.getInventoryCount() << endl;
    ss << "Number Sold: " << c.getNumberSold() << endl;
    ss << "Total Paid: " << c.getTotalPaid() << endl;
    //bool prices = true;
    try {
        c.getPrice();
    }
    catch (runtime_error& exc){
        ss << "Price: Unavailable" << endl;
        return ss;
        //prices = false;
    }
    ss << "Price: " << c.getPrice() << endl;

    return ss;
}