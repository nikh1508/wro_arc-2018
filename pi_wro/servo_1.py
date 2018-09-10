import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

GPIO.setup(12, GPIO.OUT)

p = GPIO.PWM(12, 50)

p.start(7.5)
# 2.5   7.5    12.5
x=12.5
for i in range(0,2):
  print (i)
  p.ChangeDutyCycle(x)  # turn towards 90 degree
  time.sleep(1) # sleep 1 second
  p.ChangeDutyCycle(x)  # turn towards 0 degree
  time.sleep(1) # sleep 1 second
  p.ChangeDutyCycle(x) # turn towards 180 degree
  time.sleep(1) # sleep 1 second 
p.stop()
GPIO.cleanup()
