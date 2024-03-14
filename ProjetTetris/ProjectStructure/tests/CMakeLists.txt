cmake_minimum_required(VERSION 3.5)

file(GLOB MODEL_SOURCES "../src/model/*.cpp")

add_executable(ProjectStructureTests

    testMyClass.cpp
    ../src/MyClass.cpp
    testBoard.cpp
    ${MODEL_SOURCES}
)
target_include_directories(ProjectStructureTests PRIVATE
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

target_link_libraries(ProjectStructureTests Catch2::Catch2WithMain)
