# Replay Recorder & Screenshot Tool

A lightweight Windows application that captures **screenshots** and **instant 30120 second gameplay replays**, even in **exclusive fullscreen** games. Designed as a customizable, moddable alternative to ShadowPlay and Xbox Game Bar.

---

## Features

### 1. Rolling Replay Buffer

* Continuously captures frames + audio while running.
* Stores only the **last X seconds** (default: 30s).
* Press the hotkey  instantly saves the last recorded segment.
* Supports buffer durations:

  * 10s
  * 15s
  * 30s
  * 60s
  * 120s

### 2. Screenshot Capture

* Works in exclusive fullscreen and borderless modes.
* Customizable global hotkey.
* Supports PNG, JPEG, WEBP, BMP.
* Auto-organizes screenshots per-game.

### 3. Works in All Games

Uses Windows-native APIs:

* **DXGI Desktop Duplication API**  lossless/high-performance frame capture.
* **WASAPI Loopback**  system audio capture.

Supports: DirectX9/11/12, Vulkan, OpenGL, Exclusive Fullscreen.

### 4. Lightweight Video Encoding

Encodes replay clips using:

* **FFmpeg** (required)
* Optional GPU encoders:

  * NVIDIA NVENC
  * Intel QuickSync
  * AMD AMF

Output formats:

* MP4 (H.264)
* WEBM (VP9)
* MKV

### 5. Global Hotkeys

* Save replay
* Take screenshot
* Start/stop full recording
* Bookmark clip moments

### 6. Storage Management

* Auto-delete older clips.
* User-defined disk cap (e.g., keep only last 5GB).
* Auto-compress older videos.

### 7. Per-Game Profiles

Each game can have unique settings:

* Capture resolution
* Framerate (30/60/90+)
* Bitrate
* Storage paths
* Screenshot format

---

## How It Works

### 1. Real-Time Capture Loop

The app:

* Captures frames at target FPS
* Captures desktop audio as PCM
* Stores both into an in-memory **circular buffer** (ring buffer)

Example buffer sizes:

* 60 FPS  30 seconds  1800 frames
* Oldest frames automatically overwritten

### 2. Saving a Clip

When the hotkey is pressed:

1. Freeze the buffer
2. Send frames + audio to FFmpeg
3. FFmpeg outputs the video file
4. Resume capture immediately

Fast, seamless, and low overhead.

---

## Estimated Resource Usage

### Raw frame size (1080p): ~6 MB

* 1920  1080  3 bytes

### Uncompressed 30s buffer: ~10.8 GB (not feasible)

### Optimized buffer with lightweight compression:

* MJPEG or YUV422 reduces usage to **12 GB** for 1080p60.

### GPU offloading (optional):

* NVENC reduces CPU load significantly.

---

## Optional Features

* Minimal overlay displaying: "Replay Buffer Active"
* Screenshot + last-5s replay combo
* Bookmark tags for naming clips
* Auto-generate folders per game

---

## Tech Stack

**Language:** C++ or C# (with C++ interop)

**Core APIs:**

* DXGI Desktop Duplication (frame capture)
* WASAPI Loopback (audio capture)
* RawInput API (hotkeys)

**Encoding:**

* FFmpeg libraries (required)
* Optional NVENC/AMF/QuickSync

**UI:**

* WinUI / WPF / Qt

**Database:**

* SQLite for clip history

---

## Project Structure 

```
ReplayRecorder/

 src/
    capture/
       FrameCapture.cpp
       AudioCapture.cpp
       DesktopDuplication.cpp
   
    buffer/
       CircularBuffer.cpp
       FrameCompressor.cpp
   
    encode/
       FFmpegEncoder.cpp
       EncoderConfig.cpp
   
    ui/
       MainWindow.xaml
       Overlay.cpp
   
    utils/
       Hotkeys.cpp
       Settings.cpp
       GameDetection.cpp

 assets/
 docs/
 README.md
```

---

## Building the MVP

1. Implement DXGI frame capture
2. Add WASAPI loopback audio
3. Create circular buffer
4. Add clip saving to FFmpeg
5. Add hotkey system
6. Add simple UI

After MVP, add:

* storage management
* per-game profiles
* screenshot tools

---

## Requirements

* Windows 10/11
* FFmpeg (bundled or dynamic)
* GPU recommended (optional NVENC)

---

## License

MIT (recommended for open-source)
