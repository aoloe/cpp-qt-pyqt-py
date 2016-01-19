CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(CPP-QT-PYQT-PY)

ADD_DEFINITIONS("-std=c++11")

SET (QT_MIN_VERSION "5.2.0")
SET(CMAKE_PREFIX_PATH "${QT_PREFIX}/lib/cmake")
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Widgets REQUIRED)

# hint: http://stackoverflow.com/questions/23068700/embedding-python3-in-qt-5
# ADD_DEFINITIONS(-DQT_NO_KEYWORDS) 
# ... DQT_NO_KEYWORDS conflicts with the use public *slot*: in the header files:
# problem: http://stackoverflow.com/questions/27045323/embedding-python-3-4-into-c-qt-application
# solution: http://stackoverflow.com/questions/20185423/qt-cmake-missing-before-identifier-slots

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

ADD_SUBDIRECTORY(cpp-qt-pytqt-py)


configure_file(python/test.py python/test.py COPYONLY)
