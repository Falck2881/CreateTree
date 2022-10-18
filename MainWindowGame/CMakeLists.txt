cmake_minimum_required(VERSION 3.21)

project(MainWindowGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 COMPONENTS Widgets Core REQUIRED)
qt6_add_resources(QRC_DIFF_IMG "${CMAKE_CURRENT_SOURCE_DIR}/DifferentImages/DifferentImages.qrc")
qt6_add_resources(QRC_BUILD_DATA "${CMAKE_CURRENT_SOURCE_DIR}/BuildDataQrc/BuildData.qrc")
qt6_add_resources(QRC_IMAGE_NODE_DATA "${CMAKE_CURRENT_SOURCE_DIR}/ImagesNode/Images.qrc")

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
                          SourceBinaryTree/Tree.h
                          SourceBinaryTree/SimpleBinaryTree.h
                          SourceBinaryTree/SimpleBinaryTree.cpp
                          SourceBinaryTree/BalancedBTree.h
                          SourceBinaryTree/BalancedBTree.cpp
                          SourceBinaryTree/ManagerGameWindow.h
                          SourceBinaryTree/ManagerGameWindow.cpp
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
                          SourceBinaryTree/MethodCustomizationUi.h
                          SourceBinaryTree/MethodCustomizationUi.cpp
                          SourceBinaryTree/ArrayNodes.h
                          SourceBinaryTree/ArrayNodes.cpp
                          SourceBinaryTree/ArrayOffsets.h
                          SourceBinaryTree/MethodsInitArrOffsets.h
                          SourceBinaryTree/ConceptMethodInitArr.h)


add_library(MainWindowGame STATIC ${WINDOWS}
                                  ${SOURCE_BINARY_TREE}
                                  ${QRC_IMAGE_NODE_DATA}
                                  ${QRC_BUILD_DATA}
                                  ${QRC_DIFF_IMG})

target_link_libraries(MainWindowGame PRIVATE Qt6::Widgets
                                             Qt6::Core)

target_include_directories(MainWindowGame PRIVATE "../Commands" "${CMAKE_CURRENT_SOURCE_DIR}/SourceBinaryTree")

target_compile_definitions(MainWindowGame PRIVATE MAINWINDOWGAME_LIBRARY)
