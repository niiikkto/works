#pragma once
#include <string>

class Product {
private:
	int id;
	std::string title;
	double price;
	int quantity;

public:
	Product(int id, const std::string& title, double price = 0.0, int quantity = 0)
		: id(id), title(title), price(price), quantity(quantity) {}
	
	int getId() const { return id; }
	std::string getTitle() const { return title; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }
	
	void setTitle(const std::string& title) { this->title = title; }
	void setPrice(double price) { this->price = price; }
	void setQuantity(int quantity) { this->quantity = quantity; }
	
	bool operator==(const Product& other) const {
		return id == other.id;
	}
};
