CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(CPP-QT-PYQT-PY)

ADD_DEFINITIONS("-std=c++11")

SET (QT_MIN_VERSION "5.2.0")
SET(CMAKE_PREFIX_PATH "${QT_PREFIX}/lib/cmake")
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Widgets REQUIRED)

ADD_DEFINITIONS(-DQT_NO_KEYWORDS) # http://stackoverflow.com/questions/23068700/embedding-python3-in-qt-5

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

ADD_EXECUTABLE (cpp-qt-pyqt-py
    main.cpp
    MainWindow.cpp
)

TARGET_LINK_LIBRARIES(cpp-qt-pyqt-py
    ${PYTHON_LIBRARIES}
    Qt5::Widgets
)

