#this code gives more pies first instead of giving less pies first.

from math import ceil

totalPies = int(input())
totalPeople = int(input())

#Format:
#(maxPiece, peopleLeft, piesLeft) : combinations
numPaths = {}

#maxGive : Maximum amount of pies to be given. Can only decrease.
#peopleLeft : how many people still need pies
#piesLeft : how many pies is still left

def DFS (maxPiece, peopleLeft, piesLeft):
    
    #DP Base Case
    if (maxPiece, peopleLeft, piesLeft) in numPaths.keys():
        return numPaths[(maxPiece, peopleLeft, piesLeft)]
    
    #Base Case
    if peopleLeft == 0 and piesLeft == 0:
        return 1
    
    #Recursion
    ways = 0
    maximumGive = min(piesLeft - peopleLeft + 1, maxPiece)
    minGive = ceil(piesLeft / peopleLeft)
    
    for i in range (maximumGive, minGive - 1, -1):
        ways += DFS(i, peopleLeft - 1, piesLeft - i)
    
    numPaths[(maxPiece, peopleLeft, piesLeft)] = ways
    return ways

print (DFS(totalPies - totalPeople + 1, totalPeople, totalPies))