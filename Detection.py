import cv2
import serial
import time

#initalize camera & serial connection

esp32 = serial.Serial("", 115200, timeout=1)
time.sleep(2) #wait 2 seconds for connection to establish

#important variables
targetAngle = 0

def send_servo_angle(angle):
    command = f"{angle}/n"
    esp32.write(command.encode())

while True:
    #person detection logic
    
    #calculate target angle offset

    #send angle to servo driver
    send_servo_angle(targetAngle)