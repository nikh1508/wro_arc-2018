from Block_class import *

count = 10


try:
    #Wait calibrate camera and moving to cross section
    sendData(101,1)
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count :
            break
        print '0'
    print '1----------'
    #Scan the Arena to detect position of Blocks Placed in Arena
    ########################################################################
    #Scan for Block 1 -- stacking form
        
    print 'Scan for Block 1 -- stacking form'
    
    while arena_block[0]==-1:
        arena_block[0]=find_Block()
    ########################################################################
    #Scan for Block 2 -- short supply line near stack

    print 'Wait 90 degree ccw'
    sendData(3,1)                       #Wait 90 degree ccw
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'

    print 'Wait camera angle short supply 1 == 102'
    sendData(102,1)                     #Wait camera angle short supply 1 == 102
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'

    print 'Scan for Block 2 -- short supply line near stack'
    while arena_block[1]==-1:
        arena_block[1]=find_Block()
        
    ########################################################################3

    #Scan for Block 3 -- short supply line near start

    print 'Wait 45 degree ccw'
    sendData(5,1)                       #Wait 45 degree ccw
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'
    
    print 'Wait camera angle short supply 2 == 103'
    sendData(103,1)                     #Wait camera angle short supply 2 == 103
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'
    
    print 'Scan for Block 3 -- short supply line near start'
    while arena_block[2]==-1:
        arena_block[2]=find_Block()

    ##########################################################################

    #Scan for Block 4 -- inside void space 1
    
    print 'Wait 90 degree ccw'    
    sendData(3,1)                       #Wait 90 degree ccw
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'
    

    print 'Wait camera angle void area 1 == 104'
    sendData(104,1)                     #Wait camera angle void area 1 == 104
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'
        
    print'Scan for Block 4 -- inside void space 1'
    while arena_block[3]==-1:
        arena_block[3]=find_Block()
    ##########################################################################
    #Scan for Block 5 -- inside void space 2
        
    print 'Wait camera angle void area 2 == 105'
    sendData(105,1)                     #Wait camera angle void area 2 == 105
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'
        
    print 'Scan for Block 5 -- inside void space 2'
    while arena_block[4]==-1:
        for i in range (total_color):
            if i != arena_block[3]:
                if track(i) == 0:
                    arena_block[4] = i
                    break
        
    #########################################################################
    #Scan for Block 6 -- inside void space 3
    print 'Wait 45 degree ccw'
    sendData(5,1)#Wait 45 degree ccw
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------' 

    print 'Wait camera angle void area 3 == 106'
    sendData(104,1)                     #Wait camera angle void area 3 == 106
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'

    print 'Scan for Block 6 -- inside void space 3'
    while arena_block[5]==-1:
        for i in range (total_color):
            if i != arena_block[4]:
                if track(i) == 0:
                    arena_block[5] = i
                    break
    ########################################################################
    print 'Wait 90 degree cw'
    sendData(4,1)                       #Wait 90 degree cw to set initial 
    while True:
        s=0
        for i in range(count):
            s = s + GPIO.input(cnl)
            time.sleep(0.1)
            print s
        if s == count:
            break
        print '0'
    print '1----------'

    ################  Print All Detected Blocks  ########################
    print '-----------------------------------------'
    print 'Stacking Form : '+my_block[arena_block[0]].getname()
    print 'Sort Supply 1 : '+my_block[arena_block[1]].getname()
    print 'Sort Supply 2 : '+my_block[arena_block[2]].getname()
    print 'void area 1   : '+my_block[arena_block[3]].getname()
    print 'void area 2   : '+my_block[arena_block[4]].getname()
    print 'void area 3   : '+my_block[arena_block[5]].getname()
    print '-----------------------------------------'


    
    #Start of Sequence Detect and signal
    #88888888888888888888888888888888888888888888888888888888888888888888888888
    
    position = [7,10,14,19,24,29,29,29]
    while True:
        
        current_working_Block=current_working_Block+1
        if current_working_Block>12:
            break;
        print 'next Color :'
        print current_working_Block
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
        for i in range(5):
            if arena_block[i+1] == color:
                goto = i
                arena_block[i+1] = -1
                break
        print "Go TO : "
        sendData(position[goto],1)
        print position[goto]
        while True:
            s=0
            for i in range(count):
                s = s + GPIO.input(cnl)
                time.sleep(0.1)
                ####print s
            if s == count:
                break
        #********************************
        print 'Wait 90 degree cw'
        sendData(4,1)
        while True:
            s=0
            for i in range(count):
                s = s + GPIO.input(cnl)
                time.sleep(0.1)
                ###print s
            if s == count:
                break
        print '1'
        
        print 'Wait 90 degree cw'
        sendData(4,1)
        while True:
            s=0
            for i in range(count):
                s = s + GPIO.input(cnl)
                time.sleep(0.1)
                ####print s
            if s == count:
                break
        print '1'
        #********************************
        

except KeyboardInterrupt:
    cv2.destroyAllWindows()
    cap.release()
    GPIO.cleanup()
    print ('Camera & GPIO Closed')
cv2.destroyAllWindows()
cap.release()
GPIO.cleanup()
print ('Camera & GPIO Closed')

