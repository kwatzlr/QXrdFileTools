cmake_minimum_required(VERSION 2.8)

PROJECT(ACsoft)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

configure_file(${CMAKE_SOURCE_DIR}/version ${CMAKE_BINARY_DIR}/version.dummy)
file (STRINGS "version" VERSION)
set(_VERSION ${VERSION})
string(REPLACE "." ";" _VERSION ${VERSION})
list(GET _VERSION 0 VERSION_MAJOR)
list(GET _VERSION 1 VERSION_MINOR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
find_package(XROOTD REQUIRED)

add_definitions(${XROOTD_CFLAGS})
include_directories(${XROOTD_INCLUDE_DIR})

# add -fPIC for 64 bit systems
if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
  add_definitions(-fPIC)
endif()

# enable folder support for XCode projects
set_property( GLOBAL PROPERTY USE_FOLDERS ON)

include(cmake/qt.cmake)

add_subdirectory(lib)

# configure package files and export
configure_file("cmake/QXrdFileToolsConfigVersion.cmake.in" ${CMAKE_CURRENT_BINARY_DIR}/QXrdFileToolsConfigVersion.cmake @ONLY)
configure_file("cmake/QXrdFileToolsConfig.cmake.in" ${CMAKE_CURRENT_BINARY_DIR}/QXrdFileToolsConfig.cmake @ONLY)

export(PACKAGE QXrdFileTools)
