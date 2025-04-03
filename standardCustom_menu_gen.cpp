#include "standardCustom_menu_gen.hpp"
#include "helper_functions.hpp" 
#include "button_sound.hpp"
#include <iostream>
using namespace std;


modSelection generateStandardCustomMenu() {
    int x = 0;
    int y = 0;

    modSelection mod_selection{false, false, false};

    ButtonPressSound press("button_click.wav");

    // Position of the Custom, standard and back button on menu, wrt top left corner
    sf::Vector2i custom_button= {67, 231};
    sf::Vector2i standard_button= {409, 235};
     sf::Vector2i back_button= {571, 370};

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 741), "Coffee Machine 3000");

    
    sf::Texture texture;
    if (!texture.loadFromFile("standard_custom_menu.png")) {
        cerr << "Could not load image" << endl;
        return mod_selection;   
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

        // Check if the custom button is clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isMouseOver(window, custom_button, 315, 103)) { //for custom_button, width is 315 pixels and height is 103 pixels
                press.play();
                sf::sleep(sf::milliseconds(500));
                cout << "custom button clicked!" << endl;
                mod_selection.custom_selected = true;
                window.close();
            }
            else if (isMouseOver(window, standard_button, 315, 103)) { //for standard_button, width is 315 pixels and height is 103 pixels
                press.play();
                sf::sleep(sf::milliseconds(500));
                cout << "standard button clicked!" << endl;
                mod_selection.standard_selected = true;
                window.close();
            }
            else if (isMouseOver(window, back_button, 155, 61)) { 
                press.play();
                sf::sleep(sf::milliseconds(500));
                cout << "back button clicked!" << endl;
                mod_selection.back_selected = true;
                window.close();
            }

        
        }
       
        window.clear(sf::Color::Black);
        window.draw(image);
        window.display();


    
    }
    return mod_selection;
}
