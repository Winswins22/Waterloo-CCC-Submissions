# index 0 == clubs
# index 1 == diamonds
# index 2 == hearts
# index 3 == spades
allCards = [
[],
[],
[],
[]
]

def getPoints (cardList):
    points = 0
    
    if len(cardList) == 0:
        points = 3
    elif len(cardList) == 1:
        points = 2
    elif len(cardList) == 2:
        points = 1
    
    for i in cardList:
        if i == "A":
            points += 4
        elif i == "K":
            points += 3
        elif i == "Q":
            points += 2
        elif i == "J":
            points += 1
    
    return points

print ("Cards Dealt              Points")
cards = input()
cType = "C"

for i in cards:
    if i == "C":
        cType = "C"
    elif i == "D":
        cType = "D"
    elif i == "H":
        cType = "H"
    elif i == "S":
        cType = "S"
    else:
        if cType == "C":
            allCards[0].append(i)
        elif cType == "D":
            allCards[1].append(i)
        elif cType == "H":
            allCards[2].append(i)
        elif cType == "S":
            allCards[3].append(i)
totalPts = 0

for i in range (4):
    pts = getPoints(allCards[i])
    totalPts += pts
    
    if i == 0:
        print ("Clubs ", end= "")
    elif i == 1:
        print ("Diamonds ", end= "")
    elif i == 2:
        print ("Hearts ", end= "")
    elif i == 3:
        print ("Spades ", end= "")
    
    for j in allCards[i]:
        print (j, " ", end = "")
    print (pts)


print ("Total", totalPts)