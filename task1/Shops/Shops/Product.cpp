#include "Product.h"

Product::Product(int id, const std::string& title, double price, int quantity)
    : id(id), title(title), price(price), quantity(quantity) {}

std::string Product::getName() const {
    return title;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setName(const std::string& name) {
    this->title = name;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
} 