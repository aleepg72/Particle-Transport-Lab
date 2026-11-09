#include <iostream>

#include "particle_transport/particle.hpp"


int main()
{
    particle_transport::Particle r;
    r.x = 0;
    r.y = 0;

    std::cout << "x = " << r.x << '\n' << "y = " << r.y << '\n';

    return 0;
}
