import cv2
import numpy as np
cap=cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    r=200.0/frame.shape[0]
    dim=(200,int(frame.shape[0]*r))
    x,y,b=np.shape(frame)
    #cv2.imshow('img',frame)
    frame=cv2.pyrUp(frame)
    dst=cv2.resize(frame,dim,interpolation = cv2.INTER_AREA)
    cv2.imshow('img1',dst)
    k=cv2.waitKey(10)&0xff
    if k==27:
        break
cap.release()
cv2.destroyAllWindows()
