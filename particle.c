#include "raylib.h"

#define WIDTH 900
#define HEIGHT 600

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


    //Collision on Walls Logic
    if (coord_x - radius <0){

        particle->coord_x = radius;
        particle->vel_x= -particle->vel_x;
    }
    if (coord_x + radius > WIDTH){

        particle->coord_x = WIDTH - radius;
        particle->vel_x = -particle->vel_x;
    }
    if (coord_y - radius < 0){

        particle->coord_y = radius;
        particle->vel_y= -particle->vel_y;
    }
    if (coord_y + radius > HEIGHT){

        particle->coord_y = HEIGHT - radius;
        particle->vel_y = -particle->vel_y;
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

    Particle particle = {300, 300 , 40 , -5 , 7};

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