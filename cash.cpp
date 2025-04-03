#include "cash.hpp"
#include "helper_functions.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

bool genCash(double to_pay) {
    int entered = 0; //amount entered by user
    double balance = 0;  //to_pay - entered = balance
    bool paid = false;
    sf::RenderWindow window(sf::VideoMode(800, 450), "Cash", sf::Style::Close);

    
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("cash.png")) {
        cerr << "Error loading background image!" << endl;
        return false;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    sf::CircleShape onedollar(90.f);
    onedollar.setPosition(30.f, 200.f);
    onedollar.setFillColor(sf::Color(0, 255, 0, 100)); // Semi-transparent green

    sf::CircleShape twodollar(90.f);
    twodollar.setPosition(310.f, 200.f);
    twodollar.setFillColor(sf::Color(0, 0, 255, 100)); // Semi-transparent blue

    sf::CircleShape fivedollar(90.f);
    fivedollar.setPosition(590.f, 200.f);
    fivedollar.setFillColor(sf::Color(0, 0, 125, 100)); 

  
    sf::RectangleShape payButton(sf::Vector2f(120.f, 50.f)); 
    payButton.setPosition(355.f, 390.f); 
    payButton.setFillColor(sf::Color::Black);  

   
    sf::Font font;
    if (!font.loadFromFile("prstart.ttf")) {
        cerr << "Could not load font" << endl;
        return false;
    }


    sf::Text payText;
    payText.setString("Pay");
    payText.setFont(font);
    payText.setCharacterSize(25);
    payText.setFillColor(sf::Color::White);
    payText.setPosition(370.f, 405.f);

    sf::Text TotalText;
    TotalText.setFont(font);
    TotalText.setCharacterSize(15);
    TotalText.setFillColor(sf::Color::White);
    TotalText.setPosition(600.f, 10.f);

   
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (onedollar.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    entered += 1;
                    cout << " $1 added. Total Amount entered: " << entered<< endl;
                    }

                if (twodollar.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    entered += 2;
                    cout << " $2 added. Total Amount entered: " << entered << endl;
                }

                if (fivedollar.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    entered += 5;
                    cout << " $5 added. Total Amount entered: " << entered << endl;
                }

                if (payButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    if(entered >= to_pay){
                        cout << "Pay button clicked. Total amount entered: " << entered << endl;
                        balance = entered - to_pay;
                        cout << "Here's the balance: " << balance << endl; 
                        paid = true;
                        window.close();
                    }
                    else{
                        cout << "Insufficient amount entered!" << endl;
                    }
            }
        }

        // Update the TotalText string dynamically
        TotalText.setString("Total: " + std::to_string(entered));


        window.clear();
        window.draw(backgroundSprite);
        window.draw(onedollar);
        window.draw(twodollar);
        window.draw(fivedollar);
        
        window.draw(TotalText);
        window.draw(payButton);
        window.draw(payText);
        window.display();
        }
    }
    return paid;
}
