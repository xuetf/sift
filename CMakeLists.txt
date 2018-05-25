cmake_minimum_required(VERSION 2.8)
project(finalmatch C)

include_directories(.)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g")

add_executable(finalmatch
        cv.c
        def.h
        header.h
        img.c
        kdtree.c
        main.c
        minpq.c
        sift.c
        type.h)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)