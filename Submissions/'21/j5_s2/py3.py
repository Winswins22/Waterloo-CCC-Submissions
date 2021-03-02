rows = int(input())
cols = int(input())

choices = int(input())

# boolean : False, True
# False == no paint, True = paint
paintRow = [False] * rows
paintCol = [False] * cols

for i in range (choices):
    rowOrCol, position = input().split()
    position = int(position)

    # Note:
    # We are subtracting 1 from position as a list counts up differently compared to a problem statement.
    # Problem: 1, 2, 3, 4
    # List: 0, 1, 2, 3
    # So, we subtract 1 from position to convert their counting system over to the list's counting system
    position = position - 1

    # Note:
    # If the artist paints over a certain row/col twice, it cancels out.
    # Use "not" to simulate the cancelling out

    if rowOrCol == "R":
        # paint row
        paintRow[position] = not paintRow[position]
    else:
        # paint col
        paintCol[position] = not paintCol[position]



goldTiles = 0

rows_with_black = 0
rows_with_gold = 0

# loop over the rows
# Add up the gold tiles gained from painting over a row, while tracking
# how many rows with black and rows with gold there are
for i in range(rows):

    if paintRow[i] == True:
        rows_with_gold = rows_with_gold + 1
        goldTiles = goldTiles + cols
    else:
        rows_with_black = rows_with_black + 1

# use this formula to calculate how many new gold tiles are created when the artist paints over a col:
# new_gold_tiles = rows_with_black - rows_with_gold
new_gold_tiles = 0

# loop over the cols while finding the amount of new gold tiles generated
for i in range (cols):
    if paintCol[i] == True:
        new_gold_tiles = rows_with_black - rows_with_gold
        goldTiles = goldTiles + new_gold_tiles

print (goldTiles)