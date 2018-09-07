import serial

ser = serial.Serial(port='/dev/ttyACM0', baudrate=115200)

def sendData(ch, val):
	ser.write(bytes(ch, 'utf-8'))
	ser.write(bytes(chr(val), 'utf-8'))
