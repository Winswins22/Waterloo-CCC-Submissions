numQuarters = int (input())
firstSlot = int (input())
secondSlot = int (input())
thirdSlot = int (input())

timesPlayed = 0

#use loop to keep repeating the playing of the slot machine. when numQuarters = 0, break the loop and give number of times spinned

while True:
    
    #play first slot machine
    numQuarters -= 1
    firstSlot += 1
    timesPlayed += 1
    
    if firstSlot == 35:
        numQuarters += 30
        firstSlot = 0
        
    if numQuarters == 0:
        break
    
    #play second slot machine
    numQuarters -= 1
    secondSlot += 1
    timesPlayed += 1
    
    if secondSlot == 100:
        numQuarters += 60
        secondSlot = 0
        
    if numQuarters == 0:
        break
    
    #play third slot machine
    numQuarters -= 1
    thirdSlot += 1
    timesPlayed += 1
    
    if thirdSlot == 10:
        numQuarters += 9
        thirdSlot = 0
        
    if numQuarters == 0:
        break
    
print ("Martha plays ", timesPlayed, " times before going broke.", sep= "")