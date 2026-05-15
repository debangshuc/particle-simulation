#include "raylib.h"
#include <time.h>

#define NUM 5
#define WIDTH 900
#define HEIGHT 600

// Particle Data
typedef struct{
    float coord_x , coord_y, radius, vel_x , vel_y;
}Particle;

Particle arr_particle[NUM];



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


void ParticlesVelocityUpdate(){
    for(int i= 0; i<NUM ; i++){
        MoveParticle(arr_particle+i);
    }
}



// Draws the Particle on Screen

void ParticleDraw(Particle *particle){
    DrawCircle(particle->coord_x,particle->coord_y,
               particle->radius,RED);
}


void ParticlesDraw(){
    for(int i=0 ; i<NUM ; i++){
        ParticleDraw(arr_particle+i);
    }
}





void CreateParticles(){

    SetRandomSeed(time(NULL));

    float radius;
    for(int i=0 ; i<NUM ; i++){
        radius = GetRandomValue(10,15);
        arr_particle[i].radius = radius;
        arr_particle[i].coord_x = GetRandomValue(radius,WIDTH - radius);
        arr_particle[i].coord_y = GetRandomValue(radius , HEIGHT- radius);
        arr_particle[i].vel_x = GetRandomValue(-6,7);
        arr_particle[i].vel_y = GetRandomValue(-6,7);
    }
}

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Particle Simulation");
    SetTargetFPS(60);

    CreateParticles();

    

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            ParticlesVelocityUpdate();
            ParticlesDraw();
            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}