cmake_minimum_required(VERSION 3.5)


add_executable(ProjectStructure
    main.cpp
    model/ShapesRotation.h
    model/ShapesRotation.cpp
    model/Position.h
    model/Position.cpp
    model/Enums.h
    model/Brick.h
    model/Brick.cpp
    model/Board.h
    model/Board.cpp
    model/BrickBag.h
    model/BrickBag.cpp
    model/Level.h
    model/Level.cpp
    model/Score.h
    model/Score.cpp
    model/Game.h
    model/Game.cpp
    util/Observer.h
    util/Observable.h
    util/Observable.cpp
    view/ConsoleView.h
    view/ConsoleView.cpp
    controller/ConsoleController.h
    controller/ConsoleController.cpp
    MyClass.cpp
    MyClass.h

)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
