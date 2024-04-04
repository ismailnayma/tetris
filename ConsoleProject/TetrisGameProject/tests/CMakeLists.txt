cmake_minimum_required(VERSION 3.5)

file(GLOB MODEL_SOURCES "../src/model/*.cpp")
file(GLOB UTIL_SOURCES "../src/util/*.cpp")

add_executable(TetrisGameProjectTests


    testBoard.cpp
    ${MODEL_SOURCES}
    ${UTIL_SOURCES}
)
target_include_directories(TetrisGameProjectTests PRIVATE
    ../src
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

target_link_libraries(TetrisGameProjectTests Catch2::Catch2WithMain)
