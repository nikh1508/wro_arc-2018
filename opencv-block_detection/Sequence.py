from Block_class import Block
import numpy as np
import cv2



#------------------------------------------------------------------
# Defining Sequence------------------------------------------------
#1-Blue 2-Yello 3-DarkBlue 4-Red 5-Orange 6-Green  [3][8][8][2]
sequence=np.array([
            [
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 10,2 ],[ 10,2 ],[ 11,1 ],[ 11,1 ],[ 11,1 ],[ 11,1 ],[ 12,2 ],[ 12,2 ]],
                [ [ 10,2 ],[ 10,2 ],[ 8,6 ],[ 8,6 ],[ 9,4 ],[ 9,4 ],[ 12,2 ],[ 12,2 ] ],
                [ [ 1,1 ],[ 7,6 ],[ 7,6 ],[ 8,6 ],[ 8,6 ],[ 9,4 ],[ 9,4 ],[ 6,5 ] ],
                [ [ 1,1 ],[ 2,3 ],[ 7,6 ],[ 7,6 ],[ 5,5 ],[ 6,5 ],[ 6,5 ],[ 6,5 ] ],
                [ [ 1,1 ],[ 2,3 ],[ 3,4 ],[ 3,4 ],[ 5,5 ],[ 5,5 ],[ 5,5 ],[ 4,3 ] ],
                [ [ 1,1 ],[ 2,3 ],[ 2,3 ],[ 3,4 ],[ 3,4 ],[ 4,3 ],[ 4,3 ],[ 4,3 ] ]
            ],
            [
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 10,4 ],[ 10,4 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 11,6 ],[ 11,6 ] ],
                [ [ 5,5 ],[ 10,4 ],[ 10,4 ],[ 9,2 ],[ 9,2 ],[ 11,6 ],[ 11,6 ],[ 7,3 ] ],
                [ [ 5,5 ],[ 6,4 ],[ 6,4 ],[ 9,2 ],[ 9,2 ],[ 8,6 ],[ 8,6 ],[ 7,3 ] ],
                [ [ 5,5 ],[ 5,5 ],[ 6,4 ],[ 6,4 ],[ 8,6 ],[ 8,6 ],[ 7,3 ],[ 7,3 ] ],
                [ [ 1,2 ],[ 1,2 ],[ 2,5 ],[ 4,1 ],[ 4,1 ],[ 4,1 ],[ 4,1 ],[ 3,3 ] ],
                [ [ 1,2 ],[ 1,2 ],[ 2,5 ],[ 2,5 ],[ 2,5 ],[ 3,3 ],[ 3,3 ],[ 3,3 ] ]
            ],
            [
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 9,5 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 11,3 ],[ 10,2 ],[ 10,2 ] ],
                [ [ 9,5 ],[ 9,5 ],[ 9,5 ],[ 11,3 ],[ 11,3 ],[ 11,3 ],[ 10,2 ],[ 10,2 ] ],
                [ [ 5,4 ],[ 5,4 ],[ 8,1 ],[ 8,1 ],[ 8,1 ],[ 8,1 ],[ 6,6 ],[ 6,6 ] ],
                [ [ 1,3 ],[ 5,4 ],[ 5,4 ],[ 7,2 ],[ 7,2 ],[ 6,6 ],[ 6,6 ],[ 3,5 ] ],
                [ [ 1,3 ],[ 2,4 ],[ 2,4 ],[ 7,2 ],[ 7,2 ],[ 4,6 ],[ 4,6 ],[ 3,5 ] ],
                [ [ 1,3 ],[ 1,3 ],[ 2,4 ],[ 2,4 ],[ 4,6 ],[ 4,6 ],[ 3,5 ],[ 3,5 ] ]
            ],
            [
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 10,5 ],[ 10,5 ],[ 10,5 ],[ 12,2 ],[ 12,2 ],[ 11,5 ],[ 11,5 ],[ 11,5 ] ],
                [ [ 7,4 ],[ 7,4 ],[ 10,5 ],[ 12,2 ],[ 12,2 ],[ 11,5 ],[ 8,6 ],[ 8,6 ] ],
                [ [ 5,3 ],[ 7,4 ],[ 7,4 ],[ 9,2 ],[ 9,2 ],[ 8,6 ],[ 8,6 ],[ 6,3 ] ],
                [ [ 5,3 ],[ 5,3 ],[ 5,3 ],[ 9,2 ],[ 9,2 ],[ 6,3 ],[ 6,3 ],[ 6,3 ] ],
                [ [ 3,1 ],[ 3,1 ],[ 3,1 ],[ 3,1 ],[ 4,1 ],[ 4,1 ],[ 4,1 ],[ 4,1 ] ],
                [ [ 0,0 ],[ 1,6 ],[ 1,6 ],[ 0,0 ],[ 0,0 ],[ 2,4 ],[ 2,4 ],[ 0,0 ] ],
                [ [ 1,6 ],[ 1,6 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[0,0 ],[ 2,4 ],[ 2,4 ] ]
            ],
            [
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 9,5 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 12,1 ],[ 11,3 ],[ 10,2 ],[ 10,2 ] ],
                [ [ 9,5 ],[ 9,5 ],[ 9,5 ],[ 11,3 ],[ 11,3 ],[ 11,3 ],[ 10,2 ],[ 10,2 ] ],
                [ [ 5,4 ],[ 5,4 ],[ 8,1 ],[ 8,1 ],[ 8,1 ],[ 8,1 ],[ 6,6 ],[ 6,6 ] ],
                [ [ 1,5 ],[ 5,4 ],[ 5,4 ],[ 7,2 ],[ 7,2 ],[ 6,6 ],[ 6,6 ],[ 3,3 ] ],
                [ [ 1,5],[ 2,4 ],[ 2,4 ],[ 7,2 ],[ 7,2 ],[ 4,6 ],[ 4,6 ],[ 3,3 ] ],
                [ [ 1,5 ],[ 1,5 ],[ 2,4 ],[ 2,4 ],[ 4,6 ],[ 4,6 ],[ 3,3 ],[ 3,3 ] ]
            ],
            [
                [ [ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[ 0,0 ] ],
                [ [ 10,5 ],[ 10,5 ],[ 10,5 ],[ 12,2 ],[ 12,2 ],[ 11,5 ],[ 11,5 ],[ 11,5 ] ],
                [ [ 7,4 ],[ 7,4 ],[ 10,5 ],[ 12,2 ],[ 12,2 ],[ 11,5 ],[ 8,6 ],[ 8,6 ] ],
                [ [ 5,3 ],[ 7,4 ],[ 7,4 ],[ 9,2 ],[ 9,2 ],[ 8,6 ],[ 8,6 ],[ 6,3 ] ],
                [ [ 5,3 ],[ 5,3 ],[ 5,3 ],[ 9,2 ],[ 9,2 ],[ 6,3 ],[ 6,3 ],[ 6,3 ] ],
                [ [ 3,1 ],[ 3,1 ],[ 3,1 ],[ 3,1 ],[ 4,1 ],[ 4,1 ],[ 4,1 ],[ 4,1 ] ],
                [ [ 0,0 ],[ 2,6 ],[ 2,6 ],[ 0,0 ],[ 0,0 ],[ 1,4 ],[ 1,4 ],[ 0,0 ] ],
                [ [ 2,6 ],[ 2,6 ],[ 0,0 ],[ 0,0 ],[ 0,0 ],[0,0 ],[ 1,4 ],[ 1,4 ] ]
            ]
           ])


#------------------------------------------------------------------
#defining Blocks data----------------------------------------------
my_block=[]

b=Block()
b.setname("Blue")
b.setHSVmin(92,104,95)
b.setHSVmax(106,155,130)
b.setcolor(255,0,0)

y=Block()
y.setname("Yellow")
y.setHSVmin(25,190,115)
y.setHSVmax(39,242,158)
y.setcolor(0,255,255)

d=Block()
d.setname("DarkBlue")
d.setHSVmin(98,112,52)
d.setHSVmax(128,196,83)
d.setcolor(139,0,0)

r=Block()
r.setname("Red")
r.setHSVmin(0,169,90)
r.setHSVmax(9,225,125)
r.setcolor(0,0,255)

o=Block()
o.setname("Orange")
o.setHSVmin(7,183,121)
o.setHSVmax(18,230,140)
o.setcolor(0,165,255)

g=Block()
g.setname("Green")
g.setHSVmin(37,176,102)
g.setHSVmax(54,237,136)
g.setcolor(0,255,0)

my_block.append(b)
my_block.append(y)
my_block.append(d)
my_block.append(r)
my_block.append(o)
my_block.append(g)

#------------------------------------------------------------------
#Defining data variables opencv------------------------------------

def callback(x):
    pass
cap = cv2.VideoCapture(-1)

Found_Block=Block()

total_color = 6
total_seq = 6
total_Blocks = 12
def track(index):
    print 'Search '+my_block[index].getname()+'\n'
    ret, frame = cap.read()
    for i in range(5):
        ret,frame = cap.read()
        frame=frame[120:360,160:480]
        x,y,b=np.shape(frame)
        #cv2.imshow('img',frame)
        frame=cv2.pyrUp(frame)
        cv2.imshow('img1',frame)
        cv2.waitKey(1)
        
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    hsvmin=np.array(my_block[index].getHSVmin())
    hsvmax=np.array(my_block[index].getHSVmax())
    hsv=cv2.inRange(hsv, hsvmin, hsvmax)
    
    cv2.imshow('hsv',hsv)
    
    kernel = np.ones((5,5),np.uint8)
    hsv = cv2.erode(hsv,kernel,iterations = 1)
    erosion = cv2.erode(hsv,kernel,iterations = 1)
    hsv = cv2.dilate(hsv,kernel,iterations = 1)
    hsv = cv2.dilate(hsv,kernel,iterations = 1)
    
    im2, contours, hierarchy = cv2.findContours(hsv,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
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


#print sequence[0][7][7][1]
#while(True):
#    track(0)
#    k = cv2.waitKey(1) & 0xFF # large wait time to remove freezing
#    if k == 113 or k == 27:
#        break
#while(1):
#    track(1)
#    print '\nx : '
#    print Found_Block.getxPos()
#    print '  y : ' 
#    print Found_Block.getyPos()

seq_index = -1

for i in range(total_color):
    if(track(i) == 0):
        print 'Found     : '+my_block[i].getname()+'\n'
        seq_index = i
        break
    else:
        print 'Not Found : '+my_block[i].getname()+'\n'
if(seq_index!=-1):
    print '\n\nComputing for block Color : '+my_block[seq_index].getname()+'\n'
    found = 0;
    for i in range(1,total_Blocks):
        found = 0
        for j in range(8):
            if found == 1:
                break
            for k in range(8):
                if found == 1:
                    break
                if sequence[seq_index][j][k][0] == i+1 :
                    print i+1
                    print my_block[sequence[seq_index][j][k][1]-1].getname()
                    print '\n'
                    found = 1
                    while (track(sequence[seq_index][j][k][1]-1) == 1):
                        pass
                        

cv2.destroyAllWindows()
cap.release()

