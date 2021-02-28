rows = int(input())
cols = int(input())

choices = int(input())

# 2 states: Black, Gold
# boolean : False, True
# False : Black, True : Gold
currentColor = []

for i in range(rows):
    currentColor.append([False] * cols)

# Black, Gold, []
# Gold, Black

# take in input and simulate painting
for i in range (choices):
    # input == R 1
    # rowOrCol = R
    # position = 1
    rowOrCol, position = input().split()
    position = int(position)
    position = position - 1

    if rowOrCol == 'R':

        for j in range (cols):
            currentColor[position][j] = not currentColor[position][j]
    
    else:
        
        for j in range (rows):
            currentColor[j][position] = not currentColor[j][position]

goldTiles = 0

for row in range(rows):
    for col in range (cols):

        if currentColor[row][col] == True:
            goldTiles = goldTiles + 1

print (goldTiles)