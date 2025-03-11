#include "headers/game.hpp"
#include "headers/raylib_utils.hpp"
#include <iostream>
#include <vector>

Game::Game(int windowWidth, int windowHeight, bool playMusic) {
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;
    this->playMusic = playMusic;
    this->state = START;

    LoadAssets();

}

void Game::LoadAssets() {
    // Load in visuals
    for(std::string key : {"ship", "star", "asteroid", "black_hole", "background"}) {
        // Load the image
        images.insert(std::pair<std::string, Image>(key, LoadImage((BASE_IMG_PATH + key + ".png").c_str())));

        // From the image, recolor and then load texture
        textures.insert(std::pair<std::string, Texture2D>(key, UtilLoadImageToTexture(&images[key])));
    }

    // Add in the icon image (don't need a texture here)
    images.insert(std::pair<std::string, Image>("icon", LoadImage((BASE_IMG_PATH + "icon.png").c_str())));
    SetWindowIcon(images["icon"]);

    // Load in audio
    for(std::string key : {"explosion", "engine"}) {
        sounds.insert(std::pair<std::string, Sound>(key, LoadSound((BASE_SOUND_PATH + key + ".wav").c_str())));
    }

    // Load audio stream and kick off
    stream = LoadMusicStream((BASE_SOUND_PATH + "music.wav").c_str());
    stream.looping = true;

    if(playMusic && IsMusicValid(stream)) {
        PlayMusicStream(stream);
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

    // Unload the sound
    for (const auto &soundPair : sounds) {
        UnloadSound(soundPair.second);
    }

    // Unload the music
    UnloadMusicStream(stream);
}

void Game::ReloadGameComponents() {
    // TODO
}

void Game::HandleInput() {
    // TODO
}

void Game::Update() {
    if(playMusic && IsMusicValid(stream)) {
        UpdateMusicStream(stream);
    }
}

void Game::Render() {
    BeginDrawing();
    ClearBackground(BLACK);
    
    DrawTexture(textures["background"], 0, 0, (Color){255, 255, 255, 100});

    EndDrawing();
}

