**[Automated Number Plate Recognition System](https://github.com/Muhammadharis-official/IT-Security-Portfolio/tree/IT-security-Portfolio/Projects/Automated%20License%20Plate%20Detection%20with%20Real%20Time%20Alert)**

## Overview

This project implements a real-time vehicle number plate recognition system using Python. It leverages computer vision techniques to capture video from a webcam, detect number plates, and match them against a predefined database. The results are displayed on a web interface.

#Libraries Used
- **OpenCV (cv2):** For image processing and computer vision tasks.
- **NumPy (np):** For numerical operations and handling arrays.
- **Pytesseract:** An Optical Character Recognition (OCR) tool for extracting text from images.
- **Flask:** A lightweight web framework for building web applications in Python.
- 
# Application Structure

Captures video from a webcam.
Processes each frame to detect number plates.
Compares detected number plates against a predefined list (database).
Triggers an alarm if a match is found (alarm functionality not yet implemented).
Displays results on a web page.

# Installation
Ensure you have Python installed on your machine.
**Install the required libraries:**
```bash
pip install opencv-python numpy pytesseract flask
```
# Usage
Connect your webcam.
**Run the application:**
```bash
python app.py
```
Open your web browser and navigate to http://127.0.0.1:5000/ to view the application.

# Enhancements
Implement alarm functionality when a plate is matched.
Integrate with an external database for dynamic plate management.
Improve the user interface for better interaction.

![IMg1](https://github.com/user-attachments/assets/2e5cdcac-bfb1-49f4-8576-7432a41986a2)

---

# Smart Prepaid Electricity Meter System

## Overview
This project is designed to create a smart prepaid electricity meter system that integrates various functionalities such as energy consumption monitoring, balance alerts, and remote management via Firebase.

## Key Components
- **GSM Module (SIM800A):** For sending SMS alerts.
- **Wi-Fi Module (ESP8266):** For remote monitoring and control.
- **Arduino ATMega 2560:** The main microcontroller for processing.
- **CT Sensor:** To measure current and calculate energy consumption.
- **Firebase:** For cloud-based data storage and remote monitoring.

## Functionality
- Reads energy consumption from the CT sensor.
- Sends alerts when the balance falls below specified thresholds.
- Disconnects power when the balance reaches zero.
- Updates Firebase with current status for remote access.

## Installation
1. Set up the Arduino IDE on your computer.
2. Install necessary libraries for GSM, Wi-Fi, and Firebase integration.
3. Upload the code to your Arduino board.

## Usage
1. Connect all hardware components according to specifications.
2. Replace placeholders in the code with actual values (e.g., Wi-Fi credentials, Firebase URL).
3. Power on the device to start monitoring energy consumption.

## Enhancements
- Add more detailed reporting features in Firebase.
- Implement additional alert mechanisms (e.g., email notifications).
- Improve user interface for better interaction with the system.

![1716481243276](https://github.com/user-attachments/assets/3bdf2bed-e116-4c7e-972b-83789ef22379)

---

# Virtual Mouse Using AI

## Overview
This project implements a virtual mouse controlled by hand gestures using Python. It utilizes computer vision techniques to track hand movements and translate them into mouse actions.

## Required Libraries
- **OpenCV:** For image processing tasks.
- **MediaPipe:** For hand tracking capabilities.
- **autopy or pyautogui:** For controlling mouse movements and clicks.
- **NumPy:** For numerical operations.

**Install the required libraries:**
```bash
pip install opencv-python mediapipe autopy numpy
```

## Implementation Steps
1. Set up the camera feed to capture video frames using OpenCV and MediaPipe.
2. **Detect hand gestures to control mouse actions:**
   - **Fist:** Activate virtual mouse.
   - **Index Finger Pointing:** Move cursor.
   - **Pinch Gesture:** Click action (thumb and index together).
   - **Open Hand:** Scroll action.
3. Control mouse movement based on finger positions detected by MediaPipe.

## Usage
**Run the script:**
```bash
python virtual_mouse.py
```
Perform gestures in front of the camera to control mouse actions.

## Enhancements
- Implement more complex gesture recognition for additional mouse functions.
- Improve accuracy through machine learning models for gesture detection.

![img1](https://github.com/user-attachments/assets/357a089d-4b99-44b8-b980-5c2f02a930db)

---

# Building a Multi-GPU Cluster for Hashcat Using Linux and NVIDIA

## Overview
This guide provides a comprehensive approach to building a multi-GPU cluster optimized for Hashcat password cracking. By utilizing budget-friendly NVIDIA GeForce 1650 GTX GPUs, this setup offers a cost-effective solution compared to investing in high-end GPUs. The cluster is also suitable for machine learning and other CUDA programming tasks.

## Requirements

### Hardware
- **GPUs:** 5-6 NVIDIA GeForce 1650 GTX GPUs (approximately $139.99 each during sales).
- **PC:** Refurbished HP Z840 with at least 128GB RAM and 1TB SSD (around $460).
- **GPU Risers:** 6 PCI-E risers for GPU installation.
- **Power Supply:** EVGA 1500W or equivalent (second-hand for around $40).
- **Frame Materials:** Extruded aluminum or pre-owned mining rig frame.

### Miscellaneous Tools:
- Drill and drill bits
- Tap and die set
- Metric Allen wrench set
- Phillips screwdriver, pliers

### HDMI Screen:
A 7” touchscreen monitor.

### Software
**Operating System:**
Kali Linux or Ubuntu 22.04 LTS.

**NVIDIA Drivers:**
Download the latest drivers from NVIDIA's website.

## Setup Instructions

### Step 1: Hardware Assembly

1. **Test Components:**
   Before assembling, ensure all components (GPUs, risers) are functioning.

2. **Frame Construction:**
   If using extruded aluminum, drill holes for screws using a tap-and-die set. Secure GPU risers to the frame with M3 screws.

3. **Install GPUs:**
   Attach one GPU per riser, ensuring proper airflow.

4. **Power Connections:**
   Refer to documentation for connecting power cables to GPUs and risers.

### Step 2: Software Installation

1. **Install Operating System:**
   Follow standard procedures to install Kali Linux or Ubuntu on the HP Z840.

2. **Install NVIDIA Drivers:**
   Download the appropriate driver (e.g., `NVIDIA-Linux-x86_64-535.146.02.run`).

   Execute the driver installation as root:
   ```bash
   sudo bash ./NVIDIA-Linux-x86_64-535.146.02.run
   ```

3. **Install CUDA SDK:**
   Download and install the CUDA SDK using:
   ```bash
   wget https://developer.download.nvidia.com/compute/cuda/12.3.2/local_installers/cuda_12.3.2_545.23.08_linux.run 
   sudo sh cuda_12.3.2_545.23.08_linux.run 
   ```

### Step 3: Verification

After installation, verify the setup by running:
```bash
/usr/local/cuda/extras/demo_suite/deviceQuery
```
Ensure all GPUs are detected and functioning correctly.

## Cost Analysis
The total expenditure for this setup was approximately RS430,660, which includes both new and second-hand equipment. Purchasing everything new could increase costs by about RS138925.

## Conclusion
This multi-GPU cluster provides a robust solution for password cracking with Hashcat while remaining cost-effective and versatile for other computational tasks like machine learning.

![Fig](https://github.com/user-attachments/assets/e307a875-ba3a-47b6-aaa9-2c6e37ea3ef4)
```
