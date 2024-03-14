cmake_minimum_required(VERSION 3.5)


add_executable(ProjectStructure
    main.cpp
    model/ShapesRotation.h
    model/ShapesRotation.cpp
    model/Position.h
    model/Position.cpp
    model/Enums.h
    Brick.hpp
    Board.h
    Board.cpp
    BrickBag.hpp
    Score.hpp
    Level.hpp
    Game.h
    Game.cpp
    util/Observer.h
    util/Observable.h
    util/Observable.cpp
    ConsoleView.h
    ConsoleController.h
    ConsoleView.cpp
    ConsoleController.cpp
    MyClass.cpp
    MyClass.h

)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
