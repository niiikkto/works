#include <iostream>
#include "ShopManager.h"
#include "Shop.h"
#include "Product.h"
#include "ProductInfo.h"
#include "Buyer.h"

int main() {
    try {
        ShopManager manager;

        // Создаем магазины
        Shop shop1("Продукты");
        Shop shop2("Супермаркет");

        // Создаем продукты
        Product milk(1, "Молоко", 80.0, 50);
        Product bread(2, "Хлеб", 50.0, 100);
        Product cheese(3, "Сыр", 300.0, 30);

        // Добавляем продукты в магазины
        shop1.addProduct(milk, 80.0, 50);
        shop1.addProduct(bread, 50.0, 100);
        shop2.addProduct(milk, 85.0, 40);
        shop2.addProduct(cheese, 320.0, 25);

        manager.addShop(shop1);
        manager.addShop(shop2);

        // Создаем покупателя
        Buyer buyer("Иван", 1000.0);

        // Ищем самый дешевый магазин для молока
        if (Shop* cheapestShop = manager.findCheapestShop(milk.getId())) {
            std::cout << "Самый дешевый магазин для молока: " << cheapestShop->getName() << std::endl;

            // Получаем информацию о товаре
            if (ProductInfo* productInfo = cheapestShop->findProduct(milk.getId())) {
                double cost = productInfo->getPrice() * 2; // цена за 2 единицы
                if (buyer.pay(cost) && cheapestShop->sellProduct(milk.getId(), 2)) {
                    std::cout << "Покупка успешно совершена!" << std::endl;
                    std::cout << "Остаток на счете: " << buyer.getBalance() << " руб." << std::endl;
                } else {
                    std::cout << "Ошибка при совершении покупки." << std::endl;
                }
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}