#pragma once

#include <random>

#include "particle_transport/particle_system.hpp"


namespace particle_transport
{
    struct Simulation
    {
        double dt{0.1};
        double t{0};
        
        std::mt19937 gen{std::random_device{}()};
        std::normal_distribution<double> dist{0.0, 1.0};
        
        void setSeed(unsigned int s);
        void step(ParticleSystem& particleSystem);
    };
}
