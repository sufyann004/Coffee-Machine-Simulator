
#include "cashorcard.hpp"
#include "helper_functions.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


cashCard gencashcard() {
    cashCard selection;
    sf::RenderWindow window(sf::VideoMode(800, 450), "Cash or Card", sf::Style::Close);

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("cashcard.png")) {
        cerr << "Error loading background image!" << endl;
        return {};
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // Set up buttons
    sf::CircleShape cashButton(110.f);
    cashButton.setPosition(95.f, 100.f);
    cashButton.setFillColor(sf::Color(0, 255, 0, 100)); // Semi-transparent

    sf::CircleShape cardButton(110.f);
    cardButton.setPosition(445.f, 100.f);
    cardButton.setFillColor(sf::Color(0, 0, 255, 100)); 

    

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (cashButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    selection.IsCash = true;
                    selection.IsCard=false;
                    cout << "Cash selected!" << endl;
                    window.close();
                }

                if (cardButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    selection.IsCard=true;
                    selection.IsCash=false;
                    cout << "Card selected!" << endl;
                    window.close();
                }
            }
        }

       
        window.clear();
        window.draw(backgroundSprite);
        window.draw(cashButton);
        window.draw(cardButton);
        window.display();
    }

    // Return selection
    return selection;
}
