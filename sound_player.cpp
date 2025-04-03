#include "sound_player.hpp"


SoundPlayer::SoundPlayer(const std::string& filePath) {
    if (!buffer.loadFromFile(filePath)) {
        std::cerr << "Failed to load sound file: " << filePath << std::endl;
        exit(-1); 
    }
    sound.setBuffer(buffer);
    sound.setLoop(true); // Enable looping
}

// Starts playing the sound
void SoundPlayer::play() {
    sound.play();
}

// Stops the sound
void SoundPlayer::stop() {
    sound.stop();
}
