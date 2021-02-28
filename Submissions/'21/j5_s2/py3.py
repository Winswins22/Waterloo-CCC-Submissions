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
    position = position - 1

    if rowOrCol == "R":
        # paint row
        paintRow[position] = not paintRow[position]
    else:
        # paint col
        paintCol[position] = not paintCol[position]



goldTiles = 0

rows_with_black = 0
rows_with_gold = 0

# painting the rows
for i in range(rows):

    if paintRow[i] == True:
        rows_with_gold = rows_with_gold + 1
        goldTiles = goldTiles + cols
    else:
        rows_with_black = rows_with_black + 1

# paint over the cols
# new_gold_tiles = rows_with_black - rows_with_gold
new_gold_tiles = 0

for i in range (cols):
    if paintCol[i] == True:
        new_gold_tiles = rows_with_black - rows_with_gold
        goldTiles = goldTiles + new_gold_tiles

print (goldTiles)