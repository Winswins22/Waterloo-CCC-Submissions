currentSquare = 1

#while True: loop
while True:
    
    #get the user dice roll
    userRoll = int (input())
    
    #if statement for no moves if user passes 100
    if userRoll + currentSquare <= 100:
        currentSquare += userRoll
    
    #use if statements to check if the user is at the ladder/snake tile
    #ladders
    if currentSquare == 9:
        currentSquare = 34
    
    if currentSquare == 40:
        currentSquare = 64

    if currentSquare == 67:
        currentSquare = 86
    
    #snakes
    if currentSquare == 54:
        currentSquare = 19
    
    if currentSquare == 90:
        currentSquare = 48
    
    if currentSquare == 99:
        currentSquare = 77
    
    #if 100 then put "You Win!"
    if currentSquare == 100:
        print ("You are now on square 100")
        print ("You Win!")
        break
    
    #if 0 then put "You Quit!"
    elif userRoll == 0:
        print ("You Quit!")
        break
    
    else:
        print ("You are now on square", currentSquare)