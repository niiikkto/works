#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Product {
protected:
	string title;
	int id;

public:
	Product(const string& title, int id) : title(title), id(id) {}

	string getTitle() const { return title; }
	int getId() const { return id; }

	// Для сравнения продуктов
	bool operator==(const Product& other) const {
		return id == other.id;
	}
};