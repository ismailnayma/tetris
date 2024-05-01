cmake_minimum_required(VERSION 3.5)


add_executable(TetrisGameProject
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
    model/Timer.h
    model/Timer.cpp
    util/Observer.h
    util/Observable.h
    util/Observable.cpp
    view/ConsoleView.h
    view/ConsoleView.cpp
    controller/ConsoleController.h
    controller/ConsoleController.cpp
    view/gui/mainwindow.h
    view/gui/mainwindow.cpp
    view/gui/mainwindow.ui
    view/gui/startwindow.h
    view/gui/startwindow.cpp
    view/gui/startwindow.ui
    controller/GUIController.h
    controller/GUIController.cpp
    view/gui/restartwindow.h
    view/gui/restartwindow.cpp
    view/gui/restartwindow.ui


)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
target_link_libraries(TetrisGameProject PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


install(TARGETS TetrisGameProject
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
