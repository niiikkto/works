#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include "Shop.h"
#include "Buyer.h"

class ShopManager {
private:
	std::vector<Shop> shops;
	std::vector<Buyer> buyers;
	
public:
	void addShop(const Shop& shop) {
		shops.push_back(shop);
	}
	
	Shop* findCheapestShop(int productId);
	void addBuyer(const Buyer& buyer);
	void removeBuyer(const std::string& name);
	Buyer* findBuyer(const std::string& name);
	Shop& getShop() { return shops[0]; }
	const std::vector<Buyer>& getBuyers() const { return buyers; }
};