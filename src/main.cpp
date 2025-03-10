#include <stdio.h>
#include <raylib.h>
#include "headers/game.hpp"

int WINDOW_HEIGHT = 972;
int WINDOW_WIDTH = 1728;

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Black Hold Bounce");
    SetTargetFPS(60);
    Game game = Game(WINDOW_WIDTH, WINDOW_HEIGHT);
    game.LoadAssets();

    while(!WindowShouldClose()) {
        game.HandleInput();
        game.Update();
        game.Render();
    }

    game.UnloadAssets();
    CloseWindow();
}