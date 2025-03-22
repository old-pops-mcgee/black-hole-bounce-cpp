#pragma once
#include <raylib.h>
#include "game.hpp"
#include <vector>
#include <cstdlib>
#include <math.h>
#include "raylib_utils.hpp"
#include <algorithm>
#include <iostream>

class Game;
class Entity;
class Asteroid;
class BlackHole;
class Explosion;
class ExplosionCluster;
class Ship;
class Star;

class Entity {
    public:
        virtual void render() = 0;
        virtual void update() = 0;
};

class Asteroid : public Entity {
    public:
        Asteroid(Game *game, Vector2 pos, float radius, Texture2D *texture, Vector2 velocity);
        Vector2 getCollisionCircle();
    private:
        Game *game;
        Vector2 pos;
        float radius;
        Texture2D *texture;
        Vector2 velocity;
        std::vector<Vector3> vaporTrail;
};

class BlackHole : public Entity {
    public:
        BlackHole(Game *game, Vector2 pos, float radius, Texture2D *texture);
        Vector2 calculateForceOnObject(float objectX, float objectY);
    private:
        const float STANDARD_FORCE = 2500.0;
        const float FUDGE_FACTOR = 3.5;
        const float DECAYING_FORCE_ADDER = 20.0;
        const float DECAY_RATE = 0.25;
        const float RENDER_SCALE = 3.5;

        Game *game;
        Vector2 pos;
        float initialRadius;
        float radius;
        float force;
        int level;
        float deathRadius;
        Texture2D *texture;
        float angle;
        int turningDirection;
        float rotationSpeed;
};

class ExplosionCluster : public Entity {
    public:
        ExplosionCluster(Game *game, Vector2 pos, int explosionCount);
        void update();
        void render();
    private:
        Game *game;
        Vector2 pos;
        std::vector<Explosion *> explosions;
};

class Explosion : public Entity {
    public:
        Explosion(Vector2 pos, float angle, float speed);
        void update();
        void render();
        bool getShouldKill();
    private:
        const std::vector<Color> colorChoice = {RED, ORANGE, YELLOW, GOLD};
        Vector2 pos;
        float angle;
        float speed;
        Color color;
        bool shouldKill;
};

class Ship : public Entity {
    public:
        Ship(Game *game, Vector2 pos, float radius, Color color, Texture2D *texture);
        void render();
        void update();
        void increaseSpeed();
        void decreaseSpeed();
        void turnRight();
        void turnLeft();
    private:
        const float MAX_SPEED = 5.0;
        const float MAX_ENGINE_SPEED = 50.0;
        Game *game;
        Vector2 pos;
        float radius;
        Color color;
        float angle;
        Texture2D *texture;
        Vector2 velocity;
        float engineSpeed;
        std::vector<Vector3> vaporTrail;
        bool isDead;        
};

class Star : public Entity {
    public:
        Star(Game *game, Vector2 pos, float radius, Texture2D *texture);
    private:
        Game *game;
        Vector2 pos;
        float radius;
        Texture2D *texture;
        float angle;
        int turningDirection;
        int timeToDetonation;
        int detonationCounter;
};