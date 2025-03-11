#include "../headers/entities.hpp"

Explosion::Explosion(ExplosionCluster *cluster, Vector2 pos, float angle, float speed) {    
    this->cluster = cluster;
    this->pos = pos;
    this->angle = angle;
    this->speed = speed;

    this->color = colorChoice[rand() % colorChoice.size()];
}

void Explosion::update() {
    pos.x += cos(angle) * speed;
    pos.y += sin(angle) * speed;

    speed = std::max(0.0, speed - 0.1);
    if(speed <= 0.0) {
        // TODO: Remove self from cluster
    }
}

void Explosion::render() {
    std::vector<Vector2> renderPoints = {
        Vector2 {
            pos.x + cos(angle)*speed*(rand() % 4 + 2),
            pos.y + sin(angle)*speed*(rand() % 4 + 2)
        }
    };
}

