#pragma once

#include <vector>

#include "particle_transport/particle.hpp"


namespace particle_transport
{
    struct ParticleSystem
    {
        std::vector<Particle> particles;
        double D;
    };
}