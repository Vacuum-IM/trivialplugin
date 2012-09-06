cmake_minimum_required(VERSION 2.8)

project(trivial-plugin)
set(PLUGIN_NAME trivialplugin)

set(SOURCES trivialplugin.cpp)
set(HEADERS trivialplugin.h)
set(MOC_HEADERS trivialplugin.h)

include_directories("${CMAKE_SOURCE_DIR}")

include("${CMAKE_SOURCE_DIR}/cmake/config.cmake")
include("${CMAKE_SOURCE_DIR}/translations/languages.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/plugin.cmake")

install(DIRECTORY "resources/menuicons"
	DESTINATION "${INSTALL_RESOURCES}")
