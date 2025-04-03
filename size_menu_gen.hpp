#ifndef size_menu_gen
#define size_menu_gen

struct sizeSelection {
    bool small;
    bool medium;
    bool large;
    bool was_size_selected;
    bool back;   //no skip here since selecting a size is a must, not an option
};




sizeSelection generateSizeMenu();

#endif 
