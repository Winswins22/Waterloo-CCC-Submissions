question = int(input())
numTimes = int(input())

dmoj = input().split(" ")
peg = input().split(" ")

summ = 0

#make both int
for i in range (len(dmoj)):
    temp = int(dmoj.pop(i))
    dmoj.insert(i, temp)

for i in range (len(peg)):
    temp = int(peg.pop(i))
    peg.insert(i, temp)

#sort both
dmoj.sort()
peg.sort()

#Question #1: minimum speed
if question == 1:
    
    while len(dmoj) > 0:
        #max and max
        dTemp = dmoj.pop(-1)
        pTemp = peg.pop(-1)
        
        summ += max(dTemp, pTemp)

#Question #2: maximum speed
if question == 2:
    
    while len(dmoj) > 0:
        #find min one list, max of other
        dTemp = dmoj.pop(0)
        pTemp = peg.pop(-1)
        
        summ += max(dTemp, pTemp)

print (summ)