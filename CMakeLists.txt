cmake_minimum_required(VERSION 3.16)
project(bmp_processing C)

set(CMAKE_C_STANDARD 99)

add_executable(bmp_processing main.c BitmapFileHeader.h Rgb.h BitmapInfoHeader.h)

target_link_libraries(bmp_processing m)