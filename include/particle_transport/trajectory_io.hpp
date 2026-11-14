#pragma once

#include <filesystem>
#include <fstream>
#include <ostream>
#include <system_error>

#include "particle_transport/particle_system.hpp"


namespace particle_transport
{
    inline const std::filesystem::path defaultOutputPath{"data/trajectories.csv"};

    bool initialiseTrajectoryFile(
        std::ofstream& output,
        const std::filesystem::path& path,
        std::error_code& error
    );

    bool writeSnapshot(
        std::ostream& output,
        const ParticleSystem& particleSystem,
        const double t,
        std::error_code& error
    );

    bool closeTrajectoryFile(
        std::ofstream& output,
        std::error_code& error
    );
}
