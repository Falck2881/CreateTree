cmake_minimum_required(VERSION 3.21)

project(MainWindowGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(GameWindow)
find_package(Qt6 COMPONENTS Widgets Core REQUIRED)
qt6_add_resources(QRC_JSON JsonData.qrc)
qt6_add_resources(QRC_IMAGE_NODE_DATA "${CMAKE_CURRENT_SOURCE_DIR}/ImagesNode/Images.qrc")
qt6_add_resources(RCC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/DifferentImages/DifferentImages.qrc")


set(SOURCE_BINARYTREE SourceBinaryTree/Node.cpp
                      SourceBinaryTree/Node.h
                      SourceBinaryTree/StreamJson.h
                      SourceBinaryTree/StreamJson.cpp
                      SourceBinaryTree/Tree.h
                      SourceBinaryTree/BalancedTree.h
                      SourceBinaryTree/BalancedTree.cpp
                      SourceBinaryTree/BalancedBTree.h
                      SourceBinaryTree/BalancedBTree.cpp
                      SourceBinaryTree/BuilderTreeStrategy.h
                      SourceBinaryTree/ManagerBuilder.h
                      SourceBinaryTree/ManagerBuilder.cpp
                      SourceBinaryTree/NodeProxy.h
                      SourceBinaryTree/NodeProxy.cpp
                      SourceBinaryTree/MethodsChoiceBuildersTree.h
                      SourceBinaryTree/MethodsChoiceBuildersTree.cpp
)



set(LIB_SOURCE  MainWindowGame.cpp
                MainWindowGame.h
                MainWindowGame.ui
                WindowInputData.cpp
                WindowInputData.h
                WindowInputData.ui
)

add_library(MainWindowGame STATIC ${LIB_SOURCE}
                                  ${RCC_FILE}
                                  ${SOURCE_BINARYTREE}
                                  ${QRC_IMAGE_NODE_DATA}
                                  ${QRC_JSON}
                                  )

target_link_libraries(MainWindowGame PRIVATE Qt6::Widgets
                                             Qt6::Core
                                             GameWindow)

target_include_directories(MainWindowGame PRIVATE "../Commands" "/GameWindow")

target_compile_definitions(MainWindowGame PRIVATE MAINWINDOWGAME_LIBRARY)
