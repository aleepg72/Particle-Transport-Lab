#pragma once

#include <ostream>

#include "particle_transport/particle_system.hpp"


namespace particle_transport
{
    void writeSnapshot(std::ostream& output, const ParticleSystem& particleSystem, const double t);
}
