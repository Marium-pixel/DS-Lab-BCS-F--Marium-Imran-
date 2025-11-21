/* Task-4:
Imagine you are working for a company that provides an online shopping platform. There are only 3
products listed on the platform, and customers often search for products based on their price. Write a
program in C++ that uses Quick sort to sort the products based on their price in ascending order.
Define a class for each product that will store its name, price, description, and availability?
 */
#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    float price;
    string description;
    bool available;
};

void swap(Product &a, Product &b) {
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;  
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Product products[3];

    products[0] = {"Laptop", 85000, "Gaming Laptop", true};
    products[1] = {"Headphones", 3500, "Wireless Headphones", true};
    products[2] = {"Keyboard", 2200, "Mechanical Keyboard", true};

    quickSort(products, 0, 2);

    cout << "Products sorted by price:\n";
    for (int i = 0; i < 3; i++) {
        cout << products[i].name << " - Rs." << products[i].price << endl;
    }
}
