#include <cstddef>
#include <cmath>

#include "particle_transport/simulation.hpp"

namespace particle_transport
{
    void Simulation::step(ParticleSystem& particleSystem)
    {
        const double B{std::sqrt(2 * particleSystem.D * dt)};
    
        const std::size_t N{particleSystem.particles.size()};
    
        for (std::size_t i{}; i < N; ++i)
        {
            double dx{B * dist(gen)};
            double dy{B * dist(gen)};
    
            particleSystem.particles[i].x += dx;
            particleSystem.particles[i].y += dy;
        }
    
        t += dt;
    }


    void Simulation::setSeed(unsigned int s)
    {
        gen.seed(s);
        dist.reset();
    }
}

