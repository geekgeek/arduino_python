#Send serial data from the computer to the Arduino

import serial #import serial library
arduinoSerialData = serial.Serial('com3', 9600)


while(1==1):
    x = raw_input('Enter input')
    arduinoSerialData.write(x)
