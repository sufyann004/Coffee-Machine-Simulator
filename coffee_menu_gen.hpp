#ifndef coffee_menu_gen
#define coffee_menu_gen


struct CoffeeSelection {
    bool was_coffee_selected;
    bool cappuccino_selected;
    bool latte_selected;
    bool espresso_selected;
    bool americano_selected;
    bool dalgona_selected;
    bool frappe_selected;
};


CoffeeSelection generateCoffeeMenu();

#endif 
