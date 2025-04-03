#include "cappuccino.hpp"

Cappuccino::Cappuccino() {  //standard recipe, if custom manually set data members to required values
    coffee_powder = 13; //gms
    white_sugar = 10;  //gms
    brown_sugar = 0;    //the problem with previous approach was that it by default used to add sugar to cappuccino when object was created
    mix_sugar = 0; 
    full_cream_milk = 250;  //ml
    almond_milk = 0;
    coconut_milk = 0;
    size = "";
    size_factor = 0;

    cout << "Cappuccino created!" << endl;
}


void Cappuccino::setWhiteSugar(double sugarAdded){
    this->white_sugar = sugarAdded;
}
double Cappuccino::getWhiteSugar() const{
    return this->white_sugar;
}

//define the set and get functions here, look Cappuccino.hpp file

void Cappuccino::bill() {
    total_amount = 13;
}



//     totalamount=Sizee*coffee_beans+sugar+milk+toppings;
//     cout << "Billing details for your Cappuccino:" << endl;
//     cout << "Coffee Beans: " << coffee_beans << "g" << endl;
//     cout << "Sugar: " << sugar << "g" << endl;
//     cout << "Milk: " << milk << "ml" << endl;
//     cout << "Toppings: " << toppings << "g" << endl;
//     cout << "Size: " << size << "g" << endl;
//     cout<<"Total:" <<totalamount<<" USD \n";
   
// }
