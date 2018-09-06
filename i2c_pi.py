import smbus
import time

bus = smbus.SMBus(1)

address = 0x04

def writeNumber(value):
    bus.write_byte(address,value)
    return -1
def readNumber():
    number = bus.read_byte(address)
    return number
while True:
    var = int(input("Number :"))
    num = ord(input("Char :"))
    if not var:
        continue
    writeNumber(var)
    time.sleep(1)
    writeNumber(num)
    print ("I sent: ")
    print (var)
    time.sleep(1)
    number = readNumber()
    print ("Recive : ")
    print (number)
    if var == 8:
        break
