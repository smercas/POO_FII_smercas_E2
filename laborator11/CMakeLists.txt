cmake_minimum_required(VERSION 3.25)
project(laborator11)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES
    sort.h
)

set(APP_EXE
    sort
)

add_executable(${APP_EXE}
    sort.h
)

target_link_libraries(${APP_EXE}
    laborator11
)

add_library(laborator11 STATIC
    ${SOURCE_FILES}
)

