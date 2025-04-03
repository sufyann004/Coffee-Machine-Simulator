#include "coffee_menu_gen.hpp"
#include <SFML/Graphics.hpp>     
#include "helper_functions.hpp" 
#include "button_sound.hpp"
#include "cappuccino.hpp"
#include <iostream>
using namespace std;



CoffeeSelection generateCoffeeMenu() {
    int x = 0;
    int y = 0;

    CoffeeSelection selection{false, false, false, false, false, false, false};  //create a variable of type CoffeeSelection (which is a struct)
    //Position of the cappuccino button on coffee_menu, wrt top left corner
    sf::Vector2i cappuccino_button = {42, 235};
    sf::Vector2i latte_button = {530, 237};
    sf::Vector2i espresso_button = {287, 236};
    sf::Vector2i frappe_button = {530, 477};
    sf::Vector2i dalgona_button = {45, 478};
    sf::Vector2i americano_button = {289, 477};

    ButtonPressSound press("button_click.wav");
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 741), "Coffee Machine 3000");

  
    sf::Texture texture;
    if (!texture.loadFromFile("coffee_menu.png")) {
        cerr << "Could not load image" << endl;
        return selection;
    }

 
    sf::Sprite image;
    image.setTexture(texture);
    image.setPosition(sf::Vector2f(x, y));
    image.scale(sf::Vector2f(1, 1));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


         //figure out which coffee was selected from coffee_menu
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isMouseOver(window, cappuccino_button, 223, 217)) { //Button Width: 223, Height: 217
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "cappuccino selected!" << endl;
                selection.cappuccino_selected = true;
                selection.was_coffee_selected = true;
                window.close();
            }
            else if (isMouseOver(window, espresso_button, 223, 217)) { //Button Width: 223, Height: 217
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "espresso selected!" << endl;
                selection.espresso_selected = true;
                selection.was_coffee_selected = true;
                window.close();
            }
            else if (isMouseOver(window, latte_button, 223, 217)) { //Button Width: 223, Height: 217
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "latte selected!" << endl;
                selection.latte_selected = true;
                selection.was_coffee_selected = true;
                window.close();
            }
            else if (isMouseOver(window, dalgona_button, 223, 217 )) { //Button Width: 223, Height: 217
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "dalgona selected!" << endl;
                selection.dalgona_selected = true;
                selection.was_coffee_selected = true;
                window.close();
            }
            else if (isMouseOver(window, americano_button, 223, 217 )) { //Button Width: 223, Height: 217
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "americano selected!" << endl;
                selection.americano_selected = true;
                selection.was_coffee_selected = true;
                window.close();
            }
            else if (isMouseOver(window, frappe_button, 223, 217)) { //Button Width: 223, Height: 217
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "frappe selected!" << endl;
                selection.frappe_selected = true;
                selection.was_coffee_selected = true;
                window.close();
            }
        }

        // Clear, draw, and display
        window.clear(sf::Color::Black);
        window.draw(image);
        window.display();
    }
    return selection;
}
