import serial
from time import sleep
ser = serial.Serial(port='/dev/ttyS0', baudrate=9600)

def sendData(ch, val):
	data = []
	while val:
		data.append(0b11111111 & val)
		val = val >> 8
	print("Sending %c :: %r"%(ch, val))
	ser.write(bytes(ch, 'latin_1'))
	for i in reversed(data):
		ser.write(bytes(chr(i), 'latin_1'))
