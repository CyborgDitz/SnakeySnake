cmake_minimum_required(VERSION 3.30)
project(SnakeySnake C CXX)

set(CMAKE_C_STANDARD 99)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG ${gitTag}
            GIT_SHALLOW TRUE
            GIT_PROGRESS TRUE
    )

    FetchContent_MakeAvailable(${libName})
endfunction()

set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    message(STATUS "Getting ${LIB1} from Github")
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git master)
else()
    message(STATUS "Using local ${LIB1}")
endif()

add_executable(SnakeySnake main.c
        draw.c
        game.c)


target_include_directories(SnakeySnake PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(SnakeySnake PRIVATE raylib)

# Set C++ standard
set(CMAKE_CXX_STANDARD 99)
