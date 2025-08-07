
# 🦾 Robotic Arm WebServer (5-DOF) – ESP32 + WebSocket

A 5-DOF robotic arm built using 2 SG90 and 3 MG995 servo motors, controlled wirelessly through a web interface using WebSockets. Features include real-time control and a **motion recording & replay system** ideal for repetitive industrial automation tasks.

## 📌 Features
- 5 DOF using SG90 and MG995 servos
- Real-time WebSocket control from browser
- Motion recording and replay
- ESP32 powered and Wi-Fi based

## 📂 Folder Overview
- `hardware/`: Circuit diagrams and arm specs
- `firmware/`: ESP32 code (Arduino or MicroPython)
- `web/`: HTML/CSS/JS for control UI
- `media/`: Demos and screenshots

## 🚀 Getting Started
1. Upload code to ESP32
2. Connect ESP32 to Wi-Fi
3. Open ESP32 IP in browser to control arm

## 🛠️ To-Do
- Add SD card support for routines
- Add camera module for vision-based actions
