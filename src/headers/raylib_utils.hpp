#pragma once
#include <raylib.h>
#include <string>
#include <math.h>

Texture2D UtilLoadImageToTexture(Image *img);
float getRandomFloat(); // reimplementation of python's random.random()

const std::string BASE_IMG_PATH = "assets/images/";
const std::string BASE_SOUND_PATH = "assets/sound/";
const Color COLOR_KEY = (Color){255, 174, 201, 255};