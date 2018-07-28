#RPi Pinouts

#I2C Pins 
#GPIO2 -> SDA
#GPIO3 -> SCL

import smbus2
import time

bus = smbus2.SMBus(1)

SLAVE_ADDR = 0x07              ##Set the Address Here.

def sendData(ch, counts, byte = 2):
    bus.write_byte(SLAVE_ADDR, byte + 3)
    counts_byte = []
    for i in range(byte):
        counts_byte.append(0b11111111 & counts)
        counts = counts>>8
    bus.write_byte(SLAVE_ADDR, ord(ch))
    for i in reversed(counts_byte):
        bus.write_byte(SLAVE_ADDR, i)
    return -1


def readNumber(byte=4):
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
    
while True:
    ## Send Data to Arduino
    ch = input("Enter the character to be sent : ")
    num = int(input("Enter Encoder Counts : "))
    temp = num
    totalBytes = 0
    while temp:
        totalBytes += 1
        temp = temp >> 8
    sendData (ch, num, totalBytes)
    ## Recv Data from Arduino
    time.sleep(.01)
    print(readNumber())

#End

