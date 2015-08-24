#Send serial data from the computer to the Arduino

import serial 
import time

arduinoSerialData = serial.Serial('com3', 9600)
time.sleep(2)

#infinite loop
while(1==1):
    x = raw_input('Enter input \n')
    arduinoSerialData.write(x)
