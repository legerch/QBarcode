# CMakeLists file based on project template repository: https://github.com/legerch/projects-template
## Template file version: 2025-07-24 

cmake_minimum_required(VERSION 3.20)

# Set project properties
set(PROJECT_NAME qbarcode-tests)

# Set project configuration
## Generic properties
project(${PROJECT_NAME} LANGUAGES CXX)

## Qt specific properties
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Define project options
# Example: option(QBAR_TESTS_ENABLE_FEAT1 "Use to enable/disable feature1 for tests." ON)

# Set needed packages
## Qt packages
set(PROJECT_QT_PACKAGES
    Core
    Test
)

find_package(QT NAMES Qt6 Qt5 COMPONENTS ${PROJECT_QT_PACKAGES} REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ${PROJECT_QT_PACKAGES} REQUIRED)

list(TRANSFORM PROJECT_QT_PACKAGES PREPEND "Qt${QT_VERSION_MAJOR}::")

## Other library packages
### Example: find_package(nlohmann_json 3.11.3 REQUIRED)
find_package(GTest 1.11.0 REQUIRED)

# Defines useful path variables for easier CMake configuration
set(PROJECT_DIR_TESTS_EXTERNAL_RSC  "${CMAKE_CURRENT_SOURCE_DIR}/external-ressources/")

# Manage library files
## Set tests compilation definitions
set(PROJECT_DEFS_PRIV
    QBAR_TESTS_DIR_EXTERNAL_RSC="${PROJECT_DIR_TESTS_EXTERNAL_RSC}"
)

## Set library linking
### Linking dirs
set(PROJECT_LINKING_DIR

)

### Linking libs
set(PROJECT_LINKING_LIB
    ${PROJECT_QT_PACKAGES}
    GTest::gtest_main

    qbarcode
)

## Set tests files
set(FILES_HEADERS
    helpers/testsrsc.h
)

set(FILES_SOURCES
    helpers/testsrsc.cpp

    payloads_tests.cpp
)

# Add files to the test application
set(PROJECT_FILES ${FILES_HEADERS} ${FILES_SOURCES})
add_executable(${PROJECT_NAME} ${PROJECT_FILES})

# Link needed libraries
target_link_directories(${PROJECT_NAME} PUBLIC ${PROJECT_LINKING_DIR})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${PROJECT_LINKING_LIB})

# Specify compiler options
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Werror=return-type -Wshadow -Wlogical-op -Wduplicated-cond -Wduplicated-branches>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Werror=return-type -Wshadow -Wlogical-op -Wduplicated-cond -Wduplicated-branches>
    $<$<CXX_COMPILER_ID:MSVC>:/W3 /wd4251>
)

# Compile needed definitions
## Application tests related
target_compile_definitions(${PROJECT_NAME} PRIVATE ${PROJECT_DEFS_PRIV})

# Specify include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
