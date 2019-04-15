cmake_minimum_required(VERSION 3.9)
project(Project)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_NAME Project)

add_executable(${EXECUTABLE_NAME} main.cpp Abstract_Factory.h ChooseCharacter.h ChooseCharacter.cpp Enemy.cpp Enemy.h EnemyAwake.cpp EnemyAwake.h EnemySleeping.cpp EnemySleeping.h EnemyStrategy.cpp EnemyStrategy.h FireBall.cpp FireBall.h Game.h Game.cpp GameCharacter.h GameCharacter.cpp Graphic.cpp Graphic.h GraphicState.cpp GameCharacter.h Hero.cpp Hero.h Item.h Item.cpp Kalashnikov.h Kalashnikov.cpp Knight.cpp Knight.h MapLevel.cpp MapLevel.h Menu.h Menu.cpp MenuLoop.cpp MenuLoop.h Musica.cpp Musica.h MyView.h MyView.cpp Ninja.h Ninja.cpp Obstacle.h Obstacle.cpp Planetar.h Planetar.cpp Projectile.cpp Projectile.h Rules.h Rules.cpp Skeleton.h Skeleton.cpp TileMap.cpp TileMap.h Valkyrie.h Valkyrie.cpp Weapon.cpp Weapon.h Wizard.cpp Wizard.h Tile.cpp Tile.h Observer.h Subject.cpp Subject.h LevelOneFactory.cpp LevelOneFactory.h LevelTwoFactory.h LevelTwoFactory.cpp Arcontus.cpp Arcontus.h BossLevel.cpp BossLevel.h Mirinthas.cpp Mirinthas.h Orc.cpp Orc.h Abstract_Factory.cpp TileBossMap.h TileBossMap.cpp GameObserver.h GameObserver.cpp BossMap1.cpp BossMap1.h)
set(SOURCE_FILE main.cpp Abstract_Factory.h ChooseCharacter.h ChooseCharacter.cpp Enemy.cpp Enemy.h EnemyAwake.cpp EnemyAwake.h EnemySleeping.cpp EnemySleeping.h EnemyStrategy.cpp EnemyStrategy.h FireBall.cpp FireBall.h Game.h Game.cpp GameCharacter.h GameCharacter.cpp Graphic.cpp Graphic.h GraphicState.cpp GameCharacter.h Hero.cpp Hero.h Item.h Item.cpp Kalashnikov.h Kalashnikov.cpp Knight.cpp Knight.h MapLevel.cpp MapLevel.h Menu.h Menu.cpp MenuLoop.cpp MenuLoop.h Musica.cpp Musica.h MyView.h MyView.cpp Ninja.h Ninja.cpp Obstacle.h Obstacle.cpp Planetar.h Planetar.cpp Projectile.cpp Projectile.h Rules.h Rules.cpp Skeleton.h Skeleton.cpp TileMap.cpp TileMap.h Valkyrie.h Valkyrie.cpp Weapon.cpp Weapon.h Wizard.cpp Wizard.h Tile.cpp Tile.h Observer.h Subject.cpp Subject.h Achievement.cpp Achievement.h Pause.cpp Pause.h Heart.cpp Heart.h LevelOneFactory.cpp LevelOneFactory.h LevelTwoFactory.h LevelTwoFactory.cpp Arcontus.cpp Arcontus.h BossLevel.cpp BossLevel.h Mirinthas.cpp Mirinthas.h Orc.cpp Orc.h Abstract_Factory.cpp TileBossMap.h TileBossMap.cpp GameObserver.h GameObserver.cpp BossMap1.cpp BossMap1.h)

####### GUI ##########
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()

########GOOGLE TEST###########
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../include)
add_subdirectory(/home/piero/Documents/Programmazione/Project2/Project/test)
add_library(core ${SOURCE_FILE})
target_link_libraries(Project core)
