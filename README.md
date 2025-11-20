# Qt Screen & Video Recorder

A C++ desktop application for screen recording, audio capture, and screenshots using **Qt** and **FFmpeg**.

## Overview

This project uses Qt for the user interface and event handling, and FFmpeg for high-performance video and audio processing. It allows users to:

- Record the full screen or a selected region  
- Capture system audio and/or microphone input  
- Take screenshots in multiple formats  
- Configure recording settings such as resolution, frame rate, and output folder  

## Project Structure
```
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
```


## File Descriptions

- **main.cpp**  
  Entry point; initializes the UI and starts the event loop.

- **AudioCaptureEngine.\***  
  Handles audio recording from system and microphone inputs.

- **CaptureManager.\***  
  Coordinates video and audio capture processes.

- **ConfigManager.\***  
  Manages user settings such as resolution, frame rate, hotkeys, and output paths.

- **FFmpegProcess.\***  
  Handles video and audio encoding with FFmpeg.

- **FileManager.\***  
  Manages saving and organizing output files.

- **HotkeyManager.\***  
  Registers and manages keyboard shortcuts.

- **MainWindow.\***  
  Main UI window connecting actions to backend functionality.

- **ScreenCaptureEngine.\***  
  Handles screen capture logic and prepares frames for recording.

- **CMakeLists.txt**  
  Build configuration file.

## Prerequisites

- **Qt 5.x or 6.x** (with Qt Widgets and Multimedia modules)  
- **CMake 3.16+**  
- **FFmpeg** (installed and added to system PATH)  
- C++17 compatible compiler (GCC, Clang, or MSVC)

### FFmpeg Setup

- **Windows:** Download FFmpeg static build and add the `bin` folder to PATH  
- **macOS:** Install via Homebrew  
  ```bash
  brew install ffmpeg

./QtScreenRecorder
