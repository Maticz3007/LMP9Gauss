cmake_minimum_required(VERSION 3.26)
project(gauss_kopia C)

set(CMAKE_C_STANDARD 11)

add_executable(gauss_kopia main.c
        mat_io.c
        gauss.c
        backsubst.c)
