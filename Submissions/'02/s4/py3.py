inf = float ("inf")

#Input
groupSize = int(input())
totalPeople = int(input())

people = []
time = []

for i in range (totalPeople):
    people.append(input())
    time.append(int(input()))

#Memoization

#F: pos : bestTime
goodTimes = {}

#F: pos : [bestPath]
paths = {}

#DFS Creation
#Not actually DFS, but they are similar because they both use recursion
def DFS (pos, currTime):
    
    #check if pos in time
    if pos in goodTimes.keys():
        return [currTime + goodTimes[pos], paths[pos]]
    
    #check if last person
    if pos == totalPeople - 1:
        return [currTime, [pos]]
    
    #Recursion
    bestPath = []
    bestTime = inf
    
    slowestPerson = -inf
    
    #With pos and groupSize, go thru next couple possibilities. Also make sure not to exceed the # people
    for newPos in range (pos + 1, pos + groupSize + 1):
        
        #Check against exceed # of people
        if newPos > totalPeople - 1:
            break
        
        slowestPerson = max(slowestPerson, time[newPos])
        newTime = currTime + slowestPerson
        
        #Will return in (time, path) format
        result = DFS(newPos, newTime)
        
        if result[0] - currTime < bestTime:
            bestTime = result[0] - currTime
            bestPath = result[1]
    
    
    
    #Add current node to the bestPath
    bestPath = [pos] + bestPath
    paths[pos] = bestPath
    goodTimes[pos] = bestTime
    
    bestTime += currTime
    return (bestTime, bestPath)

#Returned in (time, path) format
answers = DFS(-1, 0)

print ("Total Time:", answers[0])

#Rebuild the path
for index in range(len(answers[1]) - 1):
    firstPos = answers[1][index]
    secondPos = answers[1][index+1]
    
    for person in range (firstPos + 1, secondPos + 1):
        if person == secondPos:
            print(people[person])
        else:
            print(people[person], " ", sep= "", end= "")