#pragma once

#include <vector>

#include "particle_transport/particle.hpp"


namespace particle_transport
{
    struct ParticleSystem
    {
        std::vector<Particle> particles{500, Particle{0.0, 0.0}};
        double D{3};
    };
}
