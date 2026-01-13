#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <string>
#include <map>
#include <set>

class AudioManagerDestroyer;

class AudioManager {
private:
    static AudioManager* p_instance;
    static AudioManagerDestroyer destroyer;

    std::map<std::string, std::string> sounds; // name -> path
    std::set<std::string> playingSounds;
    float volume;
    bool paused;

    AudioManager();
    AudioManager(const AudioManager&);
    AudioManager& operator=(const AudioManager&);
    ~AudioManager();

    friend class AudioManagerDestroyer;

public:
    static AudioManager* getInstance();

    void loadSound(const std::string& path);
    void playSound(const std::string& name);
    void stopSound(const std::string& name);
    void setVolume(float volume);
    void pauseAll();
    void resumeAll();
    bool isPlaying(const std::string& name);
};

class AudioManagerDestroyer {
private:
    AudioManager* p_instance;
public:
    ~AudioManagerDestroyer() { delete p_instance; }
    void initialize(AudioManager* p) { p_instance = p; }
};

#endif // AUDIOMANAGER_H
