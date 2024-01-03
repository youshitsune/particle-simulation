use std::io;

pub struct Vector2{
    x: f32,
    y: f32,
}

pub struct Particle{
    pos: Vector2,
    vel: Vector2,
}

pub const G: f32 = 9.81;

impl Particle{
    pub fn print_particle(&self){
        println!("X: {}  Y: {}", self.pos.x, self.pos.y);
    }
    pub fn run_particle(&mut self, t: i32){
        self.pos.x = (self.vel.x*t as f32)+((G*t as f32*t as f32)/2.0);
        if ((self.vel.y*t as f32)-((G*t as f32*t as f32)/2.0) <= 0.0){
            self.pos.y = 0; 
        }
        else{
            self.pos.y = (self.vel.y*t as f32)-((G*t as f32*t as f32)/2.0);
        }
    }
}

fn take_input(prompt: &str) -> i32 {
    let mut input = String::new();
    println!("{}", prompt);
    io::stdin().read_line(&mut input).expect("Error: taking input");
    let n: i32  = input.trim().parse().unwrap();
    return n;
}

fn main(){
    let n = take_input("Type in number of particles: ");
    let mut particles: Vec<Particle> = vec![];
    for i in 0..n{
        particles.push(Particle{pos: Vector2 {x: take_input("Type in X of particle: ") as f32, y: take_input("Type in Y of particle: ") as f32}, vel: Vector2 {x: take_input("Type in X speed of particle: ") as f32, y: take_input("Type in Y speed of particle: ") as f32,}});
    } 
    let t = take_input("Type in time for running this simulation: ");
    for i in &mut particles{
        i.print_particle();
        i.run_particle(t);
        i.print_particle();
    }
}
