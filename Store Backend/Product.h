#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

// note cannot have a "using namespace std;" statement in header file

class Product {
	
public:
    Product(int productID, std::string productName);
    int getID() const;
    std::string getName() const;
    void setName(std::string newName);
    std::string getDescription() const;
    void setDescription(std::string description);
    int getNumberSold() const;
    double getTotalPaid() const;
    int getInventoryCount() const;
    void addShipment(int shipmentQuantity, double shipmentCost);
    void reduceInventory(int purchaseQuantity);
    double getPrice() const;
    
private:
    int id;
	std::string name;
	std::string description;
	int inventory;
	int numSold;
	double totalPaid;
};

std::ostream& operator<<(std::ostream&, const Product&);

#endif