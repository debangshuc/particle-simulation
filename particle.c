#include "raylib.h"

#define WIDTH 800
#define HEIGHT 700


typedef struct{
    float coord_x , coord_y, radius, vel_x , vel_y;
}Particle;


void ParticleDraw(Particle *particle){
    DrawCircle(particle->coord_x,particle->coord_y,
               particle->radius,RED);
}



int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Particle Simulation");
    SetTargetFPS(60);

    Particle particle = {300 , 300 , 35 , -5 , -5};

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(GRAY);
            
            ParticleDraw(&particle);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}