listNums = []

numsInput = int (input())

for i in range (numsInput):
    
    bossNum = int (input())
    
    if bossNum == 0 and len(listNums) >= 1:
        listNums.pop()
        
    else:
        listNums.append(bossNum)
        
if len(listNums) == 0:
    print ("0")
else:
    sum = 0
    for i in range (len(listNums)):
        sum += listNums[i]
    print (sum)