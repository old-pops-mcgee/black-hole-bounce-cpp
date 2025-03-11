#include "../headers/entities.hpp"

Explosion::Explosion(Vector2 pos, float angle, float speed) {    
    this->pos = pos;
    this->angle = angle;
    this->speed = speed;

    this->color = colorChoice[rand() % colorChoice.size()];
    this->shouldKill = false; // Set to true once it's done, and the cluster will remove it
}

void Explosion::update() {
    if(!shouldKill) {
        pos.x += cos(angle) * speed;
        pos.y += sin(angle) * speed;

        speed = std::max(0.0, speed - 0.1);
        if(speed <= 0.0) {
            shouldKill = true;
        }
    }
}

void Explosion::render() {
    std::vector<Vector2> renderPoints = {
        Vector2 {
            pos.x + cos(angle)*speed*(rand() % 4 + 2),
            pos.y + sin(angle)*speed*(rand() % 4 + 2)
        },
        Vector2 {
            pos.x + cos(angle+PI*0.5f)*speed*(rand() % 4 + 2),
            pos.y + sin(angle+PI*0.5f)*speed*(rand() % 4 + 2)
        },
        Vector2 {
            pos.x + cos(angle+PI)*speed*(rand() % 4 + 2),
            pos.y + sin(angle+PI)*speed*(rand() % 4 + 2)
        },
        Vector2 {
            pos.x + cos(angle+PI*1.5f)*speed*(rand() % 4 + 2),
            pos.y + sin(angle+PI*1.5f)*speed*(rand() % 4 + 2)
        },
    };

    DrawTriangle(renderPoints[0], renderPoints[3], renderPoints[1], color);
    DrawTriangle(renderPoints[2], renderPoints[1], renderPoints[3], color);
}

bool Explosion::getShouldKill() {
    return shouldKill;
}

