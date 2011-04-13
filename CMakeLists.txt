cmake_minimum_required(VERSION 2.8)

project(trivial-plugin)
set(PLUGIN_NAME trivialplugin)

set(SOURCES trivialplugin.cpp)
set(HEADERS trivialplugin.h)
set(MOC_HEADERS trivialplugin.h)

include_directories("${CMAKE_SOURCE_DIR}")

set(LOCALIZED_LANGS "ru;pl;de;uk")

include("${CMAKE_SOURCE_DIR}/cmake/config.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/translations.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/plugin.cmake")
