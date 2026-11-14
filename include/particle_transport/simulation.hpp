#pragma once

#include <cstddef>
#include <random>

#include "particle_transport/particle_system.hpp"


namespace particle_transport
{
    struct Simulation
    {
        // parameters
        std::size_t nSteps{100};
        double dt{0.1};

        // state
        double t{0.0};
        
        // utility
        std::mt19937 gen{std::random_device{}()};
        std::normal_distribution<double> dist{0.0, 1.0};
        
        void setSeed(unsigned int s);
        void step(ParticleSystem& particleSystem);
    };
}
