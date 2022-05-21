cmake_minimum_required(VERSION 3.16)

project(PawnMove)

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

set(PANDA_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/submodules/Panda)
set(BIN_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(${PANDA_DIRECTORY})

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES
        src/*.cpp
        )

file(GLOB_RECURSE INCLUDE
        src/*.h
        src/*.hpp
        )

file(GLOB RESOURCE_FOLDERS
        resources/common/*
        )

if (DESKTOP)
    file(GLOB RESOURCE_DESKTOP_FOLDERS resources/desktop/*)
    list (APPEND RESOURCE_FOLDERS "${RESOURCE_DESKTOP_FOLDERS}")
elseif(PLATFORM_IOS)
    file(GLOB RESOURCE_IOS_FOLDERS resources/ios/*)
    list (APPEND RESOURCE_FOLDERS "${RESOURCE_IOS_FOLDERS}")
endif()

list(FILTER RESOURCE_FOLDERS EXCLUDE REGEX "\\.DS_Store")

# Pawn move target

add_app(PawnMove "${SOURCES}" "${INCLUDE}" "${RESOURCE_FOLDERS}")

target_precompile_headers(PawnMove PRIVATE ${PROJECT_SOURCE_DIR}/src/pwnmvpch.hpp)
target_include_directories(PawnMove PRIVATE ${PROJECT_SOURCE_DIR}/src)

set_target_properties(PawnMove
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BIN_DIRECTORY}
        )

# Dependencies - Panda
target_link_libraries(PawnMove Panda)
target_include_directories(PawnMove PRIVATE ${PANDA_DIRECTORY}/Panda/src)
message("PANDA HEADERS: ${PANDA_DIRECTORY}/src")

