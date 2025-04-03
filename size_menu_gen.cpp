#include "size_menu_gen.hpp"
#include "helper_functions.hpp" 
#include "button_sound.hpp"
#include <iostream>
using namespace std;


sizeSelection generateSizeMenu() {
    int x = 0;
    int y = 0;

    sizeSelection size_selection{false, false, false, false, false};

    ButtonPressSound press("button_click.wav");

    // Position of buttons on menu, wrt top left corner
    sf::Vector2i small_button = {38, 152};
    sf::Vector2i medium_button = {284, 152};
    sf::Vector2i large_button = {533, 152};
    sf::Vector2i back_button = {533, 396};

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 741), "Coffee Machine 3000");

    
    sf::Texture texture;
    if (!texture.loadFromFile("size_menu.png")) {
        cerr << "Could not load image" << endl;
        return size_selection;   
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

        // Check if the small size button is clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isMouseOver(window, small_button, 221, 219)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "small size chosen!" << endl;
                size_selection.small = true;
                size_selection.was_size_selected = true;
                window.close();
            }
            else if (isMouseOver(window, medium_button, 221, 219)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "medium size chosen!" << endl;
                size_selection.medium = true;
                size_selection.was_size_selected = true;
                window.close();
            }
            else if (isMouseOver(window, large_button, 221, 219)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "large size chosen!" << endl;
                size_selection.large= true;
                size_selection.was_size_selected = true;
                window.close();
            }
            else if (isMouseOver(window, back_button, 221, 100)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "back button pressed!" << endl;
                size_selection.back = true;
                size_selection.was_size_selected = false;
                window.close();
            }
        }
       
        window.clear(sf::Color::Black);
        window.draw(image);
        window.display();

    }
    return size_selection;
}
