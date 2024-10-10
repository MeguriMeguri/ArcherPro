#include<iostream>
#include "raylib.h"
#include "game.h"

void AppInit();

static float scale;
static RenderTexture2D target;
static Rectangle virtualSource;
static Rectangle virtualDest;
static Vector2 virtualOrigin;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Your Game Title");
    GameInitialize();
    AppInit();

    while (!WindowShouldClose()) {
        BeginTextureMode(target);
        GameDraw();
        EndTextureMode();

        GameUpdate();
        BeginDrawing();
        DrawTexturePro(target.texture, virtualSource, virtualDest, virtualOrigin, 0.0f, WHITE);
        EndDrawing();
    }

    GameDeInitialize();

    return 0;
}

void AppInit() {
    scale = MIN((float)GetScreenWidth() / VSCREEN_WIDTH, (float)GetScreenHeight() / VSCREEN_HEIGHT);
    std::cout << scale << "\n";
    target = LoadRenderTexture(VSCREEN_WIDTH, VSCREEN_HEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    virtualSource = { 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height };
    virtualDest = { 0, 0, (float)VSCREEN_WIDTH * scale, (float)VSCREEN_HEIGHT * scale };
    virtualOrigin = { 0, 0 };
}
