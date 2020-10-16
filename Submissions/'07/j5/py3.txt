locations = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]

minDist = int(input())
maxDist = int(input())

extras = int(input())
for _ in range(extras):
    locations.append(int(input()))
locations.sort()

graph = {}
shortcuts = {}
trvl = {}

for i in locations:
    graph[i] = []
    shortcuts[i] = 0
    trvl[i] = False

for i in range(len(locations)):
    for j in range (i, len(locations)):
        if minDist <= locations[j] - locations[i] <= maxDist:
            graph[locations[i]] = graph[locations[i]] + [locations[j]]

def DFS(node):
    
    if trvl[node] == True:
        return shortcuts[node]
    
    if node == 7000:
        return 1
        
    trvl[node] = True
    neighs = graph.get(node)
    
    totalPaths = 0
    
    if neighs != None:
        
        for i in neighs:
            paths = DFS(i)
            shortcuts[i] = paths
            totalPaths += paths
    
    return totalPaths
    
print (DFS(0))