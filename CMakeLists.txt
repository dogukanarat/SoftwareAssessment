cmake_minimum_required(VERSION 3.6)

project(
    RocketLabAssesment
    VERSION 0.1
)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("====== Building with coverage flags")

    set(GCC_COVERAGE_COMPILE_FLAGS "--coverage -g -O0")
    set(GCC_COVERAGE_LINK_FLAGS    "--coverage -g")

    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("====== Building without coverage flags")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")
    
option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen)

# include(GenerateDoxygen)

add_subdirectory(Assessments)

enable_testing()

add_subdirectory(Tests)

