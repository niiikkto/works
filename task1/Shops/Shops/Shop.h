#pragma once
#include <string>
#include <vector>
#include "ProductInfo.h"

class Shop {
private:
    std::string name;
    std::vector<ProductInfo> products;

public:
    Shop(const std::string& name);
    std::string getName() const { return name; }

    void addProduct(const Product& product, double price, int quantity);
    void removeProduct(const std::string& name);
    ProductInfo* findProduct(int productId);
    bool sellProduct(int productId, int quantity);
    const std::vector<ProductInfo>& getProducts() const { return products; }
};