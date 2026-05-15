#include "raylib.h"

#define WIDTH 800
#define HEIGHT 700

// Particle Data
typedef struct{
    float coord_x , coord_y, radius, vel_x , vel_y;
}Particle;


// Updates Particle Position on Screen
void MoveParticle(Particle *particle){
    particle->coord_x += particle->vel_x;
    particle->coord_y += particle->vel_y;

    float coord_x = particle->coord_x;
    float coord_y = particle->coord_y;
    float radius = particle->radius;

    if (coord_x - radius <0){
        particle->coord_x = -particle->coord_x;
    }
    if (coord_x + radius > WIDTH){
        particle->coord_x = -particle->coord_x;
    }
    if (coord_y - radius < 0){
        particle->coord_y = -particle->coord_y;
    }
    if (coord_y + radius > HEIGHT){
        particle->coord_y = -particle->coord_y;
    }

}


// Draws the Particle on Screen

void ParticleDraw(Particle *particle){
    DrawCircle(particle->coord_x,particle->coord_y,
               particle->radius,RED);
}





int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Particle Simulation");
    SetTargetFPS(60);

    Particle particle = {250, 250 , 35 , -5 , -5};

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(GRAY);
            MoveParticle(&particle);
            ParticleDraw(&particle);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}