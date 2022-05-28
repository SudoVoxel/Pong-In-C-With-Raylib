#include <raylib.h> 
#include <stdlib.h>




int main(void)
{
    
    const int screenWidth = 800;
    const int screenHeight = 450;
    const float playerSpeed = 5;
    int leftscore = 0;
    int rightscore = 0;
    

    InitWindow(screenWidth, screenHeight, "Pong!");

    Rectangle leftPaddle = { 100, 100, 15, 85 };
    Rectangle rightPaddle = { 700, 350, leftPaddle.width, leftPaddle.height };
    Rectangle PongBall = { screenWidth / 2, screenHeight / 2, 10, 10 };
    
    bool collisionWithPaddle, collisionWithWall = false;
    
    
    float rightSpeed = -6.0;
    float upSpeed = -0.5;
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    

    


    // Main game loop
    while (!WindowShouldClose())    
    {
        
        PongBall.x += rightSpeed;
        PongBall.y += upSpeed;

        
        
        if (IsKeyDown(KEY_UP)) rightPaddle.y -= playerSpeed;
        if (IsKeyDown(KEY_DOWN)) rightPaddle.y += playerSpeed;
        if (IsKeyDown(KEY_W)) leftPaddle.y -= playerSpeed;
        if (IsKeyDown(KEY_S)) leftPaddle.y += playerSpeed;


        //make sure our paddles dont go off screen
        if (leftPaddle.y < 0) {
            leftPaddle.y = 0;
        } 
        if (rightPaddle.y < 0) {
            rightPaddle.y = 0;
        }
        if (leftPaddle.y > 365) {
            leftPaddle.y = 365;
        }
        if (rightPaddle.y > 365) {
            leftPaddle.y = 365;
        }

        

        
        

        
        collisionWithWall = PongBall.y == 445 || PongBall.y == 15;
        collisionWithPaddle = CheckCollisionRecs(PongBall, leftPaddle) || CheckCollisionRecs(PongBall, rightPaddle);
        if (collisionWithPaddle) {
            rightSpeed *= -1;
            

        } 
        if (collisionWithWall) {
            upSpeed *= -1;
        }
        
        
        BeginDrawing();

        ClearBackground(BLACK);

        
        DrawText(TextFormat("%i,%i", leftscore, rightscore), screenWidth / 2, 10, 20, WHITE);
        
        
        DrawRectangleRec(leftPaddle, WHITE);
        DrawRectangleRec(rightPaddle, WHITE);

        if (PongBall.x > 0 && PongBall.x < screenWidth) {
            DrawRectangleRec(PongBall, WHITE);
        } else {
            if (PongBall.x < 0) {
                leftscore++;
            } else {
                rightscore++;
            }
            
            //Calculate if the ball should go left or right
            

            DrawRectangleRec(PongBall, collisionWithPaddle? RED : WHITE);
            PongBall.x = screenWidth / 2;
            PongBall.y = screenHeight / 2;
            rightSpeed = -6.0f;
            upSpeed = -0.5;
            
        }
        


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

