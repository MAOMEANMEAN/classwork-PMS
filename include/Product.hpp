#pragma once
#include <string>

class Product {
    private:
        int id;
        std::string name;
        double price;
        int qty;
    public:
        Product(); //default constructor
        Product(int id, const std::string& name, double price, int qty); //parameterize constructor

        int getId() const;
        std::string getName() const;
        double getPrice() const;
        int getQty() const;

        void setName(const std::string& name);
        void setPrice(double price);
        void setQty(int qty);
};