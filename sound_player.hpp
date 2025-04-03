#ifndef sound_player
#define sound_player

#include <SFML/Audio.hpp>
#include <iostream>

class SoundPlayer {
private:
    sf::SoundBuffer buffer; // Holds the audio file
    sf::Sound sound;        // Plays the audio

public:
   
    SoundPlayer(const std::string& filePath);

    // Starts playing the sound in a loop
    void play();

    // Stops playing the sound
    void stop();
};

#endif 
