#include <iostream>

#include "particle_transport/particle.hpp"
#include "particle_transport/system.hpp"


int main()
{
    particle_transport::ParticleSystem particleSystem;

    // positions
    particleSystem.particles.resize(3);
    particleSystem.particles[0] = {0.0, 0.0};
    particleSystem.particles[1] = {1.0, 1.0};
    particleSystem.particles[2] = {2.0, 2.0};

    // diffusion coefficient
    particleSystem.D = 3.0;


    std::cout << particleSystem.particles.size() << " particles with positions:\n";
    for (std::size_t i{}; i < particleSystem.particles.size(); ++i)
    {
        std::cout << "(" << particleSystem.particles[i].x << ", " << particleSystem.particles[i].y << ")\n";
    }
    std::cout << "and diffusion coefficient D = " << particleSystem.D << '\n';

    return 0;
}
