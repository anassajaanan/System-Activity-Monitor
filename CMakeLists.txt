cmake_minimum_required(VERSION 3.25)
project(system_activity_monitor C)

set(CMAKE_C_STANDARD 11)

add_executable(system_activity_monitor cpu.c cpu_utils.c lib/ft_split.c cpu.h)
