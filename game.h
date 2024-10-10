
#pragma once
#include "raylib.h"
#include <vector>

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define VSCREEN_WIDTH 320
#define VSCREEN_HEIGHT 180

// Function prototypes
void GameInitialize();
void GameUpdate();
void GameDraw();
void GameDeInitialize();

// Arrow class
class Arrow {
public:
    Vector2 position;
    Vector2 speed;
    bool isReleased;
    Texture2D arrowTexture;

    Arrow(Vector2 pos, Texture2D texture);
    void drawArrow();
    void updateArrow();
    void reset();
};

// Balloon class
class Balloon {
public:
    Vector2 position;
    bool isHit;
    Texture2D balloonTexture;
    float speedY;

    Balloon(Vector2 pos, Texture2D texture);
    void updateBalloon();
    bool checkCollision(Vector2 arrowPos);
};
