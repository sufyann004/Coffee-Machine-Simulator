#include "sugar_menu_gen.hpp"
#include "helper_functions.hpp" 
#include "button_sound.hpp"
#include <iostream>
using namespace std;


sugarSelection generateSugarMenu() {
    int x = 0;
    int y = 0;

    ButtonPressSound press("button_click.wav");

    sugarSelection sugar_selection{false, false, false, false, false, false};

    // Position of the sugar and other buttons on menu, wrt top left corner
    sf::Vector2i whiteSugar_button = {55, 127};
    sf::Vector2i brownSugar_button = {291, 127};
    sf::Vector2i mixSugar_button = {531, 127};
    sf::Vector2i skip_button = {531, 363};
    sf::Vector2i back_button = {531, 463};

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 741), "Coffee Machine 3000");

    
    sf::Texture texture;
    if (!texture.loadFromFile("sugar_menu.png")) {
        cerr << "Could not load image" << endl;
        return sugar_selection;   
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

        // Check if any of the displayed buttons is clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isMouseOver(window, whiteSugar_button, 210, 204)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "white sugar button clicked!" << endl;
                sugar_selection.white = true;
                sugar_selection.was_sugarSelected = true;
                
                window.close();
            }
            else if (isMouseOver(window, brownSugar_button, 210, 204)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "brown sugar button clicked!" << endl;
                sugar_selection.brown = true;
                sugar_selection.was_sugarSelected = true;
                window.close();
            }
            else if (isMouseOver(window, mixSugar_button, 210, 204)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "mix sugar button clicked!" << endl;
                sugar_selection.mix = true;
                sugar_selection.was_sugarSelected = true;
                window.close();
            }
            else if (isMouseOver(window, skip_button, 210, 72)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "skip button clicked!" << endl;
                sugar_selection.skip = true;
                sugar_selection.was_sugarSelected = true;  //just to move ahead in main() even though no sugar is chosen in reality
                window.close();
            }
            else if (isMouseOver(window, back_button, 210, 72)) {
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "back button clicked!" << endl;
                sugar_selection.back = true;
                sugar_selection.was_sugarSelected = false;
                window.close();
            }




        }
       
        window.clear(sf::Color::Black);
        window.draw(image);
        window.display();

    }
    return sugar_selection;
}
