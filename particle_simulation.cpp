#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    float x;
    float y;
} Vector2;

class Particle{
    public:
        void PrintParticle();
        void DefineParticle(Vector2 pos, Vector2 vel);
        void RunParticle(int t);
        Vector2 position;
        Vector2 velocity;
};

void Particle::PrintParticle(){
    cout << " X: " << this->position.x << " Y: " << this->position.y << '\n';
}

void Particle::DefineParticle(Vector2 pos, Vector2 vel){
    this->position.x = pos.x;
    this->position.y = pos.y;
    this->velocity.x = vel.x;
    this->velocity.y = vel.y;
}

void Particle::RunParticle(int t){
    this->position.x+=(this->velocity.x*t);
    this->position.y+=(this->velocity.y*t);
}

int main(){
    int n;
    cout << "Type in number of particles: ";
    cin >> n;
    vector<Particle> particles;
    float pos[2];
    float vel[2];
    int t;
    cout << "Type in time for running this simulation: ";
    cin >> t;
    for (int i = 0; i < n; i++){
        cout << "Type in cords of particle: ";
        cin >> pos[0] >> pos[1];
        cout << "Type in velocity of particle: ";
        cin >> vel[0] >> vel[1];
        Particle particle;
        particle.DefineParticle((Vector2){pos[0], pos[1]}, (Vector2){vel[0], vel[1]});
        particles.push_back(particle);
    }
    for (Particle particle: particles){
        particle.PrintParticle();
        particle.RunParticle(t);
        particle.PrintParticle();
    }
}
