#include "helper_functions.hpp"


//helps to execute button logic, when the mouse is over the button region, returns true else returns false
bool isMouseOver(sf::RenderWindow &window, const sf::Vector2i &start_pos, int width, int height) {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    return mouseX > start_pos.x && mouseX < (start_pos.x + width) && 
           mouseY > start_pos.y && mouseY < (start_pos.y + height);
}
