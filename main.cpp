#include "audiomanager.h"
#include <iostream>

int main() {
    AudioManager* audio = AudioManager::getInstance();

    audio->loadSound("sounds/explosion.wav");
    audio->loadSound("sounds/laser.wav");

    audio->setVolume(0.7f);

    audio->playSound("explosion");
    audio->playSound("laser");

    std::cout << "explosion is playing? " << (audio->isPlaying("explosion") ? "YES" : "NO") << std::endl;

    audio->pauseAll();
    audio->resumeAll();

    audio->stopSound("explosion");
    std::cout << "explosion is playing? " << (audio->isPlaying("explosion") ? "YES" : "NO") << std::endl;

    audio->stopSound("laser");

    return 0;
}
