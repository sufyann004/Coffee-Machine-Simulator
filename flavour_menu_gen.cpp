#include "flavour_menu_gen.hpp"
#include "helper_functions.hpp" 
#include "button_sound.hpp"
#include <iostream>
using namespace std;


flavourSelection generateFlavourMenu() {
    int x = 0;
    int y = 0;

    ButtonPressSound press("button_click.wav");

    flavourSelection flavour_selection{false, false, false, false, false, false};

    // Position of buttons on menu, wrt top left corner
    sf::Vector2i milkChoc_button = {53, 191};
    sf::Vector2i caramel_button = {292, 191};
    sf::Vector2i matcha_button = {528, 191};
    sf::Vector2i skip_button = {528, 425};
    sf::Vector2i back_button = {528, 540};

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 741), "Coffee Machine 3000");

    
    sf::Texture texture;
    if (!texture.loadFromFile("flavour_menu.png")) {
        cerr << "Could not load image" << endl;
        return flavour_selection;   
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

        // Check if a button is clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isMouseOver(window, milkChoc_button, 214, 208)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "milk chocolate button clicked!" << endl;
                flavour_selection.milk_choc = true;
                flavour_selection.was_flavourSelected = true;
                window.close();
            }
            else if (isMouseOver(window, caramel_button, 214, 208)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "caramel button clicked!" << endl;
                flavour_selection.caramel= true;
                flavour_selection.was_flavourSelected = true;
                window.close();
            }
            else if (isMouseOver(window, matcha_button, 214, 208)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "matcha button clicked!" << endl;
                flavour_selection.matcha= true;
                flavour_selection.was_flavourSelected = true;
                window.close();
            }
            else if (isMouseOver(window, skip_button, 214, 88)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "skip button clicked!" << endl;
                flavour_selection.skip = true;
                flavour_selection.was_flavourSelected = true;
                window.close();
            }
            else if (isMouseOver(window, back_button, 214, 88)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "back button clicked!" << endl;
                flavour_selection.back= true;
                flavour_selection.was_flavourSelected = false;
                window.close();
            }
        }
       
        window.clear(sf::Color::Black);
        window.draw(image);
        window.display();

    }
    return flavour_selection;
}
