cmake_minimum_required(VERSION 3.20)

project(Sandbox LANGUAGES CXX)
set(CMAKE_SUPPRESS_REGENERATION ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Engine)
add_subdirectory(Game)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Game)
