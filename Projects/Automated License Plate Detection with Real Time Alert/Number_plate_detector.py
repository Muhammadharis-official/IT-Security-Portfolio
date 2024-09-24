import cv2
import numpy as np
import pytesseract
from flask import Flask, render_template, Response

app = Flask(__name__)

database = ["ABC1234", "XYZ5678", "LMN9101"]
matched_plates = []

def detect_plate(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5, 5), 0)
    edges = cv2.Canny(blur, 100, 200)
    contours, _ = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    
    for contour in contours:
        x, y, w, h = cv2.boundingRect(contour)
        aspect_ratio = w / float(h)
        if 2 < aspect_ratio < 5:
            plate_img = gray[y:y+h, x:x+w]
            text = pytesseract.image_to_string(plate_img, config='--psm 8')
            if text.strip() in database:
                matched_plates.append(text.strip())
                return True
    return False

def generate_frames():
    cap = cv2.VideoCapture(0)
    while True:
        success, frame = cap.read()
        if not success:
            break
        if detect_plate(frame):
            # Code to trigger sound alarm goes here
            pass
        yield cv2.imencode('.jpg', frame)[1].tobytes()

@app.route('/')
def index():
    return render_template('index.html', matched_plates=matched_plates)

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    app.run(debug=True)