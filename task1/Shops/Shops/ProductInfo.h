#pragma once
#include "Product.h"

class ProductInfo {
private:
	Product product;
	double price;
	int quantity;

public:
	ProductInfo(const Product& product, double price, int quantity);

	const Product& getProduct() const { return product; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }

	bool setPrice(double newPrice) { 
		if (newPrice < 0) return false;
		price = newPrice;
		return true;
	}
	bool decreaseQuantity(int amount);
	bool increaseQuantity(int amount) { 
		if (amount < 0) return false;
		quantity += amount;
		return true;
	}
};