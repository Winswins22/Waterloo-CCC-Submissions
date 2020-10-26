# position refers to the maximum x and y coordinates of the mouse
# inp refers to the input line
# xC == x coordinate; yC == y coordinate

position = list(map(lambda a : int(a), input().split(" ")))
inp = []
xC = 0
yC = 0


while inp != [0, 0]:
    inp = list(map(lambda a : int(a), input().split(" ")))
    
    xC += inp[0]
    yC += inp[1]
    
    if xC < 0:
        xC = 0
        
    if xC > position [0]:
        xC = position [0]
    
    if yC < 0:
        yC = 0
    
    if yC > position [1]:
        yC = position [1]
    
    if inp != [0, 0]:
        print (xC, yC)