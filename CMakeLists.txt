cmake_minimum_required(VERSION 3.16)
project(FLASHBACK VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(FLASHBACK
    main.cpp
    CaptureManager.cpp
    FFmpegProcess.cpp
    ScreenCaptureEngine.cpp
    AudioCaptureEngine.cpp
    FileManager.cpp
    ConfigManager.cpp
    HotkeyManager.cpp
    MainWindow.cpp
)

target_link_libraries(FLASHBACK 
    Qt6::Core 
    Qt6::Widgets
)

if(WIN32)
    target_link_libraries(FLASHBACK user32)
endif()
