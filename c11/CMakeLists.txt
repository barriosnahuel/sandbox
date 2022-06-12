cmake_minimum_required(VERSION 3.13)
project(c11 C)

set(CMAKE_C_STANDARD 11)

add_executable(c11 main.c)

add_library(
        # Sets the name of the library.
        androidc

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ejercicio-clase.c
        examen2.c
)