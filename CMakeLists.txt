cmake_minimum_required(VERSION 3.2)

project(storyboard VERSION 0.0.1)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(storyboard main.cpp core/note.cpp core/note.h core/storyboard.cpp core/storyboard.h)

add_executable(storyboard_tests tests.cpp core/note.cpp core/note.h core/storyboard.cpp core/storyboard.h)

set_target_properties(storyboard storyboard_tests PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

set_target_properties(storyboard_tests PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

target_link_libraries(storyboard_tests
        ${Boost_LIBRARIES}
        )

enable_testing()

add_test(storyboard_test_set storyboard_tests)
