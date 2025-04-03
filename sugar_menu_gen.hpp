#ifndef sugar_menu_gen
#define sugar_menu_gen

struct sugarSelection {
    bool white;
    bool brown;
    bool mix;
    bool was_sugarSelected;
    bool skip;
    bool back;
};




sugarSelection generateSugarMenu();

#endif 
