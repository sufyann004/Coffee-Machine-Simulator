#ifndef button_sound
#define button_sound

#include <SFML/Audio.hpp>
#include <iostream>

class ButtonPressSound {
private:
    sf::SoundBuffer buffer; // Holds the audio file
    sf::Sound sound;        // Plays the audio

public:
   
    ButtonPressSound(const std::string& filePath);

    // Starts playing the sound in a loop
    void play();

    // Stops playing the sound
    void stop();
};

#endif 
