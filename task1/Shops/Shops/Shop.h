#pragma once
#include <iostream>
#include <vector>
#include "ProductInfo.h"

using namespace std;

class Shop {
private:
	string name;
	vector<ProductInfo> products;

public:
	Shop(const string& name) : name(name) {}

	string getName() const { return name; }

	void addProduct(const Product& product, double price, int quantity) {
		products.push_back(ProductInfo(product, price, quantity));
	}

	ProductInfo* findProduct(int productId) {
		for (auto& productInfo : products) {
			if (productInfo.getProduct().getId() == productId) {
				return &productInfo;
			}
		}
		return nullptr;
	}

	bool sellProduct(int productId, int quantity) {
		ProductInfo* productInfo = findProduct(productId);
		if (productInfo && productInfo->decreaseQuantity(quantity)) {
			return true;
		}
		return false;
	}

	const vector<ProductInfo>& getProducts() const { return products; }
};