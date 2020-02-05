#ifndef STORE_H
#define STORE_H

#include <vector>
#include "Product.h"
#include "Customer.h"
#include <string>

// note cannot have a "using namespace std;" statement in header file

class Store {
	
public:
	Store();
    Store(std::string);
    std::string getName() const;
    void setName(std::string name);
    void addProduct(int productID, std::string productName);
    Product& getProduct(int productID);
    void addCustomer(int customerID, std::string customerName, bool credit = false);
    Customer& getCustomer(int customerID);
    void takeShipment(int productID, int quantity, double cost);
    void takePayment(int customerID, double amount);
    void sellProduct(int customerID, int productID, int quantity);
    std::string listProducts();
    std::string listCustomers();
    
private:
    int ProductID;
    std::string productName;
    int customerID;
    std::string customerName;
    bool credit;
    int quantity;
    double cost;
    double amount;
	std::string name;
    std::vector<Product> products;
    std::vector<Customer> customers;
};

#endif