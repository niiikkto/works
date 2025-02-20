#pragma once
#include <iostream>
#include <vector>
#include "Shop.h"
#include "Buyer.h"

using namespace std;
class Shop {};

class ShopManager {
private:
	vector<Shop> shops;
	
public:
	void addShop(const Shop& shop) {
		shops.push_back(shop);
	}
	
	Shop* findCheapestShop(int productId) {
		Shop* cheapestShop = nullptr;
		double lowestPrice = numeric_limits<double>::max();
		
		for (auto& shop : shops) {
			ProductInfo* productInfo = shop.findProduct(productId);
			if (productInfo && productInfo->getQuantity() > 0) {
				if (productInfo->getPrice() < lowestPrice) {
					lowestPrice = productInfo->getPrice();
					cheapestShop = &shop;
				}
			}
		}
		return cheapestShop;
	}
	
	bool processPurchase(Buyer& buyer, int productId, int quantity, Shop& shop) {
		ProductInfo* productInfo = shop.findProduct(productId);
		if (!productInfo) return false;
		
		double totalCost = productInfo->getPrice() * quantity;
		if (!buyer.pay(totalCost)) return false;
		
		return shop.sellProduct(productId, quantity);
	}
};