graph = {}
nodePaths = {}
trvl = {}
totalPaths = 0

numNodes = int(input())

while True:
    n1, n2 = map(int, input().split(" "))
    
    if n1 == 0 and n2 == 0:
        break
    
    if n1 in graph.keys():
        graph[n1] = graph[n1] + [n2]
    else:
        graph[n1] = [n2]

    nodePaths[n1] = 0
    nodePaths[n2] = 0
    trvl[n2] = False
    trvl[n1] = False

def DFS (start):
    
    if trvl[start] == True and start != 1:
        return nodePaths[start]
    
    if start == numNodes:
        return 1
    
    trvl[start] = True
    neighs = graph.get(start)
    totalPaths = 0
    
    for i in neighs:
        paths = DFS(i)
        nodePaths[i] = paths
        totalPaths += paths
    
    return totalPaths

try:
    print (DFS(1))
except:
    print (0)