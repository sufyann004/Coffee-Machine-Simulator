#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "coffee_type.cpp"
#include "cash.hpp"
#include "espresso.cpp"
#include "espresso.hpp"
#include "dalgona.hpp"
#include "dalgona.cpp"
#include "frappe.cpp"
#include "frappe.hpp"
#include "cash.cpp"
#include "coffee_hot_cold.cpp"
#include "americano.cpp"
#include "americano.hpp"
#include "cappuccino.cpp"
#include "cashorcard.cpp"
#include "cashorcard.hpp"
#include "ingredients.cpp"
#include "helper_functions.cpp"
#include "start_menu_gen.cpp"
#include "coffee_menu_gen.cpp"
#include "standardCustom_menu_gen.cpp"
#include "sugar_menu_gen.cpp"
#include "milk_menu_gen.cpp"
#include "flavour_menu_gen.cpp"
#include "size_menu_gen.cpp"
#include "generateCardScreen.cpp"
#include <SFML/Graphics.hpp>
#include "sound_player.cpp"
#include "button_sound.cpp"
#include "setInventoryValue.cpp"
#include "deductInventory.cpp"
#include <cstdlib>
#include <SFML/Audio.hpp>

using namespace std;



int main() {
    startSelection start_selection;
    CoffeeSelection coffee_selection;
    modSelection mod_selection;
    sugarSelection sugar_selection;
    milkSelection milk_selection;
    flavourSelection flavour_selection;
    sizeSelection size_selection;
    cashCard choice;
    PaymentDetails payy;
    Ingredients ingredients;
    CoffeeType* c1= nullptr;

    bool paid;
       
    setInventoryValue(ingredients);  //fetch ingredient inventory level info

//    SoundPlayer player("elvienrose.wav");
//     player.play();

    start_selection = generateStartMenu();   //START SCREEN
    
    if(start_selection.start_pressed == true){
        coffee_selection = generateCoffeeMenu();   //COFFEE TYPES SCREEN
    }
    else if(start_selection.quit_pressed == true){
        exit(0);
    }


    if (coffee_selection.cappuccino_selected == true) {
        c1=new Cappuccino();
    } 
    else if(coffee_selection.espresso_selected == true){
        // c1=new Espresso();        
    }
    else if(coffee_selection.dalgona_selected == true){
        // c1=new Dalgona();
    }
    else if(coffee_selection.frappe_selected == true){
        // c1=new Frappe();
    }
    else if(coffee_selection.americano_selected == true){
        // c1=new Americano();
    }


    if(coffee_selection.was_coffee_selected == true){
        mod_selection = generateStandardCustomMenu();  //STANDARD CUSTOM SCREEN
    }

    if(mod_selection.custom_selected == true){  //CUSTOM ORDER
        sugar_selection = generateSugarMenu();  //SUGAR SCREEN
   
        if(sugar_selection.white==true){
            c1->setWhiteSugar(7);

        }
        else if(sugar_selection.brown==true){
            // c1->sugar=7;
        }
        else if(sugar_selection.mix==true){
            // c1->sugar=5;
        }

        if(sugar_selection.was_sugarSelected==true){
            milk_selection = generateMilkMenu();  //MILK SCREEN
        }
        if(milk_selection.full_cream == true){
        //only add to order details, dont deduct from inventory yet to allow back button operation
        }
        else if(milk_selection.coconut == true){
            //add to order details
            cout << c1->getWhiteSugar();
        }
        else if(milk_selection.almond == true){
            //add to order details
        }

        if(milk_selection.was_milkSelected == true){
            flavour_selection = generateFlavourMenu();  //FLAVOUR SCREEN
        }
        if(flavour_selection.milk_choc == true){
            //add to order details
        }
        else if(flavour_selection.caramel == true){
            //add to order details
        }
        else if(flavour_selection.matcha == true){
            //add to order details
        }

        if(flavour_selection.was_flavourSelected == true){
            size_selection = generateSizeMenu();  //SIZE SCREEN
        }

        if(size_selection.small == true){
            c1->size="Small";
            // c1->Sizee=1;
        }
        else if(size_selection.medium == true){
            c1->size="Medium";
            // c1->Sizee=2;
        }
        else if(size_selection.large == true){
            c1->size="Large";
            // c1->Sizee=3;
        }
        // c1->bill(); // Generate the bill
        // choice = gencashcard(); // Ask for payment method

        // if (choice.IsCard == true) {
        //     payy = generateCardScreen(); // Handle card payment
        // } 
        // else {
        //     paid = genCash(c1->total_amount); // Handle cash payment
        // }
        // player.stop();
        return 0;
    }
        

    else if(mod_selection.standard_selected == true){  //STANDARD ORDER
        size_selection = generateSizeMenu();  //SIZE SCREEN

        if(size_selection.small == true){
            c1->size="Small";
            // c1->Sizee=1;
        }
        else if(size_selection.medium == true){
            c1->size="Medium";
            // c1->Sizee=2;
        }
        else if(size_selection.large == true){
            c1->size="Large";
            // c1->Sizee=3;
        }

        // c1->bill(); // Generate the bill
        // choice = gencashcard(); // Ask for payment method

        // if(choice.IsCard == true) {
        //     payy = generateCardScreen(); // Handle card payment
        // } 
        // else {
        //     paid = genCash(c1->total_amount); // Handle cash payment  , should take total bill as parameter
            
        // }
        // player.stop();
        return 0;
    }

    else if(mod_selection.back_selected == true){
       //go back to coffee menu
    }

    if(paid == true){
        //update inventory levels, add order to sales record with order id, show coffee being made, and move on.
        
    }
    
    return 0;
}


//add destructors to release memory