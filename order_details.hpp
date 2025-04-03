#ifndef order_details
#define order_details

#include <iostream>
using namespace std;

class order {
    public:
    string coffee_type;   //full name of coffee type chosen in lowercase to be stored here
    char size;  //either S, M or L 
    int sugar;  //in grams
    int milk;   //in ml
    int toppings;  //to be implemented
    string flavour; //CHOCOLATE, CARAMEL or MATCHA. 
};


//remember in main to see which combination was selected, ie:
// cost of small cup with CHOC will not be the same as Large cup with CHOC.
//calculate cost based on this logic. Also tell Sufyan about this.


#endif 