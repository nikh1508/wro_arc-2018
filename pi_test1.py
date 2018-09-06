from Block_class import *

try:
    #Wait calibrate camera and moving to cross section
    while(GPIO.input(cnl)==0):
        time.sleep(.01)
        print '0'

    #Scan the Arena to detect position of Blocks Placed in Arena
    ########################################################################
    #Scan for Block 1 -- stacking form
        
    print 'Scan for Block 1 -- stacking form'
    
    while arena_block[0]==-1:
        arena_block[0]=find_Block()
    ########################################################################
    #Scan for Block 2 -- short supply line near stack

    print 'Wait 90 degree ccw'
    sendData(3,1)
    while(GPIO.input(cnl)==0):  #Wait 90 degree ccw
        time.sleep(.01)
        print '0'

    print 'Wait camera angle short supply 1 == 102'
    sendData(102,1)
    while(GPIO.input(cnl)==0):  #Wait camera angle short supply 1 == 102
        time.sleep(.01)
        print '0' 

    print 'Scan for Block 2 -- short supply line near stack'
    while arena_block[1]==-1:
        arena_block[1]=find_Block()
        
    ########################################################################3

    #Scan for Block 3 -- short supply line near start

    print 'Wait 45 degree ccw'
    sendData(4,1)
    while(GPIO.input(cnl)==0):  #Wait 45 degree ccw
        time.sleep(.01)
        print '0' 

    print 'Wait camera angle short supply 2 == 103'
    sendData(103,1)
    while(GPIO.input(cnl)==0):  #Wait camera angle short supply 2 == 103
        time.sleep(.01)
        print '0' 
    print 'Scan for Block 3 -- short supply line near start'
    while arena_block[2]==-1:
        arena_block[2]=find_Block()

    ##########################################################################

    #Scan for Block 4 -- inside void space 1
    
    print 'Wait 90 degree ccw'    
    sendData(3,1)
    while(GPIO.input(cnl)==0):  #Wait 90 degree ccw
        time.sleep(.01)
        print '0' 

    print 'Wait camera angle void area 1 == 104'
    sendData(104,1)
    while(GPIO.input(cnl)==0):  #Wait camera angle void area 1 == 104
        time.sleep(.01)
        print '0'
        
    print'Scan for Block 4 -- inside void space 1'
    while arena_block[3]==-1:
        arena_block[3]=find_Block()
    ##########################################################################
    #Scan for Block 5 -- inside void space 2
        
    print 'Wait camera angle void area 2 == 105'
    sendData(105,1)
    while(GPIO.input(cnl)==0):  #Wait camera angle void area 2 == 105
        time.sleep(.01)
        print '0'
        
    print 'Scan for Block 5 -- inside void space 2'
    while arena_block[4]==-1:
        x=find_Block()
        if(x == arena_block[3]):
            continue;
        arena_block[4]=x
        
    #########################################################################
    #Scan for Block 6 -- inside void space 3
    print 'Wait 45 degree ccw'
    sendData(4,1)
    while(GPIO.input(cnl)==0):  #Wait 45 degree ccw
        time.sleep(.01)
        print '0' 

    print 'Wait camera angle void area 3 == 106'
    sendData(104,1)
    while(GPIO.input(cnl)==0):  #Wait camera angle void area 3 == 106
        time.sleep(.01)
        print '0' 

    print 'Scan for Block 6 -- inside void space 3'
    while arena_block[5]==-1:
        arena_block[5]=find_Block()

    ################  Print All Detected Blocks  ########################
    print '-----------------------------------------'
    print 'Stacking Form : '+arena_block[0]
    print 'Sort Supply 1 : '+arena_block[1]
    print 'Sort Supply 2 : '+arena_block[2]
    print 'void area 1   : '+arena_block[3]
    print 'void area 2   : '+arena_block[4]
    print 'void area 3   : '+arena_block[5]
    print '-----------------------------------------'


    """
    #Start of Sequence Detect and signal

    """
    """
    while True:
        if checkPin()== 0:
            continue
        current_working_Block=current_working_Block+1
        if current_working_Block>12:
            break;
        print ("next Color :")
        print (current_working_Block)
        found = 0
        color = -1
        for i in range(8):
            if found == 1:
                break
            for j in range(8):
                if found == 1:
                    break
                if sequence[arena_block[0]][i][j][0] == current_working_Block :
                            color=sequence[arena_block[0]][i][j][1]-1
                            found = 1
        print (my_block[color].getname())
        goto = 6
        for i in range(6):
            if arena_block[i] == color:
                goto = i
                arena_block[i] = 0
                break
        print ("Go TO : ")
        print (goto)
        
    #-------------------------------------------------------------------------------------------

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
                        #while (track(sequence[seq_index][j][k][1]-1) == 1):
                        while True:
                             if track(sequence[seq_index][j][k][1]-1) == 0:
                                print Found_Block.getxPos()
                                if Found_Block.getxPos()>300:
                                    if Found_Block.getxPos()<500:
                                        print '**********************'
                                        break;
                                servo(Found_Block.getxPos())

    """
except KeyboardInterrupt:
    cv2.destroyAllWindows()
    cap.release()
    GPIO.cleanup()
    print ('Camera & GPIO Closed')
cv2.destroyAllWindows()
cap.release()
GPIO.cleanup()
print ('Camera & GPIO Closed')

