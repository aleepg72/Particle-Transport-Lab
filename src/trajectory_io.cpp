#include <cstddef>

#include "particle_transport/trajectory_io.hpp"


namespace particle_transport
{
    bool initialiseTrajectoryFile(
        std::ofstream& output,
        const std::filesystem::path& path,
        std::error_code& error
    ) {
        error.clear();

        // create output directory
        std::filesystem::path directory{path.parent_path()};

        if (!directory.empty())
        {
            std::filesystem::create_directories(directory, error);

            if (error) return false;
        }

        // open output file
        output.open(path);

        if (!output)
        {
            error.assign(
                static_cast<int>(std::errc::io_error),
                std::generic_category()
            );

            return false;
        }

        // write header to file
        output << "time,"
               << "particle_id,"
               << "x,"
               << "y\n";

        if (!output)
        {
            error.assign(
                static_cast<int>(std::errc::io_error),
                std::generic_category()
            );

            output.close();

            return false;
        }

        return true;
    }


    bool writeSnapshot(
        std::ostream& output,
        const ParticleSystem& particleSystem,
        const double t,
        std::error_code& error
    ) {
        error.clear();

        for (std::size_t i{}; i < particleSystem.particles.size(); ++i)
        {
            output << t << ","
                   << i << ","
                   << particleSystem.particles[i].x << ","
                   << particleSystem.particles[i].y << '\n';
        }

        if (!output)
        {
            error.assign(
                static_cast<int>(std::errc::io_error),
                std::generic_category()
            );

            return false;
        }

        return true;
    }


    bool closeTrajectoryFile(
        std::ofstream& output,
        std::error_code& error
    ) {
        error.clear();

        output.clear();
        output.close();

        if (!output)
        {
            error.assign(
                static_cast<int>(std::errc::io_error),
                std::generic_category()
            );

            return false;
        }

        return true;
    }
}
