rows = int(input())
cols = int(input())

choices = int(input())

# 2 states: Black, Gold
# boolean : False, True
# False : Black, True : Gold
currentColor = False

for i in range (choices):
    currentColor = not currentColor

if currentColor == False:
    # color == black
    print (0)
else:
    # color == gold
    print (1)