#pragma once
#include <iostream>
using namespace std;
#include "coffee_hot_cold.hpp"



class Dalgona : public CoffeeType {
public:
    

    Dalgona();

    void add_sugar(double amount);

    void add_milk(double amount);

    void add_toppings(double amount);

    void bill() override;
};