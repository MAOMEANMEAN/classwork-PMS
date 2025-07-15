#include <iostream>
#include "Product.hpp"
#include "ProductService.hpp"
using namespace std;

void menu() {
    cout << "================= | Menu | =================" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. Get All Product" << endl;
    cout << "3. Get Product By Id" << endl;
    cout << "4. Delete Product" << endl;
    cout << "5. Update Product" << endl;
    cout << "0. Exit" << endl;
    cout << "============================================" << endl;
}

ProductService productService;

int main() {

    system("cls");

    int op;
    do {
        menu();
        cout << "Enter an option : "; cin >> op;
        system("cls");
        if (op == 0) {
            cout << "Exiting..." << endl;
            return 0;
        }

        switch(op) {
            case 1: {
                system("cls");
                string name;
                int qty, id;
                double price;
                cout << "============= | Add Product | =============" << endl;
                cout << "Enter product id    : "; cin >> id;
                if (productService.existsById(id)) {
                    cout << "Product with id : " << id << " already exists." << endl;
                    break;
                }
                cout << "Enter product name  : "; cin >> name;
                cout << "Enter product price : "; cin >> price;
                cout << "Enter product qty   : "; cin >> qty;

                Product product(id, name, price, qty);
                productService.addProduct(product);
                break;
            }
            case 2: {
                system("cls");
                productService.getAllProduct();
                break;
            }
            case 3: {
                system("cls");
                int id;
                cout << "Enter product id    : "; cin >> id;
                productService.getProductById(id);
                break;
            }
            case 4: {
                system("cls");
                int id;
                cout << "Enter product id : "; cin >> id;
                if (!productService.existsById(id)) {
                    cout << "Product with id : " << id << " does not exit" << endl;
                    break;
                }
                productService.deleteProductById(id);
                break;
            }
            case 5: {
                system("cls");
                int id, qty;
                string name;
                double price;
                cout << "Enter product id to update : "; cin >> id;
                if (!productService.existsById(id)) {
                    cout << "Product with id : " << id << " does not exit" << endl;
                    break;
                }
                cout << "Enter new name : "; cin >> name;
                cout << "Enter new price : "; cin >> price;
                cout << "Enter new qty : "; cin >> qty;
                productService.updateProductById(id, name, price, qty);
                break;
            }
            default: {
                cout << "Invalid option, please try again!!!" << endl;
            }
        }
    }while(op != 0);


    return 0;
}