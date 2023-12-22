cmake_minimum_required(VERSION 3.26)
project(gauss_kopia C)

set(CMAKE_C_STANDARD 11)

add_executable(gauss_kopia src/main.c
        src/gauss.c
        src/backsubst.c
        src/mat_io.c)
