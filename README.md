# Particle Transport Lab

A computational physics project for simulating and analysing two-dimensional particle transport using C++ and Python.

The project currently supports Brownian motion, providing a simple framework for numerical simulation, trajectory generation and MSD analysis.


## Current Features
- Configurable simulation parameters and physical properties.
- Euler–Maruyama integration scheme.
- Particle trajectory output in CSV format.
- Mean-squared displacement computation and comparison with theoretical predictions.


## Physical Model
The dynamics of a particle subject to both deterministic and stochastic forces are described by the Langevin equation

$$ m \boldsymbol{\ddot{r}}(t) = -\gamma \boldsymbol{\dot{r}}(t) + \boldsymbol{F}(\boldsymbol{r}(t)) + \boldsymbol{\eta}(t),$$

where $m$ is the mass of the particle, $\gamma$ its friction coefficient, $\boldsymbol{F}$ the deterministic forces applied on the particle, and $\boldsymbol{\eta}(t) = \sqrt{2\Gamma}\, \boldsymbol{\xi}(t)$ represents the stochastic force resulting from random collisions with the surrounding medium, where $\boldsymbol{\xi}$ is normalised Gaussian white noise and $\Gamma = \gamma k_B T$ sets the noise amplitude. The Fluctuation-Dissipation theorem further relates this amplitude to the diffusion coefficient $D = k_B T / \gamma$.

In the overdamped limit, where inertial forces are negligible compared to friction, the dynamics are usually obtained numerically through the Euler–Maruyama discretisation

$$ \boldsymbol{r}(t + \delta t) = \boldsymbol{r}(t) + \frac{\boldsymbol{F}(\boldsymbol{r}(t))}{\gamma}\, \delta t + \sqrt{2D\, \delta t}\, \boldsymbol{\xi},$$

where $\delta t$ is the integration timestep, and $\boldsymbol{\xi}$ is treated as a vector of independent standard normally distributed random variables. This is the case for our current implementation, where $\boldsymbol{F} = 0$.

In two dimensions, the mean-squared displacement (MSD) of Brownian particles is expected to follow

$$ \langle |\boldsymbol{r}(t) - \boldsymbol{r}(0)|^2 \rangle = 4Dt. $$


## Requirements
- A C++ compiler supporting C++20.
- CMake 3.20 or newer.
- Python 3 with the packages: numpy, pandas, matplotlib.

Currently the build has only been tested on macOS; support for other operating systems has not yet been verified.


## Building and Running

Clone the repository and navigate to its root directory.

Configure the project with CMake:
```
cmake -S . -B build
```

Build the executable:
```
cmake --build build
```

Run the simulation from the project root:
```
./build/ptl
```
The simulation writes particle trajectories to `data/trajectories.csv`. Running the simulation again overwrites the file.

The directories that are not cloned are created automatically during this process if they do not already exist.


## Output Format

The simulation produces a CSV file with one row per particle at each recorded time step.

Column             | Description
---                | ---
`time`             | Simulation time
`particle_id`      | Particle index
`x`                | Particle $x$-coordinate
`y`                | Particle $y$-coordinate

The initial particle positions are recorded at $t=0$, followed by one snapshot after each simulation step.

No particular system of units is imposed, provided that all quantities are dimensionally consistent.


## Analysis

All data analysis is performed in Python inside Jupyter notebooks.

`notebooks/01_brownian_motion.ipynb`:
- Load and process the trajectory data.
- Compute the MSD from simulation data.
- Plot the MSD against the theoretical prediction.


## Project Structure

```
particle-transport-lab/
├── build/                      # Generated build files
├── data/                       # Generated simulation output
├── include/                    # C++ header files
│   └── particle_transport/
├── notebooks/                  # Analysis in Python
├── src/                        # C++ implementation
├── .gitignore
├── CMakeLists.txt              # CMake project configuration
└── README.md
```

## Roadmap

Future extensions may include:
- **Advection** and diffusion: particle transport in flow fields, starting with planar Poiseuille flow.
- **Taylor–Aris dispersion**: analysis of effective longitudinal dispersion in confined flows.
- **Particle interactions**: incorporation of repulsive interactions between particles.
- **Obstacles**: extend the geometry by introducing obstacles that block certain areas.