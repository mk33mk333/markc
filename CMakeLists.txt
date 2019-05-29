cmake_minimum_required(VERSION 3.10)
project(search C)

set(CMAKE_C_STANDARD 99)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)  

INCLUDE_DIRECTORIES(  
      /usr/include /usr/local/include  include 
) 

add_definitions(-D__USE_POSIX)

link_libraries(/usr/local/lib/libcurl.so.4.5.0)

add_executable(markc src/main.c src/commander.c src/uploader.c)