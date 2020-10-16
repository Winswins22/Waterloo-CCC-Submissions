nT = int(input())
numTimes = {}
numToName = {}

for i in range(nT):
    line = input().split(" ")
    
    numTimes[line[1]] = 0
    numToName[line[1]] = line[0]

nT = int(input())

for i in range(nT):
    num = input()
    numTimes[num] += 1

numFind = max(numTimes.values())
bigNums = []

for i in numTimes.items():
    if i[1] == numFind:
        bigNums.append(int(i[0]))

print (numToName[str(min(bigNums))])