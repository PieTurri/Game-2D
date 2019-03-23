##########GOOGLE TEST LINK##########

find_package(GTest REQUIRED)
add_subdirectory(./lib/googletest)

include_directories(./lib/googletest/include ./lib/googletest)



set(SOURCE_FILES runAllTest.cpp KnightTest.cpp ProjectileTest.cpp)
add_executable(runAllTests ${SOURCE_FILES})
##target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core)
#[[if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} )
    add_test(AllTestsInFoo runAllTests)
endif()]]
target_link_libraries(runAllTests gtest gtest_main core)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(runAllTests sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()

