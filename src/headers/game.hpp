#pragma once
#include <map>
#include <string>
#include <raylib.h>

class Game {
    public:
        Game(int window_width, int window_height);
        void LoadAssets();
        void UnloadAssets();
        void HandleInput();
        void Update();
        void Render();
    private:
        int window_width;
        int window_height;
        std::map<std::string, Image> images;
        std::map<std::string, Texture2D> textures;
};