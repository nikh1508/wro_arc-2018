from tkinter import *
from time import sleep
import threading
import serial

ser = serial.Serial(port='/dev/ttyS0', baudrate=115200)

def sendData(ch, val):
        data = []
        byte_ct = 0
        print("Sending %c :: %d"%(ch, val))
        while val:
                data.append(0b11111111 & val)
                val = val >> 8
                byte_ct = byte_ct + 1
##        ser.write(b'b')
##        ser.write(bytes(chr(byte_ct), 'latin_1'))
        ser.write(bytes(ch, 'latin_1'))
        for i in reversed(data):
                ser.write(bytes(chr(i), 'latin_1'))

master = Tk()
LEN = 1000

Kp = Scale(master,length=LEN, label='Kp', from_=0, to=255, orient=HORIZONTAL)
Kp.pack()

Ki = Scale(master, length=LEN, label='Ki',from_=0, to=255, orient=HORIZONTAL)
Ki.pack()

Kd = Scale(master, length=LEN, label='Kd', from_=0, to=255, orient=HORIZONTAL)
Kd.pack()
#Button(master, text='Show', command=show_values).pack()


# show_values()
def print_val():
    print(Kp.get(), Ki.get(), Kd.get())
    Kp.after(100, print_val)

def send_val():
	sendData('p', int(Kp.get()))
	print(Kp.get())
	sendData('i', int(Ki.get()))
	sendData('d', int(Kd.get()))
	Kp.after(100, send_val)

Kp.set(1)
Ki.set(1)
Kd.set(1)
Kp.after(100, send_val)
mainloop()

