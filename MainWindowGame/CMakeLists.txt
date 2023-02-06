cmake_minimum_required(VERSION 3.21)

project(MainWindowGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)
qt_add_resources(QRC_DIFF_IMG "${CMAKE_CURRENT_SOURCE_DIR}/DifferentImages/DifferentImages.qrc")
qt_add_resources(QRC_BUILD_DATA "${CMAKE_CURRENT_SOURCE_DIR}/BuildDataQrc/BuildData.qrc")
qt_add_resources(QRC_IMAGE_NODE_DATA "${CMAKE_CURRENT_SOURCE_DIR}/ImagesNode/Images.qrc")

set(WINDOWS MainWindowGame.cpp
            MainWindowGame.h
            MainWindowGame.ui
            WindowInputData.cpp
            WindowInputData.h
            WindowInputData.ui
            GameWindow.cpp
            GameWindow.h
            GameWindow.ui)

set(SOURCE_BINARY_TREE
                          SourceBinaryTree/GraphicsNode.cpp
                          SourceBinaryTree/GraphicsNode.h
                          SourceBinaryTree/StreamJson.h
                          SourceBinaryTree/StreamJson.cpp
                          SourceBinaryTree/GraphicsBinaryTree.h
                          SourceBinaryTree/GraphicsBinaryTree.cpp
                          SourceBinaryTree/GraphicsBTree.h
                          SourceBinaryTree/GraphicsBTree.cpp
                          SourceBinaryTree/GraphicsTree.h
                          SourceBinaryTree/GraphicsTree.cpp
                          SourceBinaryTree/GraphicsBuilder.h
                          SourceBinaryTree/GraphicsBuilder.cpp
                          SourceBinaryTree/GraphicsBuilderBinaryTree.h
                          SourceBinaryTree/GraphicsBuilderBinaryTree.cpp
                          SourceBinaryTree/GraphicsBuilderAvlTree.h
                          SourceBinaryTree/GraphicsBuilderAvlTree.cpp
                          SourceBinaryTree/SimpleRandom.h
                          SourceBinaryTree/SimpleRandom.cpp
                          SourceBinaryTree/MethodBuild.h
                          SourceBinaryTree/MethodBuild.cpp
                          SourceBinaryTree/Array.h
                          SourceBinaryTree/Array.cpp
                          SourceBinaryTree/UpdateBinaryTree.h
                          SourceBinaryTree/UpdateBinaryTree.cpp
                          SourceBinaryTree/UpdateBTree.h
                          SourceBinaryTree/UpdateBTree.cpp
                          SourceBinaryTree/GraphicsBuilderBTree.h
                          SourceBinaryTree/GraphicsBuilderBTree.cpp
                          SourceBinaryTree/UpdateTree.h
                          SourceBinaryTree/ConceptUpdateTree.h
                          SourceBinaryTree/OffsetBranch.h
                          SourceBinaryTree/OffsetBranch.cpp)


add_library(MainWindowGame STATIC ${WINDOWS}
                                  ${SOURCE_BINARY_TREE}
                                  ${QRC_IMAGE_NODE_DATA}
                                  ${QRC_BUILD_DATA}
                                  ${QRC_DIFF_IMG})

target_link_libraries(MainWindowGame PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                             Qt${QT_VERSION_MAJOR}::Core)

target_include_directories(MainWindowGame PRIVATE "../Commands" "${CMAKE_CURRENT_SOURCE_DIR}/SourceBinaryTree")

target_compile_definitions(MainWindowGame PRIVATE MAINWINDOWGAME_LIBRARY)
