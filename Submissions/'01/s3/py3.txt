allConnections = []
dcRoads = 0
graph = {}

line = None

while line != "**":
    line = input()
    l1 = line[0]
    l2 = line[1]
    
    allConnections.append(line)
    
    if l1 in graph.keys():
        graph[l1] = graph[l1] + l2
    else:
        graph[l1] = l2
        
    if l2 in graph.keys():
        graph[l2] = graph[l2] + l1
    else:
        graph[l2] = l1

def DFS (start, end, restrict):
    
    DFSStack = [start]
    node = None
    trvl = {}
    trvl[start] = True
    
    for i in graph.keys():
        trvl[i] = False
    
    while len(DFSStack) != 0:
        node = DFSStack.pop(0)
        
        neigh = graph.get(node)
        
        if node == end:
            return 0
        
        if neigh != None and neigh != "*":
            for i in neigh:
                
                if trvl[i] == False and (node, i) != restrict and (i, node) != restrict:
                    trvl[i] = True
                    DFSStack.append(i)
    
    return 1

for i in allConnections:
    DFSResult = DFS("A", "B", (i[0], i[1]))
    
    if DFSResult == 1 and i != "**":
        print (i)
    dcRoads += DFSResult

print ("There are", dcRoads, "disconnecting roads.")