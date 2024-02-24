cmake_minimum_required(VERSION 3.5)


add_executable(ProjectStructure
    main.cpp
    MyClass.h
    MyClass.cpp
    ShapesRotation.h
    ShapesRotation.cpp
    Position.hpp
    enum.hpp
    Brick.hpp
)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
