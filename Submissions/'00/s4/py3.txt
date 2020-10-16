inf = float("inf")

totalDist = int(input())
numClubs = int(input())
clubs = []
table = {}

for i in range (numClubs):
    clubs.append(int(input()))

clubs.sort()

#Fill in the table. Need to add going backwards
table[0] = 0

for i in range (1, totalDist+1):
    table[i] = inf
    
    for x in clubs:
        res = i - x
        
        if res >= 0:
            table[i] = min(table[res] + 1, table[i])
        else:
            break

if table[totalDist] != inf:
    print ("Roberta wins in", table[totalDist], "strokes.")
else:
    print ("Roberta acknowledges defeat.")