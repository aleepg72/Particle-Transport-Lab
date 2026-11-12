#include <cstddef>

#include "particle_transport/trajectory_io.hpp"


namespace particle_transport
{
    void writeSnapshot(std::ostream& output, const ParticleSystem& particleSystem, const double t)
    {
        for (std::size_t i{}; i < particleSystem.particles.size(); ++i)
        {
            output << t << ","
                   << i << ","
                   << particleSystem.particles[i].x << ","
                   << particleSystem.particles[i].y << '\n';
        }
    }
}
