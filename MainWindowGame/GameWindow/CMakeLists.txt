cmake_minimum_required(VERSION 3.21)

project(GameWindow LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
qt6_add_resources(QRC_IMAGE_NODE_DATA "../ImagesNode/Images.qrc")

set(LIB_SOURCES GameWindow.cpp
                GameWindow.h
                GameWindow.ui)


add_library(GameWindow STATIC ${LIB_SOURCES}
                              ${QRC_IMAGE_NODE_DATA}
                              )


target_link_libraries(GameWindow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(GameWindow PRIVATE "../SourceBinaryTree")

target_compile_definitions(GameWindow PRIVATE GAMEWINDOW_LIBRARY)
