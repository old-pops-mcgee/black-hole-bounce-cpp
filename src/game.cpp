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
    ReloadGameComponents();
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
    this->ship = new Ship(this, Vector2{this->windowWidth / 2.0f, this->windowHeight / 2.0f}, 5.0f, YELLOW, &this->textures["ship"]);
}

void Game::HandleInput() {
    if (this->state == PLAY) {
        if (IsKeyDown(KEY_RIGHT)) {
            this->ship->turnRight();
        }
        if (IsKeyDown(KEY_LEFT)) {
            this->ship->turnLeft();
        }
        if (IsKeyDown(KEY_UP)) {
            this->ship->increaseSpeed();
        }
        if (IsKeyDown(KEY_DOWN)) {
            this->ship->decreaseSpeed();
        }
    } else {
        if(IsKeyPressed(KEY_SPACE)){
            ReloadGameComponents();
            this->state = PLAY;
        }
    }
}

void Game::Update() {
    if(playMusic && IsMusicValid(stream)) {
        UpdateMusicStream(stream);
    }

    if (this->state == PLAY) {
        this->ship->update();
    }
}

void Game::Render() {
    BeginDrawing();
    ClearBackground(BLACK);
    
    DrawTexture(textures["background"], 0, 0, (Color){255, 255, 255, 100});

    if (this->state == PLAY) {
        this->ship->render();
    } else if (this->state == START) {
        DrawText("Black Hole Bounce", 600, 300, 64, RAYWHITE);
        DrawText("Stay Alive as Long as You Can!", 400, 350, 64, RAYWHITE);
        DrawText("Left/Right arrows: Turn", 600, 450, 48, RAYWHITE);
        DrawText("Up/Down arrows: Accelerate/Decelerate", 400, 500, 48, RAYWHITE);
        DrawText("Press Space to Start!", 520, 600, 64, RAYWHITE);
    } else if (this->state == RESTART) {
        // TODO: Update this with the actual score
        DrawText("Final Score: 0", 620, 300, 64, RAYWHITE);
        DrawText("Play Again?", 685, 350, 64, RAYWHITE);
        DrawText("Left/Right arrows: Turn", 600, 450, 48, RAYWHITE);
        DrawText("Up/Down arrows: Accelerate/Decelerate", 400, 500, 48, RAYWHITE);
        DrawText("Press Space to Start!", 520, 600, 64, RAYWHITE);

    }

    EndDrawing();
}

int Game::getWindowHeight() {
    return this->windowHeight;
}

int Game::getWindowWidth() {
    return this->windowWidth;
}

void Game::playSound(std::string soundName) {
    // TODO
}

