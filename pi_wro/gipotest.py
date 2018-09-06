import RPi.GPIO as GPIO
import time

cnl = 7
GPIO.setmode(GPIO.BOARD)
GPIO.setup(cnl,GPIO.IN,GPIO.PUD_DOWN)
try:
    while(True):
        print(GPIO.input(cnl))
        time.sleep(0.5)
except KeyboardInterrupt:
    GPIO.cleanup()
    print("Exit")
