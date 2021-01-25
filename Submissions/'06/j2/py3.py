firstDice = int (input())
secondDice = int (input ())
numWays = 0

for i in range (1, firstDice + 1):
    for x in range (1, secondDice + 1):
        
        if i + x == 10:
            numWays += 1
            break
        if i + x > 10:
            break

if numWays == 1:
    print ("There is 1 way to get the sum 10.")
else:
    print ("There are", numWays,  "ways to get the sum 10.")
