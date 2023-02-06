cmake_minimum_required(VERSION 3.21)

project(GameTree VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(MainWindowGame)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Xml)
qt_add_resources(RCC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Style/StyleSyNet.qrc"
                            "${CMAKE_CURRENT_SOURCE_DIR}/Image/RccImage.qrc")

set(PATTERNS_COMMANDS
    Commands/LinkerCommands.cpp
    Commands/LinkerCommands.h
    Commands/Command.h
    Commands/ShowWgdCommand.h
    Commands/ShowWgdCommand.cpp
    Commands/HideWgdCommand.h
    Commands/HideWgdCommand.cpp
    Commands/KeyboardInput.h
    Commands/KeyboardInput.cpp
    Commands/ButtonActivityCommand.h
    Commands/ButtonActivityCommand.cpp
)

set(PROJECT_SOURCES
        main.cpp
        StartWindow.h
        StartWindow.cpp
        StartWindow.ui
)

if(WIN32)
    add_executable(MainGameTree WIN32 ${PROJECT_SOURCES}
                                      ${RCC_FILE}
                                      ${PATTERNS_COMMANDS}
                                      )
else()
    add_executable(MainGameTree ${PROJECT_SOURCES}
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


if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(MainGameTree PRIVATE /W3)
else()
    target_compile_options(MainGameTree PRIVATE
                            -Wall -Wextra -pedantic -Werror)
endif()
