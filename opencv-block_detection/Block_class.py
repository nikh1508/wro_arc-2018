import cv2

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


    
