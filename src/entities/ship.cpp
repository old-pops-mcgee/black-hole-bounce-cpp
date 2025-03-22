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
    if(!this->isDead) {
        this->engineSpeed = std::min(this->MAX_ENGINE_SPEED, this->engineSpeed);

        // TODO: Play engine sound or stop engine sound
        
        if(this->pos.y < 0 || this->pos.y > this->game->getWindowHeight() || this->pos.x < 0 || this->pos.x > this->game->getWindowWidth()) {
            this->isDead = true;
            return;
        }

        // TODO: Check collisions with objects

        // TODO: Calculate the velocity updates from black holes
        
        // Calculate new position
        this->pos.x = cos(this->angle)*this->engineSpeed + this->pos.x;
        this->pos.y = sin(this->angle)*this->engineSpeed + this->pos.y;
        
        // Cap velocities so we don't get TOO crazy
        this->velocity.x += cos(this->angle)*this->engineSpeed + this->velocity.x;
        this->velocity.y += sin(this->angle)*this->engineSpeed + this->velocity.y;

        // Update the vapor trail
        std::vector<Vector3>::iterator it = vaporTrail.begin();
        std::cout << vaporTrail.size() << std::endl;
        while(it != vaporTrail.end()) {
            it->z -= 0.1f;
            if(it->z <= 0.01f) {
                it = vaporTrail.erase(it);
            } else {
                it++;
            }
        }

        // Add new vapor dots
        float vaporFudgeFactor = (getRandomFloat() - 0.5) * 8.0;
        float theta = (PI/2) - this->angle;
        Vector3 newVaporDot = Vector3 {
            this->pos.x - (this->texture->height + vaporFudgeFactor)*sin(theta)/2,
            this->pos.y - (this->texture->height + vaporFudgeFactor)*cos(theta)/2,
            this->engineSpeed / 2.0f
        };
        this->vaporTrail.push_back(newVaporDot);
    }
}

void Ship::increaseSpeed() {
    engineSpeed += 0.1f;
}

void Ship::decreaseSpeed() {
    engineSpeed -= 0.1f;
}

void Ship::turnRight() {
    angle += PI/60;
}

void Ship::turnLeft() {
    angle -= PI/60;
}