cmake_minimum_required(VERSION 3.10)

# Project name
project(MyGameProject VERSION 1.0)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all your source files
set(SOURCES
    main.cpp
    Dungeon.cpp
    Entity.cpp
    Platform.cpp
    Player.cpp
    Room.cpp
    Star.cpp
)

# Find raylib (assumes raylib is installed via package manager or available to find_package)
find_package(raylib REQUIRED)

# Include raylib's dependencies (optional but recommended)
if (raylib_FOUND)
    message(STATUS "raylib found: ${raylib_INCLUDE_DIRS}")
endif()

# Add the executable
add_executable(MyGame ${SOURCES})

# Link raylib (and optionally its dependencies)
target_link_libraries(MyGame PRIVATE raylib)

# Optional: Windows-specific settings
if (WIN32)
    # Set the output directory near your source files
    set_target_properties(MyGame PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
endif()
