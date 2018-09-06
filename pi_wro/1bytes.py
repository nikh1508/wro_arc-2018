#RPi Pinouts
import RPi.GPIO as GPIO
import time
#I2C Pins 
#GPIO2 -> SDA
#GPIO3 -> SCL

import smbus
import time
cnl = 7
GPIO.setmode(GPIO.BOARD)
GPIO.setup(cnl,GPIO.IN,GPIO.PUD_DOWN)
bus = smbus.SMBus(1)

SLAVE_ADDR = 0x07              ##Set the Address Here.

def sendData(counts, byte):
    try:
        counts_byte = []
        for i in range(byte):
            counts_byte.append(0xff & counts)
            counts = counts>>8
        for i in reversed(counts_byte):
            bus.write_byte(SLAVE_ADDR, i)
    except:
        print("Error occured while sending data.")
    return -1


def readString(byte=1):
    try:
        print("Requesting %d Bytes from Arduino"%byte)
        number = bus.read_i2c_block_data(SLAVE_ADDR, 0, byte)
        str = ""
        for i in number:
                str += chr(i)
        return str
    except:
        print ("Failed to Recv any Data")
        return -1
num=0
while True:
    ## Send Data to Arduino
    num = int(input("Number : " ))
    if num==-1:
        break
    sendData (num, 1)
    while(GPIO.input(cnl)==0):
        time.sleep(.01)
        print('0')
    print(GPIO.input(cnl))
    time.sleep(0.5)
GPIO.cleanup()
#End

