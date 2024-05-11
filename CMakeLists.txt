cmake_minimum_required(VERSION 3.27)
project(CAIndex)

set(CMAKE_CXX_STANDARD 23)

add_executable(CAIndex main.cpp
        structures/TreeNode.cpp
        structures/TreeNode.h
        Tree.cpp
        structures/Tree.h)
