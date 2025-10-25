cmake_minimum_required(VERSION 3.10)
project(bibliotheque)

file(GLOB SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# Use C++17
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Add warnings
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)


