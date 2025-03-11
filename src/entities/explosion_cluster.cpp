#include "../headers/entities.hpp"

ExplosionCluster::ExplosionCluster(Game *game, Vector2 pos, int explosionCount) {
    this->game = game;
    this->pos = pos;
    
    for(int i = 0; i < explosionCount; i++) {
        Vector2 explosionCenter = Vector2{
            .x = pos.x + rand() % 10 - 5,
            .y = pos.y + rand() % 10 - 5
        };
        Explosion explosion = Explosion{
            explosionCenter,
            getRandomFloat() * 2 * PI, 
            getRandomFloat() * 5.0f
        };
        explosions.push_back(&explosion);
    }
 }

 void ExplosionCluster::update() {
    std::vector<Explosion *>::iterator explosionIterator;

    for(explosionIterator = explosions.begin(); explosionIterator != explosions.end();) {
        Explosion explosion = **explosionIterator;
        explosion.update();
        if (explosion.getShouldKill()) {
            explosionIterator = explosions.erase(explosionIterator);
        } else {
            explosionIterator++;
        }
    }
 }

 void ExplosionCluster::render() {
    for(Explosion *explosion : explosions) {
        explosion->render();
    }
 }