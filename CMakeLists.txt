cmake_minimum_required(VERSION 3.15)

project(Minishell VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(app/shell)
