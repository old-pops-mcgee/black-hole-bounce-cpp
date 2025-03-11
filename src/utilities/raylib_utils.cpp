#include "../headers/raylib_utils.hpp"

Texture2D UtilLoadImageToTexture(Image *img) {
    ImageColorReplace(img, COLOR_KEY, BLANK);
    Texture2D texture = LoadTextureFromImage(*img);
    return texture;
}

/**
 * Returns a random float value between 0.0 and 1.0;
 * A basic reimplementation of python's random.random()
 * 
 * @return Random float value in the range [0.0, 1.0]
 */
float getRandomFloat() {
    return ((float) rand() / (RAND_MAX));
}