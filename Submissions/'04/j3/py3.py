numNoun = int (input())
numAdj = int (input())

listAdj = []
listNoun = []

for i in range (numNoun):
    listNoun.append(input ())
    
for i in range (numAdj):
    listAdj.append(input ())
    
for outputNouns in range (numNoun):
    for outputAdj in range (numAdj):
        print (listNoun[outputNouns], "as", listAdj[outputAdj])
