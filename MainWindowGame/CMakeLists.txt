cmake_minimum_required(VERSION 3.21)

project(MainWindowGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets Core REQUIRED)
qt6_add_resources(RCC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Images/Images.qrc")

set(LIB_SOURCE  MainWindowGame.cpp
                MainWindowGame.h
                MainWindowGame.ui
)

set(SOURCE_BINARYTRE SourceBinaryTree/Node.cpp
                     SourceBinaryTree/Node.h)

add_library(MainWindowGame STATIC ${LIB_SOURCE} ${RCC_FILE})

target_link_libraries(MainWindowGame PRIVATE Qt6::Widgets
                                             Qt6::Core )

target_include_directories(MainWindowGame PRIVATE "../Commands")

target_compile_definitions(MainWindowGame PRIVATE MAINWINDOWGAME_LIBRARY)
