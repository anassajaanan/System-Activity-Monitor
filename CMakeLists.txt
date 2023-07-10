cmake_minimum_required(VERSION 3.25)
project(system_activity_monitor C)

set(CMAKE_C_STANDARD 11)

add_executable(system_activity_monitor cpu.c cpu_utils.c helpers/ft_split.c include/system_monitor.h helpers/ft_strjoin.c include/color.h memory.c helpers/ft_atoi.c helpers/ft_isnumeric.c include/helpers.h)
