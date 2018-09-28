cmake_minimum_required(VERSION 3.9)
project(Project)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_NAME Project)
add_executable(${EXECUTABLE_NAME} main.cpp GameCharacter.h GameCharacter.cpp Hero.cpp Hero.h Weapon.cpp Weapon.h Abstract_Factory.h Enemy.cpp Enemy.h Companion.cpp Companion.h Menu.cpp Menu.h Rules.cpp Rules.h MenuLoop.cpp MenuLoop.h)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()