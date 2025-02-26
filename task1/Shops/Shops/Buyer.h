#pragma once
#include <string>
#include <vector>
#include "Product.h"

class Buyer {
private:
	std::string name;
	double balance;
	std::vector<Product> shoppingList;

public:
	Buyer(const std::string& name, double initialBalance = 0.0);
	
	std::string getName() const { return name; }
	double getBalance() const { return balance; }
	
	void addToBalance(double amount);
	bool pay(double amount);
	void addToShoppingList(const Product& product);
	const std::vector<Product>& getShoppingList() const { return shoppingList; }
};