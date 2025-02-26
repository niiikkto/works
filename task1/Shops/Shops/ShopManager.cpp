#include "ShopManager.h"
#include <algorithm>

void ShopManager::addBuyer(const Buyer& buyer) {
    buyers.push_back(buyer);
}

void ShopManager::removeBuyer(const std::string& name) {
    buyers.erase(
        std::remove_if(buyers.begin(), buyers.end(),
            [&name](const Buyer& b) { return b.getName() == name; }),
        buyers.end()
    );
}

Buyer* ShopManager::findBuyer(const std::string& name) {
    auto it = std::find_if(buyers.begin(), buyers.end(),
        [&name](const Buyer& b) { return b.getName() == name; });
    
    if (it != buyers.end()) {
        return &(*it);
    }
    return nullptr;
}

Shop& ShopManager::getShop() {
    return shop;
}

const std::vector<Buyer>& ShopManager::getBuyers() const {
    return buyers;
}

void ShopManager::addShop(const Shop& shop) {
    shops.push_back(shop);
}

Shop* ShopManager::findCheapestShop(int productId) {
    Shop* cheapestShop = nullptr;
    double lowestPrice = std::numeric_limits<double>::max();
    
    for (auto& shop : shops) {
        if (ProductInfo* info = shop.findProduct(productId)) {
            if (info->getQuantity() > 0 && info->getPrice() < lowestPrice) {
                lowestPrice = info->getPrice();
                cheapestShop = &shop;
            }
        }
    }
    return cheapestShop;
}

bool ShopManager::processPurchase(Buyer& buyer, int productId, int quantity, Shop& shop) {
    if (ProductInfo* info = shop.findProduct(productId)) {
        double totalCost = info->getPrice() * quantity;
        if (buyer.pay(totalCost)) {
            return shop.sellProduct(productId, quantity);
        }
    }
    return false;
} 