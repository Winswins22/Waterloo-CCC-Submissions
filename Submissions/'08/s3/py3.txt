from collections import deque

def solve (start):
    global nY
    global nX
    
    que = deque()
    travelled = {}
    prev = {}
    
    for x in range (nX):
        for y in range (nY):
            travelled[(x, y)] = False
            prev[(x, y)] = None
    
    que.append(start)
    travelled[start] = True
    
    while len(que) != 0:
        node = que.popleft()
        neigh = graph.get(node)
        
        for i in neigh:
            if travelled[i] == False:
                travelled[i] = True
                prev[i] = node
                que.append(i)
    
    return prev
    
def rePath (start, end, prev):
    path = [end]
    node = prev[end]
    
    while node != None:
        path.append(node)
        node = prev[node]
    
    path.reverse()
     
    if path[0] == start:
        return path
    return -1
    
    
def BFS (start, end):
    prev = solve (start)
    return rePath (start, end, prev)
    
    

##############
nT = int(input())

moveUDO = (-1, 1)
moveLRO = (-1, 1)
moveUD = (-1, 1, 0, 0)
moveLR = (0, 0, -1, 1)

for _ in range (nT):
    
    graph = {}
    maze = []
    
    nY = int(input())
    nX = int(input())
    
    for i in range (nY):
        temp = list(map(str, input()))
        maze.append(temp)
    
    for y in range (nY):
        for x in range (nX):
            
            tempNodeStore = []
            
            if maze[y][x] == "+":
                
                for move in range (4):
                    tX = x + moveLR[move]
                    tY = y + moveUD[move]
                    
                    if 0 <= tX < nX and 0 <= tY < nY:
                        tempNodeStore.append((tX, tY))
                    
            elif maze[y][x] == "-":
                
                for move in range (2):
                    tX = x + moveLRO[move]
                    
                    if 0 <= tX < nX:
                        tempNodeStore.append((tX, y))
            
            elif maze[y][x] == "|":
                
                for move in range (2):
                    tY = y + moveUDO[move]
                    
                    if 0 <= tY < nY:
                        tempNodeStore.append((x, tY))
            
            graph[x, y] = tempNodeStore
    
    ans = BFS((0,0), (nX-1, nY-1))
    
    if ans == -1 or maze[nY-1][nX-1] == "*":
        print ("-1")
    else:
        print (len(ans))