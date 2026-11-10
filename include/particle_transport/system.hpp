#pragma once

#include <vector>

#include "particle_transport/particle.hpp"


namespace particle_transport
{
    struct ParticleSystem
    {
        std::vector<particle_transport::Particle> particles;
        double D;
    };
}