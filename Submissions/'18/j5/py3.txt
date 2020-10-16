graph = {}
shortPaths = {}
zeros = []

numPages = int(input())

for i in range (1, numPages + 1):
    line = list(map(int, input().split(" ")))
    
    if line [0] == 0:
        zeros.append(i)
        graph[i] = [0]
    else:
        line.pop(0)
        graph[i] = line
    
    shortPaths[i] = 99999

#Dijstrika's
#(Distance to node, Node)
priorityQueue = [(0, 1)]

while len(priorityQueue) != 0:
    
    priorityQueue.sort()
    Dist_Node_Pair = priorityQueue.pop(0)
    
    #check if the path is optimal
    if Dist_Node_Pair[0] <= shortPaths.get(Dist_Node_Pair[1]):
        #if optimal then:
        
        #change path info in shortPaths
        shortPaths[Dist_Node_Pair[1]] = Dist_Node_Pair[0]
        
        #find neighbours
        neighs = graph.get(Dist_Node_Pair[1])
        
        for node in graph.get(Dist_Node_Pair[1]): 
            #add the value to get to current node + 1
            travelCost = Dist_Node_Pair[0] + 1
            #check if this path is optimal. if yes, append to priority queue and change info in shortPaths
            #bandage : no path for 0
            if node != 0:
                if travelCost < shortPaths.get(node):
                    shortPaths[node] = travelCost
                    priorityQueue.append((travelCost, node))

if 99999 in shortPaths.values():
    print ("N")
else:
    print ("Y")
    
#find shortest path by looking up the nodes in shortPath
zerosDistance = []

for i in zeros:
    distance = shortPaths.get(i)
    zerosDistance.append(distance)

print (min(zerosDistance)+ 1)