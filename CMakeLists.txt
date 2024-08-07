cmake_minimum_required(VERSION 3.20)
project(MusicLibrarer)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/qt_setup.cmake)
include(cmake/path.cmake)
include(test/CMakeLists.txt)

add_executable(${PROJECT_NAME} src/main.cpp  ${HEADER_PATH} ${SOURCE_PATH})

setup_target(${PROJECT_NAME})
