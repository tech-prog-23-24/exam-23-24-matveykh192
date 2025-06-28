#include "audiomanager.h"
#include <iostream>

AudioManager* AudioManager::p_instance = nullptr;
AudioManagerDestroyer AudioManager::destroyer;

AudioManager::AudioManager() : volume(1.0f), paused(false) {}

AudioManager::~AudioManager() {}

AudioManager* AudioManager::getInstance() {
    if (!p_instance) {
        p_instance = new AudioManager();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void AudioManager::loadSound(const std::string& path) {
    // Имя звука - это имя файла без расширения
    size_t lastSlash = path.find_last_of("/\\");
    size_t lastDot = path.find_last_of(".");
    std::string name = path.substr(lastSlash + 1, lastDot - lastSlash - 1);
    sounds[name] = path;
    std::cout << "Zvuk '" << name << "' zagruzhen iz '" << path << "'\n";
}

void AudioManager::playSound(const std::string& name) {
    if (sounds.count(name)) {
        playingSounds.insert(name);
        std::cout << "Vosproizvedenie zvuka: " << name << "\n";
    } else {
        std::cout << "Zvuk '" << name << "' ne zagruzhen!\n";
    }
}

void AudioManager::stopSound(const std::string& name) {
    if (playingSounds.erase(name)) {
        std::cout << "Ostanovlen zvuk: " << name << "\n";
    } else {
        std::cout << "Zvuk '" << name << "' ne vosproizvoditsya!\n";
    }
}

void AudioManager::setVolume(float v) {
    volume = v;
    std::cout << "Gromkost' ustanovlena: " << volume << "\n";
}

void AudioManager::pauseAll() {
    if (!paused) {
        paused = true;
        std::cout << "Vse zvuki postavleny na pauzu\n";
    }
}

void AudioManager::resumeAll() {
    if (paused) {
        paused = false;
        std::cout << "Vse zvuki vozobnovleny\n";
    }
}

bool AudioManager::isPlaying(const std::string& name) {
    return playingSounds.count(name) > 0;
}
