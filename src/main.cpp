#include <cstddef>
#include <fstream>
#include <iostream>
#include <system_error>

#include "particle_transport/particle_system.hpp"
#include "particle_transport/simulation.hpp"
#include "particle_transport/trajectory_io.hpp"

int main()
{
    particle_transport::ParticleSystem particleSystem;

    // simulation parameters and seeding
    particle_transport::Simulation simulation;
    simulation.setSeed(1);

    // generate output file
    std::ofstream output;
    std::error_code error;

    if (!particle_transport::initialiseTrajectoryFile(output, particle_transport::defaultOutputPath, error))
    {
        std::cerr << "Failed to initialise output file. " << error.message() << '\n';

        return 1;
    }

    // write initial position
    if (!particle_transport::writeSnapshot(output, particleSystem, simulation.t, error))
    {
        std::cerr << "IO Error. " << error.message() << '\n'
                  << "Closing file...\n";

        if (!particle_transport::closeTrajectoryFile(output, error))
        {
            std::cerr << "IO Error. " << error.message() << '\n';
        }

        return 1;
    }

    // run simulation
    for (std::size_t i{}; i < simulation.nSteps; ++i)
    {
        simulation.step(particleSystem);

        if (!particle_transport::writeSnapshot(output, particleSystem, simulation.t, error))
        {
            std::cerr << "IO Error. " << error.message() << '\n'
                    << "Closing file...\n";

            if (!particle_transport::closeTrajectoryFile(output, error))
            {
                std::cerr << "IO Error. " << error.message() << '\n';
            }

            return 1;
        }
    }

    if (!particle_transport::closeTrajectoryFile(output, error))
    {
        std::cerr << "Failed closing file: " << error.message() << '\n';

        return 1;
    }

    return 0;
}
