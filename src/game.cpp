#include "headers/game.hpp"

Game::Game(int window_width, int window_height) {
    this->window_height = window_height;
    this->window_width = window_width;
}

void Game::LoadAssets() {
    const char *key = "background";
    images.insert(std::pair<std::string, Texture2D>(key, LoadTexture("src/assets/images/background.png")));
}

void Game::HandleInput() {
    // TODO
}

void Game::Update() {
    // TODO
}

void Game::Render() {
    BeginDrawing();
    ClearBackground(BLACK);
    
    DrawTexture(images["background"], 0, 0, (Color){255, 255, 255, 100});

    EndDrawing();
}

Game::~Game() {
    UnloadTexture(images["background"]);
}

