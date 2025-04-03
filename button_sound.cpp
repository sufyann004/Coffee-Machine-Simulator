#include "button_sound.hpp"


ButtonPressSound::ButtonPressSound(const std::string& filePath) {
    if (!buffer.loadFromFile(filePath)) {
        std::cerr << "Failed to load sound file: " << filePath << std::endl;
        exit(-1); 
    }
    sound.setBuffer(buffer);
    sound.setLoop(false); //disable looping
}

// Starts playing the sound
void ButtonPressSound::play() {
    sound.play();
}

// Stops the sound
void ButtonPressSound::stop() {
    sound.stop();
}
