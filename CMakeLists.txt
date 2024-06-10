cmake_minimum_required(VERSION 3.27)
project(CAIndex VERSION 1.0
                DESCRIPTION "Implementation of a hierarchy index based on paths"
                LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        tomlplusplus
        GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
        GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(tomlplusplus)

add_executable(CAIndex src/main.cpp
        src/structures/DRAG.cpp
        src/indices/CAIndex/CAIndex.cpp
        src/indices/CAIndex/CAIndex.h
        src/indices/AOIndex/AOIndex.cpp
        src/indices/AOIndex/AOIndex.h
)

configure_file(src/config/config.toml ${CMAKE_CURRENT_BINARY_DIR}/config/config.toml COPYONLY)
target_link_libraries(CAIndex PRIVATE tomlplusplus::tomlplusplus)
