#pragma once
#include <map>
#include <string>
#include <raylib.h>
#include <vector>
#include "../headers/entities.hpp"

class Ship;

enum State {
    START,
    PLAY,
    RESTART
};

class Game {
    public:
        Game(int windowWidth, int windowHeight, bool playMusic);
        void UnloadAssets();
        void HandleInput();
        void Update();
        void Render();
        int getWindowHeight();
        int getWindowWidth();
        void playSound(std::string soundName);
    private:
        int windowWidth;
        int windowHeight;
        int score;
        bool playMusic;
        std::map<std::string, Image> images;
        std::map<std::string, Texture2D> textures;
        std::map<std::string, Sound> sounds;
        Music stream;
        State state;
        Ship *ship;
        void LoadAssets();
        void ReloadGameComponents();
};