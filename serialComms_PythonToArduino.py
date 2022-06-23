# Serial Communication Template between Python on PC and Arduino Microcontroller
# Will Graham
# V2
# 6-16-2022
# U of U DRL Lab

"""
#pyserial notes
Make sure to use a timeout with readline(), otherwise it will indefinitely block forever if it doesn't receive the '\n' character
Timeout will return the \n character
"""


# Importing Libraries
import time
import serial

arduino = serial.Serial(port='COM3', baudrate=115200)
PWM_Outputs = [255, 255, 0, 0]
def write_read():
    t1 = time.time_ns()
    print("t1 = ", t1)
    print(type(t1))
    vals = bytearray(PWM_Outputs)
    print(vals)
    arduino.write(vals)
    
    return

if __name__ == "__main__":
    while True:
        write_read()