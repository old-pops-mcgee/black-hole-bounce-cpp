#pragma once
#include <raylib.h>
#include <string>

Texture2D UtilLoadImageToTexture(Image *img);

const std::string BASE_IMG_PATH = "assets/images/";
const Color COLOR_KEY = (Color){255, 174, 201, 255};