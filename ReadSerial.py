
#Libraries needed:
# Pyserial : https://pypi.python.org/pypi/pyserial
# https://www.youtube.com/watch?v=mF5cE3DS50s&index=2&list=PLGs0VKk2DiYylFUUMMv9WiL3x3tpscDUQ


import serial #import serial library
arduinoSerialData = serial.Serial('com3', 9600)

#Infinite loop
#read data if it is data to be found.
while (1==1):
    if (arduinoSerialData.inWaiting()>0):
        myData = arduinoSerialData.readline()
        print myData
        
        
    

