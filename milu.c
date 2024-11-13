#include "raylib.h"
#include <stdbool.h>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "milu");
    
    // 加载着色器
    Texture2D texture = LoadTexture("resources/dice.png");
    Shader shader = LoadShader(0, "grayshader.glsl");
    
    
    bool useShader = false;
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_UP)) {
            useShader = true;
        }
        
        if (IsKeyPressed(KEY_DOWN)) {
            useShader = false;
        }
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BEIGE);
            
           // 开始应用 Shader 模式
           if (useShader) {
               BeginShaderMode(shader);
           }
           
           DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);    
          
           // 结束 Shader 模式
            if (useShader) {
                EndShaderMode();  
            }
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadShader(shader);
    UnloadTexture(texture);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}