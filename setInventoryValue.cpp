#include<iostream>
#include "ingredients.hpp"
 


void setInventoryValue(Ingredients& ingred){
 int val;
    //fetch stock values of inventory from inventory record csv file and set them for the current session
    val = ingred.getInventoryValue("inventory.csv", "coffee_powder");
    ingred.coffee_powder = val;
    val = ingred.getInventoryValue("inventory.csv", "full_cream_milk");
    ingred.full_cream_milk = val;
    val = ingred.getInventoryValue("inventory.csv", "almond_milk");
    ingred.almond_milk = val;
    val = ingred.getInventoryValue("inventory.csv", "coconut_milk");
    ingred.coconut_milk = val;
    val = ingred.getInventoryValue("inventory.csv", "white_sugar");
    ingred.white_sugar = val;
    val = ingred.getInventoryValue("inventory.csv", "brown_sugar");
    ingred.brown_sugar = val;
    val = ingred.getInventoryValue("inventory.csv", "mix_sugar");
    ingred.mix_sugar = val;
    val = ingred.getInventoryValue("inventory.csv", "chocolate_flavour");
    ingred.chocolate_flavour = val;
    val = ingred.getInventoryValue("inventory.csv", "caramel_flavour");
    ingred.caramel_flavour = val;
    val = ingred.getInventoryValue("inventory.csv", "matcha_flavour");
    ingred.matcha_flavour = val;
    val = ingred.getInventoryValue("inventory.csv", "largecups");
    ingred.largecups = val;
    val = ingred.getInventoryValue("inventory.csv", "mediumcups");
    ingred.mediumcups = val;
    val = ingred.getInventoryValue("inventory.csv", "smallcups");
    ingred.smallcups = val;
}