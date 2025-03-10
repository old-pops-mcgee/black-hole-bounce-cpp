#include "../headers/raylib_utils.hpp"

Texture2D UtilLoadImageToTexture(Image *img) {
    ImageColorReplace(img, COLOR_KEY, BLANK);
    Texture2D texture = LoadTextureFromImage(*img);
    return texture;
}