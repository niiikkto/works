#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "product.h"

using namespace std;
class Product {};

class Buyer {
private:
	string name;
	double balance;
	vector<Product> shoppingList;

public:
	Buyer(const string& name, double initialBalance = 0.0)
		: name(name), balance(initialBalance) {}

	string getName() const { return name; }
	double getBalance() const { return balance; }

	void addToBalance(double amount) {
		if (amount > 0) {
			balance += amount;
		}
	}

	bool pay(double amount) {
		if (balance >= amount) {
			balance -= amount;
			return true;
		}
		return false;
	}

	void addToShoppingList(const Product& product) {
		shoppingList.push_back(product);
	}

	const vector<Product>& getShoppingList() const { return shoppingList; }
};