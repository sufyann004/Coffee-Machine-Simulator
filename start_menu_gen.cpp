#include "start_menu_gen.hpp"
#include "button_sound.hpp"
#include "helper_functions.hpp" 
#include <iostream>
using namespace std;


startSelection generateStartMenu() {
    int x = 0;
    int y = 0;

    startSelection start_selection{false, false};
   
   ButtonPressSound press("button_click.wav");


    // Position of the Start and quit buttons on start_menu, wrt top left corner
    sf::Vector2i start_pos = {70, 507};
    sf::Vector2i quit_pos = {106, 635};

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 741), "Coffee Machine 3000");

    // Load the start menu texture
    sf::Texture texture;
    if (!texture.loadFromFile("start_menu.png")) {
        cerr << "Could not load image" << endl;
        return start_selection;   //recheck effect of this useless false return
    }

    // Initialize the sprite for the start menu
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

        // Check if the Start button is clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isMouseOver(window, start_pos, 273, 67)) { // Width: 273, Height: 67
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "Start button clicked!" << endl;
                start_selection.start_pressed = true;
               
                window.close();
            }
            else if (isMouseOver(window, quit_pos, 204, 65)) { // Width: 273, Height: 67
                press.play();
                sf::sleep(sf::milliseconds(400));
                cout << "quit button clicked!" << endl;
                start_selection.quit_pressed = true;
                window.close();
            }



        }
         // Clear, draw, and display the start menu
        window.clear(sf::Color::Black);
        window.draw(image);
        window.display();


    
    }
    return start_selection;
}
