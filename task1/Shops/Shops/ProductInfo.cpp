#include "ProductInfo.h"

ProductInfo::ProductInfo(const Product& product, double price, int quantity) {
    if (price < 0 || quantity < 0) {
        throw std::invalid_argument("Price and quantity must be non-negative");
    }
    this->product = product;
    this->price = price;
    this->quantity = quantity;
}

bool ProductInfo::decreaseQuantity(int amount) {
    if (amount < 0 || quantity < amount) return false;
    quantity -= amount;
    return true;
} 