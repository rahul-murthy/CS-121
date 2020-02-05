#include <sstream>
#include <ostream>
#include "Customer.h"

using namespace std;

Customer::Customer(int customerID, std::string name, bool credit) : id(customerID), name(name), credit(credit), balance(0.0) {
    //name can't be blank
    if (name.length()==0) {
        throw runtime_error("Customer name cannot be empty.");
    }
}

int Customer::getID() const{ 
    return id; 
}

string Customer::getName() const{ 
    return name; 
}

void Customer::setName(string name)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
    this-> name = name;
}

bool Customer::getCredit() const{
    return credit;
}

void Customer::setCredit(bool hasCredit) {
    this->credit = hasCredit;
}

double Customer::getBalance() const{
    return balance;
}

void Customer::processPayment(double amount) {
    //amount can not be less than 0
    if(amount < 0) {
        throw runtime_error("Amount is negative");
    }
    
    else {
        this->balance += amount;
    }
}

void Customer::processPurchase(double amount, Product product) {
    //if credit is false then balance can't go below 0
    if (credit == false && balance < 0) {
        throw runtime_error("Balance is not allowed to be negative if credit is false");
    }
    //but if credit is true then you can have a begative balance
    else if (credit == true) {
        balance -= amount;
    }
    else if (balance >= amount) {
        balance -= amount;
        this -> productsPurchased.push_back(product);
    }
    else {
        throw runtime_error("Error");
    }
    
    bool j = true;
    for (int i = 0; i < productsPurchased.size(); ++i) {
        if(productsPurchased.at(i).getID() == product.getID()){
            j = false;
        }
    }
    //if j was never changed in the loop then 
    if (j == true) {    //product was not in projectsPurcased so push back
        productsPurchased.push_back(product);
    }
    
    if(amount < 0) {
        throw runtime_error("amount is less than 0");
    }
    
}

std::string Customer::getProductsPurchased() const {
    //put in a string stream
    ostringstream bb;
    if (productsPurchased.size() == 0) {
        return bb.str();
    }
    for (int i = 0; i < productsPurchased.size(); ++i) {
        bb << "Product Name: ";
        bb << productsPurchased.at(i).getName() << endl;
        bb << "Product ID: ";
        bb << productsPurchased.at(i).getID() << endl << endl;
    }
    return bb.str();
}

ostream& operator<<(std::ostream& bb, const Customer& b){
    bb << "Customer Name: " << b.getName() << endl;
    bb << "Customer ID: " << b.getID() << endl;
    if (b.getCredit())
        bb << "Has Credit: true" << endl;
    else {
        bb << "Has Credit: false" << endl;
    }
    bb << "Balance: " << b.getBalance() << endl;
    bb << "Products Purchased --" << endl << endl;
    bb << b.getProductsPurchased();
    return bb;
}