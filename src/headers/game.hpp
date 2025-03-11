#pragma once
#include <map>
#include <string>
#include <raylib.h>
#include <vector>

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
    private:
        int windowWidth;
        int windowHeight;
        bool playMusic;
        std::map<std::string, Image> images;
        std::map<std::string, Texture2D> textures;
        std::map<std::string, Sound> sounds;
        Music stream;
        State state;
        void LoadAssets();
        void ReloadGameComponents();
};