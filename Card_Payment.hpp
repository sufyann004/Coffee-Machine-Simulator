#ifndef Card_Payment
#define Card_Payment

struct PaymentDetails {
    bool completed;
    string cardNumber;
    string code;
};




PaymentDetails generateCardScreen();

#endif 
