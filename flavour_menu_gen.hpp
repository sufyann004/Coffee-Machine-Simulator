#ifndef flavour_menu_gen
#define flavour_menu_gen

struct flavourSelection {
    bool milk_choc;
    bool caramel;
    bool matcha;
    bool was_flavourSelected;
    bool skip;
    bool back;
};




flavourSelection generateFlavourMenu();

#endif 
