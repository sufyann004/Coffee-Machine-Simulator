#include "milk_menu_gen.hpp"
#include "helper_functions.hpp" 
#include "button_sound.hpp"
#include <iostream>
using namespace std;


milkSelection generateMilkMenu() {
    int x = 0;
    int y = 0;

    ButtonPressSound press("button_click.wav");

    milkSelection milk_selection{false, false, false, false, false, false};

    // Position of buttons on menu, wrt top left corner
    sf::Vector2i fullCream_button = {53, 195};
    sf::Vector2i coconut_button = {290, 195};
    sf::Vector2i almond_button = {529, 195};
    sf::Vector2i skip_button = {529, 434};

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 741), "Coffee Machine 3000");

    
    sf::Texture texture;
    if (!texture.loadFromFile("milk_menu.png")) {
        cerr << "Could not load image" << endl;
        return milk_selection;   
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

        // Check if the button is clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isMouseOver(window, fullCream_button, 213, 209)) {
                 press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "full cream button clicked!" << endl;
                milk_selection.full_cream = true;
                milk_selection.was_milkSelected = true;
                window.close();
            }
            else if (isMouseOver(window, coconut_button, 213, 209)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "coconut milk button clicked!" << endl;
                milk_selection.coconut = true;
                milk_selection.was_milkSelected = true;
                window.close();
            }
            else if (isMouseOver(window, almond_button, 213, 209)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "almond milk button clicked!" << endl;
                milk_selection.almond = true;
                milk_selection.was_milkSelected = true;
                window.close();
            }
            else if (isMouseOver(window, skip_button, 213, 66)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "skip button clicked!" << endl;
                milk_selection.skip = true;
                milk_selection.was_milkSelected = true;
                window.close();
            }

        }
       
        window.clear(sf::Color::Black);
        window.draw(image);
        window.display();

    }
    return milk_selection;
}
