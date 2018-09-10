import cv2
import numpy as np
import smbus
import RPi.GPIO as GPIO
import time

class Block:
    def __int__(self):
        self.name

        
    def setname(self,nm):
        self.name=nm

    def setxPos(self,x):
        self.x=x

    def setyPos(self,y):
        self.y=y

    def setHSVmin(self,a,b,c):
        self.hl=a
        self.sl=b
        self.vl=c

    def setHSVmax(self,a,b,c):
        self.hh=a
        self.sh=b
        self.vh=c
        
    def getxPos(self):
        return self.x

    def getyPos(self):
        return self.y

    def getHSVmin(self):
        return self.hl,self.sl,self.vl

    def getHSVmax(self):
        return self.hh,self.sh,self.vh

    def getname(self):
        return self.name

    def setcolor(self,a,b,c):
        self.b=a
        self.g=b
        self.r=c

    def getcolor(self):
        return self.b,self.g,self.r

#b=Block()
#b.setname("Blue")
#b.setxPos(3)
#b.setyPos(9)
#b.setHSVmin(10,20,30)
#b.setHSVmax(40,50,60)

#print b.getname()
#print b.getxPos()
#print b.getyPos()
#print b.getHSVmin()
#print b.getHSVmax()

#------------------------------------------------------------------
# Defining Sequence------------------------------------------------
#1-Blue 2-Yello 3-DarkBlue 4-Red 5-Orange 6-Green  [3][8][8][2]
sequence=np.array([
            [
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 10,2 ],[ 10,2 ],[ 11,1 ],[ 11,1 ],[ 11,1 ],[ 11,1 ],[ 12,2 ],[ 12,2 ] ],
                [ [ 10,2 ],[ 10,2 ],[ 8 ,6 ],[ 8 ,6 ],[ 9 ,4 ],[ 9 ,4 ],[ 12,2 ],[ 12,2 ] ],
                [ [ 1 ,1 ],[ 7 ,6 ],[ 7 ,6 ],[ 8 ,6 ],[ 8 ,6 ],[ 9 ,4 ],[ 9 ,4 ],[ 6 ,3 ] ],
                [ [ 1 ,1 ],[ 2 ,5 ],[ 7 ,6 ],[ 7 ,6 ],[ 5 ,5 ],[ 6 ,3 ],[ 6 ,3 ],[ 6 ,3 ] ],
                [ [ 1 ,1 ],[ 2 ,5 ],[ 3 ,4 ],[ 3 ,4 ],[ 5 ,5 ],[ 5 ,5 ],[ 5 ,5 ],[ 4 ,3 ] ],
                [ [ 1 ,1 ],[ 2 ,5 ],[ 2 ,5 ],[ 3 ,4 ],[ 3 ,4 ],[ 4 ,3 ],[ 4 ,3 ],[ 4 ,3 ] ]
            ],
            [
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 10,4 ],[ 10,4 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 11,6 ],[ 11,6 ] ],
                [ [ 5 ,5 ],[ 10,4 ],[ 10,4 ],[ 9 ,2 ],[ 9 ,2 ],[ 11,6 ],[ 11,6 ],[ 7 ,3 ] ],
                [ [ 5 ,5 ],[ 6 ,4 ],[ 6 ,4 ],[ 9 ,2 ],[ 9 ,2 ],[ 8 ,6 ],[ 8 ,6 ],[ 7 ,3 ] ],
                [ [ 5 ,5 ],[ 5 ,5 ],[ 6 ,4 ],[ 6 ,4 ],[ 8 ,6 ],[ 8 ,6 ],[ 7 ,3 ],[ 7 ,3 ] ],
                [ [ 1 ,2 ],[ 1 ,2 ],[ 2 ,5 ],[ 4 ,1 ],[ 4 ,1 ],[ 4 ,1 ],[ 4 ,1 ],[ 3 ,3 ] ],
                [ [ 1 ,2 ],[ 1 ,2 ],[ 2 ,5 ],[ 2 ,5 ],[ 2 ,5 ],[ 3 ,3 ],[ 3 ,3 ],[ 3 ,3 ] ]
            ],
            [
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 9 ,5 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 11,3 ],[ 10,2 ],[ 10,2 ] ],
                [ [ 9 ,5 ],[ 9 ,5 ],[ 9 ,5 ],[ 11,3 ],[ 11,3 ],[ 11,3 ],[ 10,2 ],[ 10,2 ] ],
                [ [ 5 ,4 ],[ 5 ,4 ],[ 8 ,1 ],[ 8 ,1 ],[ 8 ,1 ],[ 8 ,1 ],[ 6 ,6 ],[ 6 ,6 ] ],
                [ [ 1 ,3 ],[ 5 ,4 ],[ 5 ,4 ],[ 7 ,2 ],[ 7 ,2 ],[ 6 ,6 ],[ 6 ,6 ],[ 3 ,5 ] ],
                [ [ 1 ,3 ],[ 2 ,4 ],[ 2 ,4 ],[ 7 ,2 ],[ 7 ,2 ],[ 4 ,6 ],[ 4 ,6 ],[ 3 ,5 ] ],
                [ [ 1 ,3 ],[ 1 ,3 ],[ 2 ,4 ],[ 2 ,4 ],[ 4 ,6 ],[ 4 ,6 ],[ 3 ,5 ],[ 3 ,5 ] ]
            ],
            [
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 10,5 ],[ 10,5 ],[ 10,5 ],[ 12,2 ],[ 12,2 ],[ 11,5 ],[ 11,5 ],[ 11,5 ] ],
                [ [ 7 ,4 ],[ 7 ,4 ],[ 10,5 ],[ 12,2 ],[ 12,2 ],[ 11,5 ],[ 8 ,6 ],[ 8 ,6 ] ],
                [ [ 5 ,3 ],[ 7 ,4 ],[ 7 ,4 ],[ 9 ,2 ],[ 9 ,2 ],[ 8 ,6 ],[ 8 ,6 ],[ 6 ,3 ] ],
                [ [ 5 ,3 ],[ 5 ,3 ],[ 5 ,3 ],[ 9 ,2 ],[ 9 ,2 ],[ 6 ,3 ],[ 6 ,3 ],[ 6 ,3 ] ],
                [ [ 3 ,1 ],[ 3 ,1 ],[ 3 ,1 ],[ 3 ,1 ],[ 4 ,1 ],[ 4 ,1 ],[ 4 ,1 ],[ 4 ,1 ] ],
                [ [ 0 ,0 ],[ 1 ,4 ],[ 1 ,4 ],[ 0 ,0 ],[ 0 ,0 ],[ 2 ,6 ],[ 2 ,6 ],[ 0 ,0 ] ],
                [ [ 1 ,4 ],[ 1 ,4 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 2 ,6 ],[ 2 ,6 ] ]
            ],
            [
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ],[ 0 ,0 ] ],
                [ [ 9 ,5 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 11,3 ],[ 10,2 ],[ 10,2 ] ],
                [ [ 9 ,5 ],[ 9 ,5 ],[ 9 ,5 ],[ 11,3 ],[ 11,3 ],[ 11,3 ],[ 10,2 ],[ 10,2 ] ],
                [ [ 5 ,4 ],[ 5 ,4 ],[ 8 ,1 ],[ 8 ,1 ],[ 8 ,1 ],[ 8 ,1 ],[ 6 ,6 ],[ 6 ,6 ] ],
                [ [ 1 ,5 ],[ 5 ,4 ],[ 5 ,4 ],[ 7 ,2 ],[ 7 ,2 ],[ 6 ,6 ],[ 6 ,6 ],[ 3 ,3 ] ],
                [ [ 1 ,5 ],[ 2 ,4 ],[ 2 ,4 ],[ 7 ,2 ],[ 7 ,2 ],[ 4 ,6 ],[ 4 ,6 ],[ 3 ,3 ] ],
                [ [ 1 ,5 ],[ 1 ,5 ],[ 2 ,4 ],[ 2 ,4 ],[ 4 ,6 ],[ 4 ,6 ],[ 3 ,3 ],[ 3 ,3 ] ]
            ],
            [
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 10,5 ],[ 10,5 ],[ 10,5 ],[ 12,2 ],[ 12,2 ],[ 11,5 ],[ 11,5 ],[ 11,5 ] ],
                [ [ 7,4 ],[ 7,4 ],[ 10,5 ],[ 12,2 ],[ 12,2 ],[ 11,5 ],[ 8,6 ],[ 8,6 ] ],
                [ [ 5,3 ],[ 7,4 ],[ 7,4 ],[ 9,2 ],[ 9,2 ],[ 8,6 ],[ 8,6 ],[ 6,3 ] ],
                [ [ 5,3 ],[ 5,3 ],[ 5,3 ],[ 9,2 ],[ 9,2 ],[ 6,3 ],[ 6,3 ],[ 6,3 ] ],
                [ [ 3,1 ],[ 3,1 ],[ 3,1 ],[ 3,1 ],[ 4,1 ],[ 4,1 ],[ 4,1 ],[ 4,1 ] ],
                [ [ 0,0 ],[ 2,4 ],[ 2,4 ],[ 0,0 ],[ 0,0 ],[ 1,6 ],[ 1,6 ],[ 0,0 ] ],
                [ [ 2,4 ],[ 2,4 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 1,6 ],[ 1,6 ] ]
            ]
           ])


#------------------------------------------------------------------
#defining Blocks data----------------------------------------------
my_block=[]

b=Block()
b.setname("Blue")
b.setHSVmin(85,76,49)
b.setHSVmax(103,157,140)
b.setcolor(255,0,0)

y=Block()
y.setname("Yellow")
y.setHSVmin(22,178,105)
y.setHSVmax(31,255,182)
y.setcolor(0,255,255)

d=Block()
d.setname("DarkBlue")
d.setHSVmin(107,85,47)
d.setHSVmax(130,158,149)
d.setcolor(139,0,0)

r=Block()
r.setname("Red")
r.setHSVmin(0,156,39)
r.setHSVmax(8,225,145)
r.setcolor(0,0,255)

o=Block()
o.setname("Orange")
o.setHSVmin(9,189,69)
o.setHSVmax(16,255,141)
o.setcolor(0,165,255)

g=Block()
g.setname("Green")
g.setHSVmin(39,209,65)
g.setHSVmax(49,255,118)
g.setcolor(0,255,0)

my_block.append(b)
my_block.append(y)
my_block.append(d)
my_block.append(r)
my_block.append(o)
my_block.append(g)


#-----------------------------------------------------------------

bus = smbus.SMBus(1)
SLAVE_ADDR = 0x07

cnl = 7
GPIO.setmode(GPIO.BOARD)
GPIO.setup(cnl,GPIO.IN,GPIO.PUD_DOWN)

arena_block = [-1,-1,-1,-1,-1,-1]
current_working_Block = 1;


#------------------------------------------------------------------
#Defining data variables opencv------------------------------------



cap = cv2.VideoCapture(-1)
Found_Block=Block()
total_color = 6
total_seq = 6
total_Blocks = 12
seq_index = -1
camAngle = 750
tempframe = cap.read()
#-------------------------------------------------------------------
def sendData(counts, byte):
    try:
        counts_byte = []
        for i in range(byte):
            counts_byte.append(0b11111111 & counts)
            counts = counts>>8
        for i in reversed(counts_byte):
            bus.write_byte(SLAVE_ADDR, i)
    except:
        print("Error occured while sending data.")
    return -1

        
def readString(byte = 1):
    try:
        print ("Request %d bytes from Arduino "%byte)
        number = bus.read_i2c_block_data(SLAVE_ADDR,0,byte)
        str = ""
        for i in number:
            str+=chr(i)
        return str
    except:
        print ("Failed to recv any Data")
        return -1
        
def callback(x):
    pass


def track(index):
    print ('Search : '+my_block[index].getname())
    ret, frame = cap.read()
    r=200.0/frame.shape[0]
    dim=(200,int(frame.shape[0]*r))
    for i in range(5):
        ret,frame = cap.read()
        #frame=frame[120:360,160:480]
        x,y,b=np.shape(frame)
        #cv2.imshow('img',frame)
        frame=cv2.pyrUp(frame)
        dst=cv2.resize(frame,dim,interpolation = cv2.INTER_AREA)
        cv2.imshow('img1',dst)
        cv2.waitKey(1)
        
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    hsvmin=np.array(my_block[index].getHSVmin())
    hsvmax=np.array(my_block[index].getHSVmax())
    hsv=cv2.inRange(hsv, hsvmin, hsvmax)
    hsv=cv2.resize(hsv,dim,interpolation = cv2.INTER_AREA)
    cv2.imshow('hsv',hsv)
    
    kernel = np.ones((5,5),np.uint8)
    hsv = cv2.erode(hsv,kernel,iterations = 1)
    erosion = cv2.erode(hsv,kernel,iterations = 1)
    hsv = cv2.dilate(hsv,kernel,iterations = 1)
    hsv = cv2.dilate(hsv,kernel,iterations = 1)
    
    contours, hierarchy = cv2.findContours(hsv,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    if len(contours)!=0 :
        cnt = contours[0]
        M = cv2.moments(cnt)
        x = int(M['m10']/M['m00'])
        y = int(M['m01']/M['m00'])
        Found_Block.setname(my_block[index].getname())
        Found_Block.setxPos(x)
        Found_Block.setyPos(y)
        return 0
    return 1



def find_Block():
    seq_index=-1
    for i in range(total_color):
        if(track(i) == 0):
            print 'Found     : '+my_block[i].getname()
            seq_index = i
            break
        #else:
            #print 'Not Found : '+my_block[i].getname()
    print 'Not Found Any '
    return seq_index

