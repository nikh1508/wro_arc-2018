import BlynkLib
import time
import sendOverSerial

BLYNK_AUTH = 'c729d62d480f4f93ba08fbac848655dd'

# Initialize Blynk
blynk = BlynkLib.Blynk(BLYNK_AUTH)

# Register Virtual Pins
@blynk.VIRTUAL_WRITE(0)
def my_write_handler(value):
    print('Current Power value: {}'.format(value))
    sendOverSerial.sendData('o', int(value))

@blynk.VIRTUAL_WRITE(1)
def my_write_handler(value):
    print('Current Kp value: {}'.format(value))
    sendOverSerial.sendData('p', int(value))

@blynk.VIRTUAL_WRITE(2)
def my_write_handler(value):
    print('Current Ki value: {}'.format(value))
    sendOverSerial.sendData('i', int(value))

@blynk.VIRTUAL_WRITE(3)
def my_write_handler(value):
    print('Current Kd value: {}'.format(value))
    sendOverSerial.sendData('d', int(value))

# Start Blynk (this call should never return)
blynk.run()
