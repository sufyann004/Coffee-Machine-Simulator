#include "ingredients.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>


Ingredients::Ingredients(){    
}
// add conditions above to prevent negative inventory levels
void Ingredients::deduct_whiteSugar(int sugarAdded){white_sugar -= sugarAdded;}
void Ingredients::deduct_brownSugar(int sugarAdded){brown_sugar -= sugarAdded;}
void Ingredients::deduct_mixSugar(int sugarAdded){mix_sugar -= sugarAdded;}
void Ingredients::deduct_full_cream_milk(int milkAdded){full_cream_milk -= milkAdded;}
void Ingredients::deduct_almondMilk(int milkAdded){almond_milk -= milkAdded;}
void Ingredients::deduct_coconutMilk(int milkAdded){coconut_milk -= milkAdded;}
void Ingredients::deduct_chocolate(int flavourAdded){chocolate_flavour -= flavourAdded;}
void Ingredients::deduct_caramel(int flavourAdded){caramel_flavour -= flavourAdded;}
void Ingredients::deduct_matcha(int flavourAdded){matcha_flavour -= flavourAdded;}
void Ingredients::deduct_cups(int size){   
        switch(size){
            case 1: smallcups-=1;
            case 2: mediumcups-=1;
            case 3: largecups-=1;
        }
    }
        
    
    
    
    //this function updates csv file wali inventory levels
    
    void Ingredients::updateInventory(const std::string& file_name, const std::string& ingredient_name, int amount_remaining) {
    std::ifstream infile(file_name); 
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file " << file_name << " for reading.\n";
        return;
    }

    std::vector<std::pair<std::string, int>> inventory;
    std::string line, ingredient;
    int amount;
    bool ingredient_found = false;

    // Read the CSV file line by line
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string amount_str;

        // Parse the line into ingredient and amount
        if (std::getline(iss, ingredient, ',') && std::getline(iss, amount_str)) {
            try {
                amount = std::stoi(amount_str);
            } catch (...) {
                amount = 0; // Handle invalid numeric data
            }

            // Check if the current ingredient matches the one to update
            if (ingredient == ingredient_name) {
                inventory.emplace_back(ingredient, amount_remaining); // Update amount
                ingredient_found = true;
            } 
            else {
                inventory.emplace_back(ingredient, amount); // Keep existing data
            }
        }
    }
    infile.close();

    // If the ingredient wasn't found, add it to the inventory
    // if (!ingredient_found) {
    //     inventory.emplace_back(ingredient_name, amount_remaining);
    // }

    // Write the updated inventory back to the file
    std::ofstream outfile(file_name); 
    if (!outfile.is_open()) {
        std::cerr << "Error: Unable to open file " << file_name << " for writing.\n";
        return;
    }

    for (const auto& item : inventory) {
        outfile << item.first << "," << item.second << "\n";
    }
    outfile.close();

    std::cout << "Inventory updated successfully for " << ingredient_name << ".\n";
}


//this function fetches value from inventory for a given ingredient, this value is used in setInventoryValue.cpp
int Ingredients::getInventoryValue(const std::string& file_name, const std::string& ingredient_name) {
    std::ifstream infile(file_name);
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file " << file_name << " for reading.\n";
        return -1; // Return a special value to indicate failure
    }

    std::string line, ingredient;
    int amount;

    // Read the CSV file line by line
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string amount_str;

        // Parse the line into ingredient and amount
        if (std::getline(iss, ingredient, ',') && std::getline(iss, amount_str)) {
            try {
                amount = std::stoi(amount_str);
            } catch (...) {
                amount = 0; // Handle invalid numeric data
            }

            // Check if the current ingredient matches the one being searched for
            if (ingredient == ingredient_name) {
                infile.close();
                return amount; // Return the found value
            }
        }
    }

    infile.close();
    std::cerr << "Error: Ingredient '" << ingredient_name << "' not found in the inventory.\n";
    return -1; // Return a special value to indicate that the ingredient was not found
}
