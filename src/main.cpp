#include <stdio.h>
#include <raylib.h>
#include <iostream>
#include <string.h>
#include "headers/game.hpp"

int WINDOW_HEIGHT = 972;
int WINDOW_WIDTH = 1728;

int main(int argc, char** argv) {
    // Process command line args
    bool playMusic = true;
    int i = 0;
    while (i < argc) {
        std::cout << argv[i] << std::endl;
        if (strcmp(argv[i], "nomusic") == 0) {
            playMusic = false;
        }
        i++;
    }

    // Set up raylib
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Black Hole Bounce");
    InitAudioDevice();
    SetAudioStreamBufferSizeDefault(4096);
    SetTargetFPS(60);
    Game game = Game(WINDOW_WIDTH, WINDOW_HEIGHT, playMusic);

    while(!WindowShouldClose()) {
        game.HandleInput();
        game.Update();
        game.Render();
    }

    game.UnloadAssets();
    CloseAudioDevice();
    CloseWindow();
}