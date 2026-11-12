#include <iostream>
#include <fstream>
#include <filesystem>
#include <system_error>
#include <cstddef>

#include "particle_transport/particle_system.hpp"
#include "particle_transport/simulation.hpp"
#include "particle_transport/trajectory_io.hpp"

int main()
{
    particle_transport::ParticleSystem particleSystem;

    // positions
    particleSystem.particles.resize(3);
    particleSystem.particles[0] = {0.0, 0.0};
    particleSystem.particles[1] = {1.0, 1.0};
    particleSystem.particles[2] = {2.0, 2.0};

    // diffusion coefficient
    particleSystem.D = 3.0;

    std::cout << particleSystem.particles.size() << " particles with positions:\n";
    for (std::size_t i{}; i < particleSystem.particles.size(); ++i)
    {
        std::cout << "(" << particleSystem.particles[i].x << ", " << particleSystem.particles[i].y << ")\n";
    }
    std::cout << "and diffusion coefficient D = " << particleSystem.D << '\n';

    particle_transport::Simulation simulation;
    simulation.setSeed(1);

    // --- test ---

    // create output directory
    std::filesystem::path outputPath{"data/test.csv"};
    std::filesystem::path directory{outputPath.parent_path()};

    std::error_code errorCode;

    if (!directory.empty())
    {
        std::filesystem::create_directories(directory, errorCode);

        if (errorCode)
        {
            std::cerr << "Failed to create output directory: "
                      << errorCode.message() << '\n';

            return 1;
        }
    }

    std::ofstream output{outputPath};

    if (!output)
    {
        std::cerr << "Could not open " << outputPath << '\n';

        return 1;
    }

    // header
    output << "time,"
           << "particle_id,"
           << "x,"
           << "y\n";

    // initial position
    particle_transport::writeSnapshot(output, particleSystem, simulation.t);

    // run simulation
    for (int i{}; i < 100; ++i)
    {
        simulation.step(particleSystem);
        particle_transport::writeSnapshot(output, particleSystem, simulation.t);

    }

    output.close();

    if (!output)
    {
        std::cerr << "Error writing to file\n";

        return 1;
    }

    // --- test ---

    std::cout << "---\n"
              << "Positions after 100 steps, at time t = " << simulation.t << ":\n";
    for (std::size_t i{}; i < particleSystem.particles.size(); ++i)
    {
        std::cout << "(" << particleSystem.particles[i].x << ", " << particleSystem.particles[i].y << ")\n";
    }

    return 0;
}
