cmake_minimum_required(VERSION 3.9)
project(Project)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_NAME Project)
add_executable(${EXECUTABLE_NAME} main.cpp GameCharacter.h GameCharacter.cpp Hero.cpp Hero.h Weapon.cpp Weapon.h Abstract_Factory.h Abstact_Factory.cpp Enemy.cpp Enemy.h Companion.cpp Companion.h Menu.cpp Menu.h Rules.cpp Rules.h MenuLoop.cpp MenuLoop.h ChoosCharacter.cpp ChoosCharacter.h TileMap.cpp TileMap.h Dungeon.cpp Dungeon.h Knight.cpp Knight.h Valkyrie.cpp Valkyrie.h Ninja.cpp Ninja.h Planetar.cpp Planetar.h Wizard.cpp Wizard.h )


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()