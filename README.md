Qt Screen and Video Recorder

This project is a desktop application built using Qt and FFmpeg to provide both screen recording and screenshot functionality. The application is structured with modular components to handle screen capture, audio capture, file management, configuration, and process control.

Overview

The application uses Qt for the user interface, event handling, and threading, while FFmpeg is used for the actual video and audio encoding. The project includes dedicated managers for each subsystem, ensuring clear separation of responsibilities and easier maintainability.

Key Features
Screen Recording

Records the desktop screen using FFmpeg.

Supports customizable FFmpeg parameters.

Runs FFmpeg as a managed background process.

Screenshot Capture

Captures still images of the screen.

Saves screenshots through the FileManager module with organized naming and path handling.

Audio Capture

Provides infrastructure for capturing microphone or system audio through FFmpeg.

System Hotkeys

Global hotkeys allow users to start or stop recording and take screenshots without switching windows.

Modular Project Structure

The codebase includes components such as:

ScreenCaptureEngine

AudioCaptureEngine

CaptureManager

FileManager

HotkeyManager

ConfigManager

FFmpegProcess

MainWindow

Each module is responsible for a distinct part of the application, resulting in a clean and extensible architecture.

Technologies Used

Qt 6 for UI, timers, signals/slots, and system integration

FFmpeg for video and audio encoding

**C++**17 for the application logic and structure

Build Instructions

Ensure FFmpeg is installed and added to your system path.

Open the project in Qt Creator or build using CMake.

Configure any necessary FFmpeg paths inside the configuration module.

Build and run the application.

Purpose

This project was created to demonstrate skills in C++, Qt application development, system-level screen capture, and integrating external tools such as FFmpeg. It showcases an understanding of modular design, event-driven programming, and multimedia processing.
