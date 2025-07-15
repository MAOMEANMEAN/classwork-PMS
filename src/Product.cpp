#include "Product.hpp"

Product::Product() {}

Product::Product(int id, const std::string& name, double price, int qty) : id(id), name(name), price(price), qty(qty) {}

//getter
int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQty() const {
    return qty;
}

//setter
void Product::setName(const std::string& name) {
    this->name = name;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setQty(int qty) {
    this->qty = qty;
}

