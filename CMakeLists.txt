cmake_minimum_required(VERSION 3.20)

project(ParticleTransportLab
    VERSION 0.1.0
    LANGUAGES CXX
)

add_executable(ptl
    src/main.cpp
    src/simulation.cpp
    src/trajectory_io.cpp
)

target_compile_features(ptl PRIVATE cxx_std_20)

target_include_directories(ptl PRIVATE include)
