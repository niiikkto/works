#include "ShopManager.h"
#include "Shop.h"
#include "Product.h"
#include "ProductInfo.h"
#include "Buyer.h"

int main() {
    try {
        // Создаем менеджер магазинов
        ShopManager manager;

        // Создаем продукты
        Product milk("Milk", 1);
        Product bread("Bread", 2);

        // Создаем магазины
        Shop shop1("Grocery");
        shop1.addProduct(milk, 2.5, 10);
        shop1.addProduct(bread, 1.5, 20);

        Shop shop2("Supermarket");
        shop2.addProduct(milk, 2.3, 15);
        shop2.addProduct(bread, 1.7, 25);

        manager.addShop(shop1);
        manager.addShop(shop2);

        // Создаем покупателя
        Buyer buyer("John");
        buyer.addToBalance(100.0);

        // Находим самый дешевый магазин для молока
        Shop* cheapestShop = manager.findCheapestShop(milk.getId());
        if (cheapestShop) {
            cout << "Cheapest shop for milk: " << cheapestShop->getName() << endl;

            // Совершаем покупку
            if (manager.processPurchase(buyer, milk.getId(), 1, *cheapestShop)) {
                cout << "Successfully bought milk" << endl;
                cout << "Remaining balance: " << buyer.getBalance() << endl;
            }
            else {
                cout << "Failed to buy milk" << endl;
            }
        }

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}