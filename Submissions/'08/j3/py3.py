row0 = ["A", "B", "C", "D", "E", "F"]
row1 = ["G", "H", "I", "J", "K", "L"]
row2 = ["M", "N", "O", "P", "Q", "R"]
row3 = ["S", "T", "U", "V", "W", "X"]
row4 = ["Y", "Z", " ", "-", ".", "enter"]

cursorMoves = 0

X = 0
Y = 0

inputString = input ()

for i in range (len(inputString)):
    
    
    if inputString[i] in row0:
        cursorMoves += abs (X - 0)
        X = 0
        
        cursorMoves += abs (Y - (row0.index(inputString[i])))
        Y = row0.index(inputString[i])
        
        
    if inputString[i] in row1:
        cursorMoves += abs (X - 1)
        X = 1
        
        cursorMoves += abs (Y - (row1.index(inputString[i])))
        Y = row1.index(inputString[i])
        
        
    if inputString[i] in row2:
        cursorMoves += abs (X - 2)
        X = 2
        
        cursorMoves += abs (Y - (row2.index(inputString[i])))
        Y = row2.index(inputString[i])
        
    if inputString[i] in row3:
        cursorMoves += abs (X - 3)
        X = 3
        
        cursorMoves += abs (Y - (row3.index(inputString[i])))
        Y = row3.index(inputString[i])
        
    if inputString[i] in row4:
        cursorMoves += abs (X - 4)
        X = 4
        
        cursorMoves += abs (Y - (row4.index(inputString[i])))
        Y = row4.index(inputString[i])


cursorMoves += abs(4-X) + abs(4-Y)


print (cursorMoves + 1)