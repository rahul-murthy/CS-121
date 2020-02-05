#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <string>

#include "Product.h"

class Customer {

public:
    
    Customer(int, std::string, bool credit = false);
    std::string to_str();
    int getID() const;
    std::string getName() const;
    void setName(std::string);
    bool getCredit() const;
    void setCredit(bool);
    double getBalance() const;
    void processPayment(double);
    void processPurchase(double, Product);
    std::string getProductsPurchased() const;

private:

    int id;
    std::string name;
    bool credit;
    double balance;
    std::vector <Product> productsPurchased;

};

std::ostream& operator<<(std::ostream&, const Customer&);

#endif