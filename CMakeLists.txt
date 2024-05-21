cmake_minimum_required(VERSION 3.5)

project(neureset_simulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(MAINWONDIW_SRC_DIR "${PROJECT_SRC_DIR}/main_window")
set(BATTERY_SRC_DIR "${PROJECT_SRC_DIR}/battery")
set(DEVICE_SRC_DIR "${PROJECT_SRC_DIR}/device")
set(EEG_SRC_DIR "${PROJECT_SRC_DIR}/eeg")
set(PC_SRC_DIR "${PROJECT_SRC_DIR}/pc")
set(SESSIONMANAGER_SRC_DIR "${PROJECT_SRC_DIR}/session_manager")
set(SIGNALPROCESSOR_SRC_DIR "${PROJECT_SRC_DIR}/signal_processor")
set(TESTUI_SRC_DIR "${PROJECT_SRC_DIR}/test_ui")
set(WAVEGENERATOR_SRC_DIR "${PROJECT_SRC_DIR}/wave_generator")
set(QCUSTOMPLOT_SRC_DIR "${PROJECT_SRC_DIR}/qcustomplot")

add_library(QCustomPlot STATIC ${QCUSTOMPLOT_SRC_DIR}/qcustomplot.cpp)
target_include_directories(QCustomPlot PUBLIC ${QCUSTOMPLOT_SRC_DIR})
target_link_libraries(QCustomPlot PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

include_directories(
    ${PROJECT_SRC_DIR}
    ${MAINWONDIW_SRC_DIR}
    ${BATTERY_SRC_DIR}
    ${DEVICE_SRC_DIR}
    ${EEG_SRC_DIR}
    ${PC_SRC_DIR}
    ${SESSIONMANAGER_SRC_DIR}
    ${SIGNALPROCESSOR_SRC_DIR}
    ${TESTUI_SRC_DIR}
    ${WAVEGENERATOR_SRC_DIR}
)

set(PROJECT_SOURCES
    ${PROJECT_SRC_DIR}/main.cpp
    ${MAINWONDIW_SRC_DIR}/mainwindow.cpp
    ${MAINWONDIW_SRC_DIR}/mainwindow.h
    ${MAINWONDIW_SRC_DIR}/mainwindow.ui
    ${BATTERY_SRC_DIR}/battery.h
    ${BATTERY_SRC_DIR}/battery.cpp
    ${PROJECT_SRC_DIR}/defs.h
    ${DEVICE_SRC_DIR}/device.h
    ${DEVICE_SRC_DIR}/device.cpp
    ${EEG_SRC_DIR}/eeg.h
    ${EEG_SRC_DIR}/eeg.cpp
    ${PC_SRC_DIR}/pc.h
    ${PC_SRC_DIR}/pc.cpp
    ${SESSIONMANAGER_SRC_DIR}/sessionmanager.h
    ${SESSIONMANAGER_SRC_DIR}/sessionmanager.cpp
    ${SIGNALPROCESSOR_SRC_DIR}/signalprocessor.h
    ${SIGNALPROCESSOR_SRC_DIR}/signalprocessor.cpp
    ${TESTUI_SRC_DIR}/testui.h
    ${TESTUI_SRC_DIR}/testui.cpp
    ${TESTUI_SRC_DIR}/testui.ui
    ${WAVEGENERATOR_SRC_DIR}/wavegenerator.h
    ${WAVEGENERATOR_SRC_DIR}/wavegenerator.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(neureset_simulator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(neureset_simulator SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(neureset_simulator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(neureset_simulator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets QCustomPlot)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.neureset_simulator)
endif()
set_target_properties(neureset_simulator PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS neureset_simulator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(neureset_simulator)
endif()
