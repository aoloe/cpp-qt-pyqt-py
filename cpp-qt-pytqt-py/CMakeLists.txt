ADD_EXECUTABLE (cpp-qt-pyqt-py
    main.cpp
    MainWindow.cpp
)

TARGET_LINK_LIBRARIES(cpp-qt-pyqt-py
    ${PYTHON_LIBRARIES}
    Qt5::Widgets
)
