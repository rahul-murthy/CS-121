#include <iostream>
#include <string>
#include <stdexcept>
#include "Store.h"
#include <sstream>

using namespace std;

    Store::Store() {}

    Store::Store(string name) : name(name) {
        //name can't be blank
        if (name.length()==0) {
            throw runtime_error("Store name cannot be empty.");
        }
    }

    string Store::getName() const { 
        return name; 
    }

    void Store::setName(string name) {
        this->name = name;
    }

    void Store::addProduct(int ProductID, string productName) {
        //checks if a product is already in vector
        for (int i = 0; i < products.size(); ++i) {
            if (products.at(i).getID() == ProductID) {
                throw runtime_error("productID already belongs to another product");
            }
        }
        //adds products to vector
        Product newProduct(ProductID, productName);
        this->products.push_back(newProduct);
    }

    Product& Store::getProduct(int ProductID) {
        //matches id and returns
        bool notfound = true;
        for (int i = 0; i < products.size(); ++i) {
            if (ProductID == products.at(i).getID()) {
                notfound = false;
                return products.at(i);
            }
        }
        //if it did not go into the loop and change the value of notfound
        if (notfound == true) {
            throw runtime_error("not found");
        }
    }

    void Store::addCustomer(int customerID, string customerName, bool credit) {

        //checks for exisiting customerID
        for (int i = 0; i < customers.size(); ++i) {
            if (customerID == customers.at(i).getID()) {
                throw runtime_error("customerID already belongs to another customer");
            }
        }
        
        Customer newCustomer(customerID, customerName, credit);
        this->customers.push_back(newCustomer);

    }

    Customer& Store::getCustomer(int customerID) {
        //matches id and returns
        bool notfound = true;
        for (int i = 0; i < customers.size(); ++i) {
            if (customerID == customers.at(i).getID()) {
                notfound = false;
                return customers.at(i);
            }
        }
        //if it did not go into the loop and change the value of notfound
        if (notfound == true) {
            throw runtime_error("customer does not exist");
        }
    }
    

    void Store::takeShipment(int ProductID, int quantity, double cost) {
        //matches id and returns
        bool notfound = true;
        for (int i = 0; i < products.size(); ++i) {
            if (ProductID == products.at(i).getID()) {
                notfound = false;
                products.at(i).addShipment(quantity, cost);
            }
        }
        // mimir error checking
        if ((quantity < 0) || (cost < 0)) {
            throw runtime_error("error");
        }
        //if it did not go into the loop and change the value of notfound
        if (notfound == true) {
            throw runtime_error("Product is not in list of products");
        }
    }

    void Store::takePayment(int customerID, double amount) {
        //matches id and returns
        bool notfound = true;
        for (int i = 0; i < customers.size(); ++i) {
            if (customerID == customers.at(i).getID()) {
                notfound = false;
                customers.at(i).processPayment(amount);
            }
        }
        if (amount < 0) {
            throw runtime_error("amount is negative");
        }
        //if it did not go into the loop and change the value of notfound
        if (notfound == true) {
            throw runtime_error("customer does not exist");
        }
    }

    void Store::sellProduct(int customerID, int ProductID, int quantity) {
        //if these functions do not give a run time error then the sale happens
        //if ((reduceInventory(quantity) != runtime_error) || (processPurchase(getProduct(ProductID).getPrice() * quantity, getProduct(ProductID))) != runtime_error) {
            //getProduct(ProductID).reduceInventory(quantity);
            //getCustomer(customerID).processPurchase(getProduct(ProductID).getPrice() * quantity, getProduct(ProductID));
        //}
        //getCustomer(int customerID)
        //processPurchase(double, Product)
        //getProduct(int productID)
        getCustomer(customerID).processPurchase((getProduct(ProductID).getPrice() * quantity),getProduct(ProductID));
        
        //getProduct(int ProductID)
        //reduceInventory(int purchaseQuantity)
        getProduct(ProductID).reduceInventory(quantity);
    }

    string Store::listProducts() {
        stringstream cc;
        
        
        
        for (int i = 0; i < products.size(); ++i) {
            cc << products.at(i) << endl;
        }
        return cc.str();
        //Product Name: Coozie
        //Product ID: 32498
        //Description: A great way to keep a canned beverage cold.
        //Inventory: 83
        //Number Sold: 107
        //Total Paid: 2850
        //Price: 18.75
    }    

    string Store::listCustomers() {
        stringstream cc;
        for (int i = 0; i < customers.size(); ++i) {
            cc << customers.at(i) << endl;
        }
        return cc.str();
        //Customer Name: Miss Reveille
        //Customer ID: 2198123
        //Has Credit: true
        //Balance: -228.33
        //Products purchased -- 

        //Product Name: Coozie
        //Product ID: 32498

        //Product Name: 12th Man Towel
        //Product ID: 121212
    }