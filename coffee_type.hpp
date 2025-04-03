#pragma once
#include <iostream>
using namespace std;


class CoffeeType {
public:
    double coffee_powder;
    double total_amount;
    string size;
    int size_factor;


    virtual ~CoffeeType() = default;  

    virtual void setWhiteSugar(double sugarAdded) = 0; 
    virtual double getWhiteSugar() const = 0;      
    virtual void setBrownSugar(double sugarAdded) = 0; 
    virtual double getBrownSugar() const = 0;      
    virtual void setMixSugar(double sugarAdded) = 0; 
    virtual double getMixSugar() const = 0;    

    virtual void setFullCreamMilk(double milkAdded) = 0; 
    virtual double getFullCreamMilk() const = 0;      
    virtual void setAlmondMilk(double milkAdded) = 0; 
    virtual double getAlmondMilk() const = 0;      
    virtual void setCoconutMilk(double milkAdded) = 0; 
    virtual double getCoconutMilk() const = 0;      
  

    virtual void setChocolate(double flavourAdded) = 0; 
    virtual double getChocolate() const = 0;      
    virtual void setCaramel(double flavourAdded) = 0; 
    virtual double getCaramel() const = 0;    
    virtual void setMatcha(double flavourAdded) = 0; 
    virtual double getMatcha() const = 0;    






    virtual void bill() = 0;  // Pure virtual function to make it an abstract class
};