#pragma once
#include <iostream>
using namespace std;
#include "coffee_hot_cold.hpp"

class Cappuccino : public CoffeeType {
public:
    double white_sugar, brown_sugar, mix_sugar;
    double full_cream_milk, almond_milk, coconut_milk;
    double chocolate, caramel, matcha;
    

    Cappuccino();


    void setWhiteSugar(double sugarAdded) override;
    double getWhiteSugar() const override;
    void setBrownSugar(double sugarAdded) override; 
    double getBrownSugar() const override;      
    void setMixSugar(double sugarAdded) override; 
    double getMixSugar() const override;    

    void setFullCreamMilk(double milkAdded) override; 
    double getFullCreamMilk() const override;      
    void setAlmondMilk(double milkAdded) override; 
    double getAlmondMilk() const override;      
    void setCoconutMilk(double milkAdded) override; 
    double getCoconutMilk() const override;      
  
    void setChocolate(double flavourAdded) override; 
    double getChocolate() const override;      
    void setCaramel(double flavourAdded) override; 
    double getCaramel() const override;    
    void setMatcha(double flavourAdded) override; 
    double getMatcha() const override;   

    void bill() override;
};