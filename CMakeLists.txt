cmake_minimum_required(VERSION 3.14.0)

project(GameTree VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(MainWindowGame)
find_package(GTest REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Xml REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Xml REQUIRED)
qt6_add_resources(RCC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Style/StyleSyNet.qrc"
                            "${CMAKE_CURRENT_SOURCE_DIR}/Image/RccImage.qrc")

set(PATTERNS_COMMANDS
    Commands/LinkerCommands.cpp
    Commands/LinkerCommands.h
    Commands/Command.h
    Commands/ShowWgdCommand.h
    Commands/ShowWgdCommand.cpp
    Commands/HideWgdCommand.h
    Commands/HideWgdCommand.cpp
    Commands/InputData.h
    Commands/InputData.cpp
    Commands/ButtonActivityCommand.h
    Commands/ButtonActivityCommand.cpp
)

set(PROJECT_SOURCES
        main.cpp
        StartWindow.h
        StartWindow.cpp
        StartWindow.ui
        WindowInputData.cpp
        WindowInputData.h
        WindowInputData.ui

)

set(PROJECT_SOURCES_TEST_DIR
    TestCurrentDir/test_main.cpp
   )

add_executable(TestGameTree ${PROJECT_SOURCES_TEST_DIR} ${RCC_FILE})

if(WIN32)
    add_executable(MainGameTree WIN32 ${PROJECT_SOURCES}
                                      ${RCC_FILE}
                                      ${PATTERNS_COMMANDS}
                                      )
else()
    add_executable(MainGameTree UNIX ${PROJECT_SOURCES}
                                     ${RCC_FILE}
                                     ${PATTERNS_COMMANDS}
                                     )
endif()

target_link_libraries(MainGameTree PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                           Qt${QT_VERSION_MAJOR}::Core
                                           Qt${QT_VERSION_MAJOR}::Xml
                                           MainWindowGame
                                           )

target_include_directories(MainGameTree PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Commands"
                                                "${CMAKE_CURRENT_SOURCE_DIR}/MainWindowGame"
                                                "${CMAKE_CURRENT_SOURCE_DIR}/OtherSourceCode"
                                                )

target_link_libraries(TestGameTree PRIVATE Qt${QT_VERSION_MAJOR}::Core
                                          GTest::gtest
                                          GTest::gtest_main)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(MainGameTree PRIVATE /W3)
    target_compile_options(TestGameTree PRIVATE /W3)
else()
    target_compile_options(MainGameTree PRIVATE
                            -Wall -Wextra -pedantic -Werror)
    target_compile_options(TestGameTree PRIVATE
                            -Wall -Wextra -pedantic -Werror)
endif()
