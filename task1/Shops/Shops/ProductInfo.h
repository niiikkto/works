#pragma once
#include "product.h"

class ProductInfo {
private:
	Product product;
	double price;
	int quantity;

public:
	ProductInfo(const Product& product, double price, int quantity)
		: product(product), price(price), quantity(quantity) {}

	const Product& getProduct() const { return product; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }

	void setPrice(double newPrice) { price = newPrice; }
	void setQuantity(int newQuantity) { quantity = newQuantity; }

	bool decreaseQuantity(int amount) {
		if (quantity >= amount) {
			quantity -= amount;
			return true;
		}
		return false;
	}
};