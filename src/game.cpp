#include "headers/game.hpp"
#include "headers/raylib_utils.hpp"
#include <iostream>
#include <vector>

Game::Game(int window_width, int window_height) {
    this->window_height = window_height;
    this->window_width = window_width;
}

void Game::LoadAssets() {
    // Load in visuals
    std::vector<std::string> asset_names = {"ship", "star", "asteroid", "black_hole", "background"};
    for(std::string key : asset_names) {
        // Load the image
        images.insert(std::pair<std::string, Image>(key, LoadImage((BASE_IMG_PATH + key + ".png").c_str())));

        // From the image, recolor and then load texture
        textures.insert(std::pair<std::string, Texture2D>(key, UtilLoadImageToTexture(&images[key])));
    }
    
}

void Game::UnloadAssets() {
    // Unload the textures
    for (const auto &texturePair : textures) {
        UnloadTexture(texturePair.second);
    }

    // Unload the underlying images
    for (const auto &imagePair : images) {
        UnloadImage(imagePair.second);
    }
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
    
    DrawTexture(textures["background"], 0, 0, (Color){255, 255, 255, 100});

    EndDrawing();
}

