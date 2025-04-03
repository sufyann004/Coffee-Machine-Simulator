#ifndef milk_menu_gen
#define milk_menu_gen

struct milkSelection {
    bool full_cream;
    bool coconut;
    bool almond;
    bool was_milkSelected;
    bool skip;
    bool back;  //will be implemented later, no button in interface atm
};




milkSelection generateMilkMenu();

#endif 
