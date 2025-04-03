#pragma once
#include <iostream>
using namespace std;

class Ingredients {
public:
    int coffee_powder, full_cream_milk, almond_milk, coconut_milk, white_sugar, brown_sugar, mix_sugar, chocolate_flavour, caramel_flavour, matcha_flavour, largecups, mediumcups, smallcups;

    Ingredients();
    void deduct_whiteSugar(int sugarAdded);
    void deduct_brownSugar(int sugarAdded);
    void deduct_mixSugar(int sugarAdded);
    void deduct_full_cream_milk(int milkAdded);
    void deduct_almondMilk(int milkAdded);
    void deduct_coconutMilk(int milkAdded);
    void deduct_chocolate(int flavourAdded);
    void deduct_caramel(int flavourAdded);
    void deduct_matcha(int flavourAdded);
    void deduct_cups(int size);
    void updateInventory(const std::string& file_name, const std::string& ingredient_name, int amount_remaining);
    int getInventoryValue(const std::string& file_name, const std::string& ingredient_name);
};