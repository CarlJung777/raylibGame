#include "raylib.h"

int main(void)
{
    // 初始化窗口
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Multiple Shaders Example");

    // 加载图像并转换为纹理
    Image image = LoadImage("resources/dice.png");  // 自定义路径
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);  // 纹理已加载，卸载原始图像

    // 加载 Shader
    Shader grayscaleShader = LoadShader(0, "shaders/grayscale.fs");
    Shader blurShader = LoadShader(0, "shaders/blur.fs");

    // 设置模糊 Shader 的模糊强度参数
    float blurAmount = 5.0f;
    SetShaderValue(blurShader, GetShaderLocation(blurShader, "blurAmount"), &blurAmount, SHADER_UNIFORM_FLOAT);

    // 控制变量
    bool useGrayScale = true;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // 切换 Shader
        if (IsKeyPressed(KEY_UP)) useGrayScale = true;
        if (IsKeyPressed(KEY_DOWN)) useGrayScale = false;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (useGrayScale)
        {
            BeginShaderMode(grayscaleShader);
            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
            EndShaderMode();
        }
        else
        {
            BeginShaderMode(blurShader);
            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
            EndShaderMode();
        }

        DrawText("Press UP for Grayscale, DOWN for Blur", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // 卸载 Shader 和纹理
    UnloadShader(grayscaleShader);
    UnloadShader(blurShader);
    UnloadTexture(texture);

    CloseWindow();
    return 0;
}
