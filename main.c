#include <raylib.h>

int main(void)
{
    // Initialize full-screen window
    InitWindow(0, 0, "Lumberjack Game");
    ToggleFullscreen();

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    // Load character textures
    Texture2D char_left = LoadTexture("mychar21.png");
    Texture2D char_right = LoadTexture("mychar22.png");

    Texture2D currentChar = char_right; // start facing right

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Input: switch side
        if (IsKeyDown(KEY_LEFT))
            currentChar = char_left;
        else if (IsKeyDown(KEY_RIGHT))
            currentChar = char_right;

        BeginDrawing();
        ClearBackground((Color){ 120, 180, 255, 255 }); // sky blue

        // Tree rectangle in center
        float treeWidth = 60;
        float treeHeight = screenHeight * 0.6f;
        float treeX = (screenWidth - treeWidth) / 2.0f;
        float treeY = screenHeight - treeHeight - 10.0f;

        DrawRectangle(treeX, treeY, treeWidth, treeHeight, (Color){ 139, 69, 19, 255 }); // brown trunk

        // Ground
        DrawRectangle(0, screenHeight - 60, screenWidth, 60, (Color){ 34, 139, 34, 255 }); // grass

        // Character positions
        float offset = 15.0f; // distance from center
        float posY = screenHeight - currentChar.height - 60; // on top of grass
        float posX;

        if (currentChar.id == char_left.id)
            posX = (screenWidth / 2.0f) - offset - currentChar.width;
        else
            posX = (screenWidth / 2.0f) + offset;

        DrawTexture(currentChar, posX, posY, WHITE);

        EndDrawing();
    }

    UnloadTexture(char_left);
    UnloadTexture(char_right);
    CloseWindow();

    return 0;
}



