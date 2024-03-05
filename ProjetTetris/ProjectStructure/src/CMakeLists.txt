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
    Board.h
    Board.cpp
    BrickBag.hpp
    Score.hpp
    Level.hpp
    Game.h
    Game.cpp
    Observer.h
    Observable.h
    Observable.cpp
)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
