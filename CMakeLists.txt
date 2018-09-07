cmake_minimum_required(VERSION 3.9)
project(Project)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project main.cpp GameCharacter.h GameCharacter.cpp Hero.cpp Hero.h Weapon.cpp Weapon.h Abstract_Factory.h Enemy.cpp Enemy.h Companion.cpp Companion.h)