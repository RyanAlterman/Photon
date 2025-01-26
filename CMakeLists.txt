cmake_minimum_required(VERSION 3.31.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

enable_testing()

# Photon Library & Unit Testing
add_subdirectory(Photon)

# Test Application
add_subdirectory(Application)