#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_PARTICLES 1

typedef struct{
    float x;
    float y;
} Vector2;

typedef struct{
    Vector2 position;
    Vector2 velocity;
    float mass;
} Particle;

Particle particles[NUM_PARTICLES];

void PrintParticles(){
    for (int i = 0; i < NUM_PARTICLES; i++){
        Particle *particle = &particles[i];
        printf("particle[%i] (%.2f, %.2f)\n", i, particle->position.x, particle->position.y);
    }
}

void InitializeParticles(){
    for (int i = 0; i < NUM_PARTICLES; i++){
        particles[i].position = (Vector2){arc4random_uniform(50), 100};
        particles[i].velocity = (Vector2){0, 0};
        particles[i].mass = 1;
    }

        particles[1].mass = 100;
}

Vector2 ComputeForce(Particle *particle){
    return (Vector2){0, particle->mass * -9.81};
}

void RunSimulation(){
    float totalSimulationTime = 10;
    float currentTime = 0;
    float dt = 1;

    InitializeParticles();
    PrintParticles();

    while (currentTime < totalSimulationTime){
        sleep(dt);

        for (int i = 0; i < NUM_PARTICLES; i++){
            Particle *particle = &particles[i];
            Vector2 force = ComputeForce(particle);
            Vector2 acceleration = (Vector2){force.x / particle->mass, force.y / particle->mass};
            particle->velocity.x += acceleration.x * dt;
            particle->velocity.y += acceleration.y * dt;
            particle->position.x += particle->velocity.x * dt;
            particle->position.y += particle->velocity.y * dt;
        }

        PrintParticles();
        currentTime += dt;
    }
}

void main(){
    RunSimulation();
}
