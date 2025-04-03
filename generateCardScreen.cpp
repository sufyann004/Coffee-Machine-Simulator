
#include "Card_Payment.hpp"
#include "helper_functions.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

PaymentDetails generateCardScreen() {
    PaymentDetails details{false, "", ""};

    
    sf::RenderWindow window(sf::VideoMode(800, 450), "Payment Screen");

   
    sf::Texture texture;
    if (!texture.loadFromFile("payment.jpg")) {
        cerr << "Could not load payment.png" << endl;
        return details;
    }

    sf::Sprite background;
    background.setTexture(texture);
    background.setScale(
        800.0f / texture.getSize().x,  // Scale to window width
        450.0f / texture.getSize().y   // Scale to window height
    );

   
    sf::RectangleShape cardNumberBox(sf::Vector2f(350.f, 50.f)); 
    cardNumberBox.setPosition(100.f, 120.f);  
    cardNumberBox.setFillColor(sf::Color::White);
    cardNumberBox.setOutlineColor(sf::Color::Black);
    cardNumberBox.setOutlineThickness(2.f);

    
    sf::RectangleShape codeBox(sf::Vector2f(150.f, 50.f));
    codeBox.setPosition(100.f, 200.f);
    codeBox.setFillColor(sf::Color::White);
    codeBox.setOutlineColor(sf::Color::Black);
    codeBox.setOutlineThickness(2.f);

    
    sf::RectangleShape payButton(sf::Vector2f(120.f, 50.f)); 
    payButton.setPosition(180.f, 300.f); // Positioned for easy access
    payButton.setFillColor(sf::Color(0, 150, 255));  // Button blue color

    
    sf::Font font;
    if (!font.loadFromFile("prstart.ttf")) {
        cerr << "Could not load font" << endl;
        return details;
    }

    sf::Text cardNumberText;
    cardNumberText.setFont(font);
    cardNumberText.setCharacterSize(20);
    cardNumberText.setFillColor(sf::Color::Black);
    cardNumberText.setPosition(105.f, 130.f);  

    
    sf::Text codeText;
    codeText.setFont(font);
    codeText.setCharacterSize(20);
    codeText.setFillColor(sf::Color::Black);
    codeText.setPosition(105.f, 205.f);

    
    sf::Text payText;
    payText.setString("Pay");
    payText.setFont(font);
    payText.setCharacterSize(25);
    payText.setFillColor(sf::Color::White);
    payText.setPosition(200.f, 320.f);

    bool cardNumberSelected = false;
    bool codeSelected = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle text input
            if (event.type == sf::Event::TextEntered) {
                if (cardNumberSelected && event.text.unicode < 128) {
                    if (event.text.unicode == '\b' && !details.cardNumber.empty())
                        details.cardNumber.pop_back();  // Backspace support
                    else if (isdigit(event.text.unicode) && details.cardNumber.length() < 16)
                        details.cardNumber += static_cast<char>(event.text.unicode);
                }
                else if (codeSelected && event.text.unicode < 128) {
                    if (event.text.unicode == '\b' && !details.code.empty())
                        details.code.pop_back();
                    else if (isdigit(event.text.unicode) && details.code.length() < 3)
                        details.code += static_cast<char>(event.text.unicode);
                }
            }

            // Mouse clicks for selection
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

               
                if (cardNumberBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    cardNumberSelected = true;
                    codeSelected = false;
                }
             
                else if (codeBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    cardNumberSelected = false;
                    codeSelected = true;
                }
                // Pay Button
                else if (payButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    if (!details.cardNumber.empty() && !details.code.empty()) {
                        details.completed = true;
                        window.close();
                    }
                }
            }
        }

        // Update input text
        cardNumberText.setString(details.cardNumber);
        codeText.setString(details.code);

        // Draw 
        window.clear(sf::Color(220, 220, 220));  // Light background
        window.draw(background);
        window.draw(cardNumberBox);
        window.draw(codeBox);
        window.draw(payButton);
        window.draw(cardNumberText);
        window.draw(codeText);
        window.draw(payText);
        window.display();
    }

    return details;
}
