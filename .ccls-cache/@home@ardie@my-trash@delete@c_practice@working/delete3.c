
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>
#include <fcntl.h>
#include <inttypes.h>


#include <raylib.h>



/*******************************************************************************************
*
*   raylib [textures] example - sprite explosion
*
*   Example complexity rating: [★★☆☆] 2/4
*
*   Example originally created with raylib 2.5, last time updated with raylib 3.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/


#define NUM_FRAMES_PER_LINE     5
#define NUM_LINES               5

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite explosion");

    InitAudioDevice();

    // Load explosion sound


    // Load explosion texture
    Texture2D explosion = LoadTexture("./explosion.png");

    // Init variables for animation
    float explosionWidth = (float)explosion.width/NUM_FRAMES_PER_LINE*4;   // Sprite one frame rectangle width
    float explosionHeight = (float)explosion.height/NUM_LINES*4;           // Sprite one frame rectangle height
    int currentFrame = 0;
    int currentLine = 0;

    Rectangle frameRec = { 0, 0, explosionWidth, explosionHeight };
    Vector2 position = { 0.0f, 0.0f };

    bool active = false;
    int framesCounter = 0;

    



    SetTargetFPS(10);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Check for mouse button pressed and activate explosion (if not active)
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !active)
        {
            position = GetMousePosition();
            active = true;

            position.x -= explosionWidth/2.0f;
            position.y -= explosionHeight/2.0f;


        }

        // Compute explosion animation frames
	// extremely ugly loop here, mostly just to mimic, some kind of "nervous" movement
        if (active)
        {
            framesCounter++;

            if (framesCounter > 2)
            {
                currentFrame++;

                if (currentFrame >= NUM_FRAMES_PER_LINE)
                {
                    currentFrame = 0;
                    currentLine++;

                    if (currentLine >= NUM_LINES)
                    {
                        currentLine = 0;
                        active = false;
                    }
                }

                framesCounter = 0;
            }
        }

        frameRec.x = explosionWidth*currentFrame ;
        frameRec.y = explosionHeight*currentLine ;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw explosion required frame rectangle
            if (active) DrawTextureRec(explosion, frameRec, position, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(explosion);   // Unload texture


    CloseAudioDevice();

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
