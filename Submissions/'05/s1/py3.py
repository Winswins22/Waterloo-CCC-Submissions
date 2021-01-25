numTimes = int(input())

for i in range (numTimes):
    
    line = input()
    newLine = ""
    counter = 0
    
    #scan line to remove hyphens. save to seperate var until 12 chars 
    while len(newLine) != 10:
        if line[counter] != "-":
            newLine += line[counter]
        
        counter += 1
    
    #change letters to #s
    procLine = ""
    for i in range (10):
        
        currChar = newLine[i]
        
        #number
        try:
            currChar = int(currChar)
            procLine += str(currChar)
        except:
            if currChar in "ABC":
                procLine += "2"
            
            elif currChar in "DEF":
                procLine += "3"
            
            elif currChar in "GHI":
                procLine += "4"
            
            elif currChar in "JKL":
                procLine += "5"
            
            elif currChar in "MNO":
                procLine += "6"
            
            elif currChar in "PQRS":
                procLine += "7"
            
            elif currChar in "TUV":
                procLine += "8"
            
            elif currChar in "WXYZ":
                procLine += "9"
        

    
    #output 10 digits, along with hyphens when neccessary
    for i in range (10):
        #case for hyphens
        if i == 2 or i == 5:
            print (procLine[i], "-", end= "", sep= "")
        #case for last char
        elif i == 9:
            print (procLine[i])
        
        else:
            print (procLine[i], end= "")