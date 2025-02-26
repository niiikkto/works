#include "Shop.h"
#include <algorithm>

Shop::Shop(const std::string& name) : name(name) {}

void Shop::addProduct(const Product& product, double price, int quantity) {
    products.push_back(ProductInfo(product, price, quantity));
}

void Shop::removeProduct(const std::string& name) {
    products.erase(
        std::remove_if(products.begin(), products.end(),
            [&name](const ProductInfo& p) { return p.getProduct().getTitle() == name; }),
        products.end()
    );
}

ProductInfo* Shop::findProduct(int productId) {
    auto it = std::find_if(products.begin(), products.end(),
        [productId](const ProductInfo& info) {
            return info.getProduct().getId() == productId;
        });
    return it != products.end() ? &(*it) : nullptr;
}

bool Shop::processPurchase(Buyer& buyer, int productId, int quantity) {
    ProductInfo* productInfo = findProduct(productId);
    if (!productInfo) return false;
    
    double totalCost = productInfo->getPrice() * quantity;
    if (!buyer.pay(totalCost)) return false;
    
    return productInfo->decreaseQuantity(quantity);
}

const std::vector<ProductInfo>& Shop::getProducts() const {
    return products;
} 