cmake_minimum_required(VERSION 3.20)
project(B_DOT C)

set(CMAKE_C_STANDARD 99)

add_executable(B_DOT main.c bdot.c bdot.h my_sensors.c my_sensors.h)
