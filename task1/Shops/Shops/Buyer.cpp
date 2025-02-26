#include "Buyer.h"
#include <algorithm>

Buyer::Buyer(const std::string& name, double initialBalance)
    : name(name), balance(initialBalance) {}

void Buyer::addToCart(const Product& product) {
    cart.push_back(product);
}

void Buyer::removeFromCart(const std::string& productName) {
    cart.erase(
        std::remove_if(cart.begin(), cart.end(),
            [&productName](const Product& p) { return p.getName() == productName; }),
        cart.end()
    );
}

double Buyer::getTotal() const {
    double total = 0.0;
    for (const auto& product : cart) {
        total += product.getPrice() * product.getQuantity();
    }
    return total;
}

bool Buyer::checkout() {
    double total = getTotal();
    if (total <= balance) {
        balance -= total;
        cart.clear();
        return true;
    }
    return false;
}

std::string Buyer::getName() const {
    return name;
}

double Buyer::getBalance() const {
    return balance;
}

void Buyer::setBalance(double balance) {
    this->balance = balance;
}

const std::vector<Product>& Buyer::getCart() const {
    return cart;
}

void Buyer::addToBalance(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool Buyer::pay(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void Buyer::addToShoppingList(const Product& product) {
    shoppingList.push_back(product);
} 