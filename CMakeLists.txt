cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp Admin.h guest.h drivers.h)