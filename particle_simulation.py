from ursina import *
import random
from time import sleep

class Particle:
    def __init__(self, position, velocity, mass):
        self.position = position
        self.velocity = velocity
        self.mass = mass

NUM_PARTICLES = 1

particles = []

def PrintParticles():
    for i in range(NUM_PARTICLES):
        print(f"particle[{i}] ({particles[i].position[0]}, {particles[i].position[1]})")

def InitializeParticles():
    for i in range(NUM_PARTICLES):
        particles.append(Particle(Vec2(random.randint(-16,16), 100), Vec2(0,0), 1))

def ComputeForce(particle):
    return Vec2(0, particle.mass * -9.81)

def RunSimulation():
    totalSimulationTime = 10
    currentTime = 0
    dt = 1

    InitializeParticles()
    PrintParticles()
    
    while currentTime < totalSimulationTime:
        sleep(dt)

        for i in range(NUM_PARTICLES):
            particle = particles[i]
            force = ComputeForce(particle)
            acceleration = Vec2(force[0] / particle.mass, force[1] / particle.mass)
            particle.velocity[0] += acceleration[0] * dt
            particle.velocity[1] += acceleration[1] * dt
            particle.position[0] += particle.velocity[0] * dt
            particle.position[1] += particle.velocity[1] * dt

        currentTime += dt
        PrintParticles()
    
if __name__=="__main__":
    RunSimulation()

