# Vehicle Number Plate Recognition System

## Overview
This project implements a real-time vehicle number plate recognition system using Python. It leverages computer vision techniques to capture video from a webcam, detect number plates, and match them against a predefined database. The results are displayed on a web interface.

## Libraries Used
- **OpenCV (cv2):** For image processing and computer vision tasks.
- **NumPy (np):** For numerical operations and handling arrays.
- **Pytesseract:** An Optical Character Recognition (OCR) tool for extracting text from images.
- **Flask:** A lightweight web framework for building web applications in Python.

## Application Structure
- Captures video from a webcam.
- Processes each frame to detect number plates.
- Compares detected number plates against a predefined list (database).
- Triggers an alarm if a match is found (alarm functionality not yet implemented).
- Displays results on a web page.

## Installation
Ensure you have Python installed on your machine.

**Install the required libraries:**
```bash
pip install opencv-python numpy pytesseract flask

Usage
Connect your webcam.
Run the application:
bash
python app.py

Open your web browser and navigate to http://127.0.0.1:5000/ to view the application.
Enhancements
Implement alarm functionality when a plate is matched.
Integrate with an external database for dynamic plate management.
Improve the user interface for better interaction.
