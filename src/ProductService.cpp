#include "ProductService.hpp"
#include <iomanip>
#include <iostream>


void ProductService::addProduct(const Product& product) {
    products.push_back(product);
    std::cout << "Product added successfully!" << std::endl;
}

void ProductService::getAllProduct() const {
    std::cout << "============= | All Products | =============" << std::endl << std::endl;
    std::cout << std::left
            << std::setw(6) << "ID"
            << std::setw(25) << "Name"
            << std::setw(15) << "Price"
            << std::setw(10) << "Qty" << std::endl;
    for (const auto& p : products) {
        std::cout << std::left
            << std::setw(6) << p.getId()
            << std::setw(25) << p.getName()
            << std::setw(15) << p.getPrice()
            << std::setw(10) << p.getQty() << std::endl;
    }
    std::cout << "============================================" << std::endl << std::endl;
}

void ProductService::getProductById(int id) const {
    std::cout << "============= | Product Details | =============" << std::endl << std::endl;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            std::cout << "Product id    : " << it->getId() << std::endl;
            std::cout << "Product name  : " << it->getName() << std::endl;
            std::cout << "Product price : " << it->getPrice() << std::endl;
            std::cout << "Product qty   : " << it->getQty() << std::endl;
        }
    }
    std::cout << "===============================================" << std::endl << std::endl;
}

void ProductService::deleteProductById(int id) {
    std::cout << "=============== | DELETE PRODUCT | ==============" << std::endl << std::endl;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            break;
        }
    }
    std::cout << "Product deleted successfully!" << std::endl << std::endl;
}

void ProductService::updateProductById(int id, const std::string& name, double price, int qty) {
    std::cout << "============== | UPDATE PRODUCT | ==============" << std::endl << std::endl;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            it->setName(name);
            it->setPrice(price);
            it->setQty(qty);
        }
    }
    std::cout << "Product updated successfully!" << std::endl << std::endl;
}

bool ProductService::existsById(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            return true;
            break;
        }
    }
    return false;
}
