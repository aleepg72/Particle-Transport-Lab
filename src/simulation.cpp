#include <cmath>

#include "particle_transport/simulation.hpp"

namespace pt = particle_transport;


void pt::Simulation::step(pt::ParticleSystem& particleSystem)
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