#include "../headers/entities.hpp"

Ship::Ship(Game *game, Vector2 pos, float radius, Color color, Texture2D *texture) {
    this->game = game;
    this->pos = pos;
    this->radius = radius;
    this->color = color;
    this->angle = 0.0;
    this->texture = texture;
    this->velocity = Vector2{0.0, 0.0};
    this->engineSpeed = 0.0;
    this->isDead = false;
}

void Ship::render() {
    if(!this->isDead) {
        DrawTexturePro(
            *texture, 
            Rectangle{0, 0, this->texture->width * 1.0f, this->texture->height*1.0f},
            Rectangle{pos.x, pos.y, this->texture->width * 1.0f, this->texture->height*1.0f},
            Vector2{this->texture->width/2.0f, this->texture->height/2.0f},
            this->angle * (180 / PI) + 90,
            WHITE);
        for(Vector3 vaporDot : this->vaporTrail) {
            DrawCircle(vaporDot.x, vaporDot.y, vaporDot.z, Color{255, 95, 31, 100});
        }
    }
}

void Ship::update() {
    // TODO
}

void Ship::increaseSpeed() {
    engineSpeed += 0.1f;
}

void Ship::decreaseSpeed() {
    engineSpeed -= 0.1f;
}