rows = int(input())
cols = int(input())

choices = int(input())

# 2 states: Black, Gold
# boolean : False, True
# False : Black, True : Gold
currentColor = [False] * cols

# take in input and simulate painting
for i in range (choices):
    # input == R 1
    # rowOrCol = R
    # position = 1
    rowOrCol, position = input().split()
    position = int(position)

    if rowOrCol == "C":
        currentColor[position-1] = not currentColor[position-1]

    else:
        for j in range (cols):
            currentColor[j] = not currentColor[j]
    
goldTiles = 0

# count the amount of gold tiles
for i in range (cols):
    if currentColor[i] == True:
        goldTiles = goldTiles + 1

print (goldTiles)