# Qt Screen & Video Recorder

A C++ desktop application demonstrating screen recording, audio capture, and screenshot functionality using Qt and FFmpeg.

## Overview

This project uses Qt for the user interface and event handling, and FFmpeg for high-performance video and audio processing. The application allows users to:

- Record the full screen or a selected region
- Capture system audio and/or microphone input
- Take screenshots in various formats
- Configure recording settings such as resolution, frame rate, and output folder

## Project Structure

QtScreenRecorder/
├── build/
├── AudioCaptureEngine.cpp
├── AudioCaptureEngine.h
├── CaptureManager.cpp
├── CaptureManager.h
├── CMakeLists.txt
├── ConfigManager.cpp
├── ConfigManager.h
├── FFmpegProcess.cpp
├── FFmpegProcess.h
├── FileManager.cpp
├── FileManager.h
├── HotkeyManager.cpp
├── HotkeyManager.h
├── main.cpp
├── MainWindow.cpp
├── MainWindow.h
├── ScreenCaptureEngine.cpp
└── ScreenCaptureEngine.h

## File Descriptions

### main.cpp
Entry point of the application; initializes the UI and starts the main event loop.

### AudioCaptureEngine.cpp / AudioCaptureEngine.h
Handles audio recording from system and microphone inputs.

### CaptureManager.cpp / CaptureManager.h
Coordinates the capture processes for video and audio.

### ConfigManager.cpp / ConfigManager.h
Manages user-configurable settings such as resolution, frame rate, hotkeys, and output paths.

### FFmpegProcess.cpp / FFmpegProcess.h
Handles video and audio encoding using FFmpeg.

### FileManager.cpp / FileManager.h
Manages file saving, naming, and organization.

### HotkeyManager.cpp / HotkeyManager.h
Registers and manages keyboard shortcuts for recording and screenshots.

### MainWindow.cpp / MainWindow.h
Defines the main UI window and links UI actions to backend functionality.

### ScreenCaptureEngine.cpp / ScreenCaptureEngine.h
Handles screen capture logic and prepares frames for recording.

### CMakeLists.txt
CMake configuration file for building the project.

## How to Build and Run

```bash
git clone https://github.com/yourusername/QtScreenRecorder.git
cd QtScreenRecorder

# Open the project in Qt Creator and build
# Or build using CMake
mkdir build
cd build
cmake ..
cmake --build .

# Run the application
./QtScreenRecorder
